#include <gtest/gtest.h>

#include "blocking_queue.h"
#include <boost/thread/thread.hpp>

TEST(blocking_queue, simple_try_pop)
{
    const int n = 1000;
    
    BlockingQueue<int> queue;
    ASSERT_TRUE(queue.empty());

    for (int i = 0; i < n; ++i) {
        int res;
        ASSERT_FALSE(queue.try_pop(res));
        queue.push(i);
        ASSERT_TRUE(queue.try_pop(res));
        ASSERT_EQ(i, res);
    }

    ASSERT_TRUE(queue.empty());

    queue.close();
    int res;
    ASSERT_FALSE(queue.pop(res));
    ASSERT_TRUE(queue.closed());
    ASSERT_TRUE(queue.empty());
}

TEST(blocking_queue, simple_pop)
{
    const int n = 1000;

    BlockingQueue<int> queue;
    ASSERT_TRUE(queue.empty());

    for (int i = 0; i < n; ++i) {
        int res;
        queue.push(i);
        ASSERT_TRUE(queue.pop(res));
        ASSERT_EQ(i, res);
    }

    ASSERT_TRUE(queue.empty());

    queue.close();
    int res;
    ASSERT_FALSE(queue.pop(res));
    ASSERT_TRUE(queue.closed());
    ASSERT_TRUE(queue.empty());
}

TEST(blocking_queue, push_and_close)
{
    BlockingQueue<int> queue;
    ASSERT_TRUE(queue.empty());
    ASSERT_FALSE(queue.closed());

    queue.push(239);
    queue.close();
    ASSERT_FALSE(queue.empty());
    ASSERT_TRUE(queue.closed());

    int res;
    ASSERT_TRUE(queue.pop(res));
    ASSERT_EQ(239, res);

    ASSERT_FALSE(queue.pop(res));
}

class QueuePopWorker {

    BlockingQueue<int>& queue;

public:

    std::vector<int> results;

    QueuePopWorker(BlockingQueue<int>& queue) : queue(queue) {}

    void start() {
        int result;
        while(queue.pop(result)) {
            results.push_back(result);
        }
        ASSERT_TRUE(queue.empty());
        ASSERT_TRUE(queue.closed());
    }

};

class QueuePushWorker {

    BlockingQueue<int>& queue;
    std::vector<int> data;
    bool should_close;

public:

    QueuePushWorker(BlockingQueue<int>& queue, std::vector<int> data, bool should_close) : queue(queue), data(data), should_close(should_close) {}

    void start() {
        int result;
        for (auto value : data) {
            if (queue.limit() != 0) {
                ASSERT_LE(queue.size(), queue.limit());
            }
            queue.push(value);
            if (queue.limit() != 0) {
                ASSERT_LE(queue.size(), queue.limit());
            }
        }
        if (should_close) {
            queue.close();
        }
    }

};

TEST(blocking_queue, single_producer_single_consumer)
{
    const int runs = 1000;
    const int n = 1000;
    const int limit = 100;
    for (int run = 0; run < runs; ++run) {
        BlockingQueue<int> queue(limit);
        ASSERT_TRUE(queue.empty());

        std::vector<int> data;
        for (int i = 0; i < n; ++i) {
            data.push_back(i);
        }

        QueuePushWorker producer(queue, data, true);
        QueuePopWorker consumer(queue);

        boost::thread consumer_thread(&QueuePopWorker::start, &consumer);
        boost::thread producer_thread(&QueuePushWorker::start, &producer);

        producer_thread.join();
        consumer_thread.join();

        ASSERT_TRUE(queue.empty());
        ASSERT_TRUE(queue.closed());

        ASSERT_EQ(consumer.results.size(), n);
        for (int i = 0; i < n; ++i) {
            ASSERT_EQ(consumer.results[i], i);
        }
    }
}

TEST(blocking_queue, multiple_producer_multilple_consumer)
{
    const int runs = 10;
    const int n = 10000;
    const int limit = 100;
    const int units = 10;
    for (int run = 0; run < runs; ++run) {
        BlockingQueue<int> queue(limit);
        ASSERT_TRUE(queue.empty());

        std::vector<QueuePushWorker> producers;
        std::vector<QueuePopWorker> consumers;
        for (int i = 0; i < units; ++i) {
            std::vector<int> data;
            for (int j = i * n; j < (i + 1) * n; ++j) {
                data.push_back(j);
            }
            producers.push_back(QueuePushWorker(queue, data, false));
            consumers.push_back(QueuePopWorker(queue));
        }

        std::vector<boost::thread> producers_threads(units);
        std::vector<boost::thread> consumers_threads(units);
        for (int i = 0; i < units; ++i) {
            producers_threads[i] = boost::thread(&QueuePushWorker::start, &producers[i]);
            consumers_threads[i] = boost::thread(&QueuePopWorker::start, &consumers[i]);
        }

        for (int i = 0; i < units; ++i) {
            producers_threads[i].join();
        }

        queue.close();

        for (int i = 0; i < units; ++i) {
            consumers_threads[i].join();
        }

        ASSERT_TRUE(queue.empty());
        ASSERT_TRUE(queue.closed());

        std::vector<bool> is_found(n * units, false);
        for (int i = 0; i < units; ++i) {
            for (int value : consumers[i].results) {
                ASSERT_FALSE(is_found[value]);
                ASSERT_GE(value, 0);
                ASSERT_LT(value, n * units);
                is_found[value] = true;
            }
        }

        for (int i = 0; i < n * units; ++i) {
            ASSERT_TRUE(is_found[i]);
        }
    }
}
