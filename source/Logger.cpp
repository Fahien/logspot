#include <string>
#include "logspot/Logger.h"

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


void Logger::vinfo(const std::string&
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
		__android_log_vprint(ANDROID_LOG_VERBOSE, LOG_TAG, fmt.c_str(), args);
	#else // other systems
		vfprintf(stdout, (fmt + "\n").c_str(), args);
	#endif // ANDROID
#endif // LST_LOGGING
}


void Logger::Info(const char*
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


void Logger::Info(const std::string
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


void Logger::verror(const std::string&
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
		__android_log_vprint(ANDROID_LOG_ERROR, LOG_TAG, fmt.c_str(), args);
	#else // other systems
		vfprintf(stderr, (fmt + "\n").c_str(), args);
	#endif // ANDROID
#endif // LST_LOGGING
}


void Logger::Error(const char*
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


void Logger::Error(const std::string
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
