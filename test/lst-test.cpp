#include <cstdlib>

#include "Logger.h"

namespace lsp = logspot;


int main()
{
	lsp::Logger::log.info("%s, %d, %f", "a", 2, 3.0f);
	lsp::Logger::log.error("%s, %d, %f", "b", 3, 4.0f);

	return EXIT_SUCCESS;
}
