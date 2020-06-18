#include "icarrier.hpp"

void ICarrier::setRemoteProvider(char* url){
	remoteProviderURL=url;
	subContext=new zmq::context_t(1);
	subSocket =new zmq::socket_t(*subContext, ZMQ_SUB);
	subSocket->setsockopt(ZMQ_SUBSCRIBE, "", 0);
	subSocket->connect(remoteProviderURL);
}
void ICarrier::setLocalServer(char* url){
	localServerURL=url;
	pubContext=new zmq::context_t(1);
	pubSocket =new zmq::socket_t(*pubContext, ZMQ_PUB);
	pubSocket->bind(url);
}
void ICarrier::publish(zmq::message_t message){
	pubSocket->send(message);
}
void ICarrier::startReceiver(){
	threadReceive=std::thread(&ICarrier::receiverLoop, this);
}
void ICarrier::waitReceiver(){ threadReceive.join(); }
void ICarrier::disable(){ active=false; }
void ICarrier::receiverLoop() {
	log("RemoteProviderURL: "<<remoteProviderURL);
	while(active){
		zmq::message_t message;
		subSocket->recv(&message);
		messageReceived(getString(&message));
	}
}
