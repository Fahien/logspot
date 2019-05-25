#include "logspot/Log.h"
#include <string>

#ifdef LST_LOGGING
#ifdef ANDROID
#include <android/log.h>
#define LOG_TAG ( "Logspot" )
#else  // other systems
#include <iostream>
#endif  // ANDROID
#endif

namespace logspot
{
void Log::vinfo( const std::string&
#ifdef LST_LOGGING
                     fmt
#endif
                 ,
                 std::va_list
#ifdef LST_LOGGING
                     args
#endif
)
{
#ifdef LST_LOGGING
#ifdef ANDROID
	__android_log_vprint( ANDROID_LOG_VERBOSE, LOG_TAG, fmt.c_str(), args );
#else   // other systems
	vfprintf( stdout, ( fmt + "\n" ).c_str(), args );
#endif  // ANDROID
#endif  // LST_LOGGING
}


void Log::info( const char*
#ifdef LST_LOGGING
                    fmt
#endif
                ,
                ... )
{
#ifdef LST_LOGGING
	std::va_list args;
	va_start( args, fmt );
	vinfo( fmt, args );
	va_end( args );
#endif  // LST_LOGGING
}


void Log::info( const std::string
#ifdef LST_LOGGING
                    fmt
#endif
                ,
                ... )
{
#ifdef LST_LOGGING
	std::va_list args;
	va_start( args, fmt );
	vinfo( fmt, args );
	va_end( args );
#endif  // LST_LOGGING
}


void Log::verror( const std::string&
#ifdef LST_LOGGING
                      fmt
#endif
                  ,
                  std::va_list
#ifdef LST_LOGGING
                      args
#endif
)
{
#ifdef LST_LOGGING
#ifdef ANDROID
	__android_log_vprint( ANDROID_LOG_ERROR, LOG_TAG, fmt.c_str(), args );
#else   // other systems
	vfprintf( stderr, ( fmt + "\n" ).c_str(), args );
#endif  // ANDROID
#endif  // LST_LOGGING
}


void Log::error( const char*
#ifdef LST_LOGGING
                     fmt
#endif
                 ,
                 ... )
{
#ifdef LST_LOGGING
	std::va_list args;
	va_start( args, fmt );
	verror( fmt, args );
	va_end( args );
#endif  // LST_LOGGING
}


void Log::error( const std::string
#ifdef LST_LOGGING
                     fmt
#endif
                 ,
                 ... )
{
#ifdef LST_LOGGING
	std::va_list args;
	va_start( args, fmt );
	verror( fmt, args );
	va_end( args );
#endif  // LST_LOGGING
}

}  // namespace logspot