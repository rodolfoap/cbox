#include <zmq.hpp>
#include <string>
#include <thread>
#include <fmt/format.h>
#include "functions.hpp"
#include "message.hpp"

class Server {
public:
	Server() {
		std::thread tpub=std::thread(&Server::fpub, this);
                tpub.join();
	}
private:
	void fpub(){
		zmq::context_t context(1);
		// The Publisher
		zmq::socket_t sockSend(context, ZMQ_PUB);
		sockSend.bind("tcp://*:5557");
		log("Ventilator: tcp://*:5557");
		while(1){
			Message m("raisealert");
			m.addOptns("requireack", "true");
			m.addParam("priority", "0");
			m.addParam("text", fmt::format("Collapsing probability is: {}", frandom(0, 1)));
			sockSend.send(getMessage(m.getJson()));
			std::this_thread::sleep_for(std::chrono::milliseconds(600));
		}
	}
};

int main(int argc, char *argv[]) {
	Server s;
	return 0;
}
