#include "icarrier.hpp"

void ICarrier::setRemoteProvider(char* url){ remoteProviderURL=url; }
void ICarrier::setLocalServer(char* url){ localServerURL=url; }
void ICarrier::startReceiver(){ threadReceive=std::thread(&ICarrier::receiverLoop, this); }
void ICarrier::waitReceiver(){ threadReceive.join(); }
void ICarrier::disable(){ active=false; }
void ICarrier::receiverLoop() {
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
