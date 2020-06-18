#include <zmq.hpp>
#include <string>
#include <thread>
#include <fmt/format.h>
#include "functions.hpp"
#include "message.hpp"
#include "icarrier.hpp"

class Publisher: public ICarrier{
public:
	Publisher(char* localServerURL){
		setLocalServer(localServerURL);
		while(1){
			Message m("raisealert");
			m.addOptns("requireack", "true");
			m.addParam("priority", "0");
			m.addParam("text", fmt::format("Probability: {}", frandom(0, 1)));
			lognoflush('.');
			publish(getMessage(m.getJson()));
			std::this_thread::sleep_for(std::chrono::milliseconds(600));
		}
	}
};

int main(int argc, char** argv) {
	if(argc<1) { log("Usage: "<<argv[0]<<" [CONNECTION_URL]"); exit(1); }
	Publisher s(argv[1]);
	return 0;
}
