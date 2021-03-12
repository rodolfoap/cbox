#pragma once
#include <iostream>
#include <cstring>
#include <secbroker.hpp>

extern "C" {
	secbroker *create(int32_t width, const char *name);
	void display(secbroker *holder, const char *message);
	void modify(secbroker *holder, const char *name, uint32_t x);
	void destroy(secbroker **holder);
}
