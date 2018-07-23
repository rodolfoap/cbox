#include<iostream>

namespace Http {
	class Request {
	public:	int x=13;
	};
	class ResponseWriter {
	};
}

void onRequest(const Http::Request& req, Http::ResponseWriter response) {
	std::cerr << req.x << std::endl;
}

int main() {
	Http::Request req;
	Http::ResponseWriter rwr;
	onRequest(req, rwr);
}
// Classes can be sent byRef in functions, so they can modified; to avoid modifications, mark function parameters with "const"
