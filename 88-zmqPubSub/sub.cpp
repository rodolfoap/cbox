#include <zmq.hpp>
#include <string>
#include <thread>
#include <fmt/format.h>
#include "functions.hpp"
#include "message.hpp"

class ICarrier {
public:
	ICarrier(){}
	void setRemoteProvider(char* url){ remoteProviderURL=url; }
	void startReceiver(){ threadReceive=std::thread(&ICarrier::receiverLoop, this); }
	void  waitReceiver(){ threadReceive.join(); }
	void       disable(){ active=false; }
private:
	char* remoteProviderURL;
	std::thread threadReceive;
	bool active=true;
	void receiverLoop() {
		zmq::context_t context(1);
		zmq::socket_t subSocket(context, ZMQ_SUB);
		subSocket.setsockopt(ZMQ_SUBSCRIBE, "", 0);
		subSocket.connect(remoteProviderURL);
		log("RemoteProviderURL: "<<remoteProviderURL);
		while(active){
			zmq::message_t message;
			subSocket.recv(&message);
			messageReceived(getString(&message));
		}
	}
	virtual void messageReceived(std::string message){
		log("messageReceived() must be overridden.");
	}
};

class Client: public ICarrier{
public:
	Client(char* remoteProviderURL){
		setRemoteProvider(remoteProviderURL);
		startReceiver();
		waitReceiver();
	}
	void messageReceived(std::string message){
		log("RECEIVED: "<<message);
	}
};

int main(int argc, char** argv) {
	if(argc<1) { log("Usage: "<<argv[0]<<" [CONNECTION_URL]"); exit(1); }
	Client s(argv[1]);
	return 0;
}
