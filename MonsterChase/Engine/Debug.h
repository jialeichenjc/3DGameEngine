#include <stdio.h>
#ifndef __DEBUG_H
#define __DEBUG_H
#define EMIT_LOCATION() printf("Line: %d in File: %s", __FILE__, __LINE__);

#define DEBUG_PRINT(fmt,...) printf(fmt, __VA_ARGS__)

#if defined(_MSC_VER)
#define BREAK_IN_DEBUGGER() __debugbreak()

#elif defined(__GNUC__)
#define BREAK_IN_DEBUGGER() __builtin_trap()
#else
#error "Provide an implementation of BREAK_IN_DEBUGGER"
#endif

#if defined(_DEBUG)
#define assert(cond, error_str)	if(cond == false) {\
						DEBUG_PRINT("%s occurred at File %s Line %d", error_str, __FILE__, __LINE__);\
						BREAK_IN_DEBUGGER();}
#endif
#endif

