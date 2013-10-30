#ifndef _UTIL_H
#define _UTIL_H

#include <iostream>
#include <string>

#ifdef _RELEASE
#include <fstream>
#endif

extern void UtilInitialise();

extern void Print(std::string Message);

#endif