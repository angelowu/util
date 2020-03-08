//
// Created by hujianzhe
//

#include "../../inc/sysapi/sprintf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef	__cplusplus
extern "C" {
#endif

char* strFormat(const char* format, ...) {
	char test_buf;
	char* buf;
	int len;
	va_list varg;
	va_start(varg, format);
	len = vsnprintf(&test_buf, 0, format, varg);
	va_end(varg);
	if (len < 0)
		return NULL;
	buf = (char*)malloc(len + 1);
	if (!buf)
		return NULL;
	va_start(varg, format);
	len = vsnprintf(buf, len + 1, format, varg);
	va_end(varg);
	if (len < 0) {
		free(buf);
		return NULL;
	}
	buf[len] = 0;
	return buf;
}

#ifdef	__cplusplus
}
#endif
