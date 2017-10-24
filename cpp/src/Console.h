#pragma once
#ifdef Windows
#include <iostream>
#endif

class Console
{
public:
#ifdef Windows
	static void Log(const char* data) {
		std::cout << data << std::endl;
	}
	static void Get() {
		std::cin.get();
	}
#else
	static void Log(const char* data) { }
	static void Get() { }
#endif
};