#ifndef LST_LOGGER_H_
#define LST_LOGGER_H_

#include <cstdarg>
#include <string>


namespace logspot
{

class Logger
{
  public:
	static Logger log;

	void Info (const char *fmt, ...) const;
	void Error(const char *fmt, ...) const;
	void Info (const std::string fmt, ...) const;
	void Error(const std::string fmt, ...) const;

  private:
	void vinfo (const std::string& fmt, std::va_list args) const;
	void verror(const std::string& fmt, std::va_list args) const;
};

}


#endif // LST_LOGGER_H_
