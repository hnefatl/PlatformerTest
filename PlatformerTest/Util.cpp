#include "Util.h"

#include <time.h>

void UtilInitialise()
{
#ifdef _RELEASE
	// Redirect
	std::fstream Out("Out.txt");
	std::cout.rdbuf(Out.rdbuf());
#endif
}

void Print(std::string Message)
{
	std::cout<<time(NULL)<<": "<<Message<<std::endl;
}