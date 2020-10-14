#include "FreeRTOS.h"

void *memcpy(void *dst, const void *src, size_t n)
{
	/* copy per 1 byte */
	const char *p = src;
	char *q = dst;

	while (n--) {
		*q++ = *p++;
	}

	return dst;
}

void memset(void *dst, char ch, size_t size)
{
	char *buf;
	size_t i;

	buf = (char *)dst;
	for (i = 0; i < size; ++i)
		buf[i] = ch;
}
