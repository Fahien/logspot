#ifndef LST_LOG_H_
#define LST_LOG_H_

#include <cstdarg>
#include <string>


namespace logspot
{

class Log
{
  public:
	static void info (const char *fmt, ...);
	static void error(const char *fmt, ...);
	static void info (const std::string fmt, ...);
	static void error(const std::string fmt, ...);

  private:
	Log() = default ;

	static void vinfo (const std::string& fmt, std::va_list args);
	static void verror(const std::string& fmt, std::va_list args);
};

}


#endif // LST_LOG_H_
