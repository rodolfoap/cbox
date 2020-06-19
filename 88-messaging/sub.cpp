#include <zmq.hpp>
#include <string>
#include <thread>
#include <fmt/format.h>
#include "message.hpp"
#include "icarrier.hpp"

class Subscriber: public ICarrier{
public:
	Subscriber(char* remoteProviderURL){
		setRemoteProvider(remoteProviderURL);
		startReceiver();
		waitReceiver();
	}
	void messageReceived(std::string message) override {
		log("RECEIVED: "<<message);
	}
};

int main(int argc, char** argv) {
	if(argc<1) { log("Usage: "<<argv[0]<<" [CONNECTION_URL]"); exit(1); }
	Subscriber s(argv[1]);
	return 0;
}
