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
private:
	char* remoteProviderURL;
	char* localServerURL;
	std::thread threadReceive;
	bool active=true;
	void receiverLoop();
	virtual void messageReceived(std::string message){ log("messageReceived() must be overridden."); }
};

#endif
