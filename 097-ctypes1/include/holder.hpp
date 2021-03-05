#pragma once
#include <cstdint>

extern "C" {
	typedef struct {
		void *handle;
		int32_t width;
		char name[32];
	} HOLDER;

	HOLDER *create(int32_t width, const char *fname);
	void modify(HOLDER *holder, const char *fname, uint32_t x);
	void destroy(HOLDER **holder);
}
