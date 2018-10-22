#include <iostream>
#include <string>

class Worker;

class IListener {
public:
	virtual void update(Worker&) = 0;
	virtual ~IListener() {};
};

class Worker {
protected:
	std::string name;
public:
	IListener* listener;
	void notifyListener(){
		listener->update(*this);
	}
	void set_name(std::string s){
		name = s;
		notifyListener();
	}
	std::string get_name(){
		return name;
	}
};

class MyListener :public IListener {
public:
	// @Override
	void update(Worker &worker) {
		std::cout << "[UPDATE] name:" << worker.get_name() << std::endl;
	}

	MyListener(){
		Worker worker;
		worker.listener=this;
		worker.set_name("Pipo");
		worker.set_name("Yuya");
	}
};

int main() {
	new MyListener();
}
