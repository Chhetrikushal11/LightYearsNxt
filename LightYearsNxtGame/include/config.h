#pragma once
#include <string>

std::string GetResourceDir()
{
#ifdef NDEBUG // release build
	return "assets/";
#else
	return "C:/Users/kbasnet/Desktop/C++/CompleteGameDevSeries/LightYearsNxt/LightYearsNxtGame/assets/";
#endif
}
