#include "zhelpers.hpp"
#include <string>
#include <thread>
#define randint(n1, n2) (int)(((float)n2-(float)n1)*random()/(RAND_MAX+1.0)+n1)
#define log(text)(std::cerr<<text<<std::endl)

class Client {
public:
	Client() {
		context=zmq::context_t(1);
		//std::thread tsend=std::thread(&Client::fsend, this);
		std::thread trcpt=std::thread(&Client::frcpt, this);
                //tsend.join();
                trcpt.join();
	}
private:
	zmq::context_t context;
	zmq::message_t getMessage(std::string s) {
		int length=s.length();
		zmq::message_t message(length);
		memcpy(message.data(), s.c_str(), length);
		return message;
	}
	std::string getString(zmq::message_t* m) {
		std::string r(static_cast<char*>(m->data()), (m->size()));
		return r;
	}

	void frcpt(){
		zmq::socket_t receiver(context, ZMQ_PULL);
		receiver.connect("tcp://127.0.0.1:5557");
		while(1){
			zmq::message_t message;
			receiver.recv(&message);
			std::string smessage=getString(&message);
			log("RECEIVED: "<<smessage);
			sleep(1);
		}
	}
	void fsend(){
		//  Socket to send messages to
	//	zmq::socket_t sender(context, ZMQ_PUSH);
	//	sender.connect("tcp://localhost:5558");
	//	while(1) {
	//		s_sleep(1);
	//		message.rebuild();
	//		sender.send(message);
	//		log("SENT:"<<smessage);
	//	}
	}
};

int main(int argc, char *argv[]) {
	Client c;
	return 0;
}
