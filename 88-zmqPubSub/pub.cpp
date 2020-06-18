#include <zmq.hpp>
#include <string>
#include <thread>
#include <fmt/format.h>
#include "functions.hpp"
#include "message.hpp"

class Server {
public:
	Server(char* url){
		zmq::context_t context(1);
		// The Publisher
		zmq::socket_t sockSend(context, ZMQ_PUB);
		sockSend.bind(url);
		log("Publisher: "<<url);
		while(1){
			Message m("raisealert");
			m.addOptns("requireack", "true");
			m.addParam("priority", "0");
			m.addParam("text", fmt::format("Collapsing probability is: {}", frandom(0, 1)));
			lognoflush('.');
			sockSend.send(getMessage(m.getJson()));
			std::this_thread::sleep_for(std::chrono::milliseconds(600));
		}
	}
};

int main(int argc, char** argv) {
	if(argc<1) { log("Usage: "<<argv[0]<<" [CONNECTION_URL]"); exit(1); }
	Server s(argv[1]);
	return 0;
}
