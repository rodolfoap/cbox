#ifndef ICARRIER_H
#define ICARRIER_H

#include <zmq.hpp>
#include <string>
#include <thread>
#include "functions.hpp"
#include "message.hpp"

class ICarrier {
public:
	ICarrier(){}
	void setRemoteProvider(char* url);
	void setLocalServer(char* url);
	void startReceiver();
	void waitReceiver();
	void disable();
	void publish(zmq::message_t message);
private:
	zmq::context_t* pubContext;
	zmq::context_t* subContext;
	zmq::socket_t* pubSocket;
	zmq::socket_t* subSocket;
	std::thread threadReceive;
	bool active=true;
	void receiverLoop();
	virtual void messageReceived(std::string message){ log("messageReceived() must be overridden."); }
};

#endif
