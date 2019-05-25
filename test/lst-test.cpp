#include <logspot/Log.h>
#include <cstdlib>


int main()
{
	using namespace logspot;
	Log::info( "%s, %d, %f", "a", 2, 3.0f );
	Log::error( "%s, %d, %f", "b", 3, 4.0f );

	return EXIT_SUCCESS;
}
