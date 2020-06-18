#include <zmq.hpp>
#include <string>
#include <thread>
#include <fmt/format.h>
#include "functions.hpp"
#include "message.hpp"
#include "icarrier.hpp"

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
