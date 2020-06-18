#include <zmq.hpp>
#include <string>
#include <thread>
#include <fmt/format.h>
#include "functions.hpp"
#include "message.hpp"

class ICarrier {
public:
	ICarrier(){}
	void startListener(ICarrier& carrier){
		// See https://stackoverflow.com/a/45823556/9911256
		std::thread tsub=std::thread(&ICarrier::fsub, this, std::ref(carrier));
		tsub.join();
	}
	void setUrl(char* _url){
		url=_url;
	}
private:
	char* url;
	void fsub(ICarrier& carrier) {
		zmq::context_t context(1);
		// The Subscriber
		zmq::socket_t sockRcpt(context, ZMQ_SUB);
		sockRcpt.setsockopt(ZMQ_SUBSCRIBE, "", 0);
		sockRcpt.connect(url);
		log("Subscriber: "<<url);
		while(1){
			zmq::message_t message;
			sockRcpt.recv(&message);
			std::string smessage=getString(&message);
			// carrier.msgArrived(smessage);
			msgArrived(smessage);
		}
	}
	virtual void msgArrived(std::string message){
		log("RECEIVED: "<<message);
	}
};

class Client: public ICarrier{
public:
	Client(char* url){
		setUrl(url);
		startListener(*this);
	}
	void msgArrived(std::string message){
		log("Arrived: "<<message);
	}
};

int main(int argc, char** argv) {
	if(argc<1) { log("Usage: "<<argv[0]<<" [CONNECTION_URL]"); exit(1); }
	Client s(argv[1]);
	return 0;
}
