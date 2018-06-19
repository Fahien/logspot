#include <cstdlib>
#include <logspot/Logger.h>

namespace lst = logspot;


int main()
{
	lst::Logger::log.Info("%s, %d, %f", "a", 2, 3.0f);
	lst::Logger::log.Error("%s, %d, %f", "b", 3, 4.0f);

	return EXIT_SUCCESS;
}
