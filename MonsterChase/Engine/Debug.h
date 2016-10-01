#ifndef __DEBUG_H
#define __DEBUG_H

#if defined(_MSC_VER)
#define BREAK_IN_DEBUGGER() __debugbreak()
#elif defined(__GNUC__)
#define BREAK_IN_DEBUGGER() __builtin_trap()
#else
#error "Provide an implementation of BREAK_IN_DEBUGGER"
#endif

#define EMIT_LOCATION() printf("Line: %d in File: %s", __FILE__, __LINE__);

#define LOG()  printf("Error occurred at ");

#if defined(BUILD_DEBUG)
#define assert(cond)	if((cond) == false) \
						BREAK_IN_DEBUGGER();\
						LOG();\
						EMIT_LOCATION();
						
#else
#define assert(cond) void(0)
#endif
#endif

