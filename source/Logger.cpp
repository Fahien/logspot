#include "Logger.h"

#ifdef LST_LOGGING
	#ifdef ANDROID
		#include <android/log.h>
		#define LOG_TAG ("LogSpoT")
	#else // other systems
		#include <iostream>
	#endif // ANDROID
#endif

using namespace logspot;


Logger Logger::log{};


void Logger::vinfo(const char*
	#ifdef LST_LOGGING
		fmt
	#endif
	, std::va_list
	#ifdef LST_LOGGING
		args
	#endif
) const
{
#ifdef LST_LOGGING
	#ifdef ANDROID
		__android_log_vprint(ANDROID_LOG_VERBOSE, LOG_TAG, fmt, args);
	#else // other systems
		vfprintf(stdout, fmt, args);
	#endif // ANDROID
#endif // LST_LOGGING
}


void Logger::info(const char*
	#ifdef LST_LOGGING
		fmt
	#endif
	, ...) const
{
#ifdef LST_LOGGING
	std::va_list args;
	va_start(args, fmt);
	vinfo(fmt, args);
	va_end(args);
#endif // LST_LOGGING
}


void Logger::verror(const char*
	#ifdef LST_LOGGING
		fmt
	#endif
	, std::va_list
	#ifdef LST_LOGGING
		args
	#endif
) const
{
#ifdef LST_LOGGING
	#ifdef ANDROID
		__android_log_vprint(ANDROID_LOG_ERROR, LOG_TAG, fmt, args);
	#else // other systems
		vfprintf(stderr, fmt, args);
	#endif // ANDROID
#endif // LST_LOGGING
}


void Logger::error(const char*
	#ifdef LST_LOGGING
		fmt
	#endif
	, ...) const
{
#ifdef LST_LOGGING
	std::va_list args;
	va_start(args, fmt);
	verror(fmt, args);
	va_end(args);
#endif // LST_LOGGING
}
