#include "Console.h"
#ifdef Windows
#include <string>
#include <iostream>
#include <sstream>
#else
#include <Arduino.h>
extern HardwareSerial Serial;
#endif

#ifdef Windows
void Console::Write(const char* data)
{
	std::cout << data;
}

void Console::WriteLine(const char* data)
{
	std::cout << data << std::endl;
}

void Console::WriteLine(int data)
{
	std::cout << data << std::endl;
}

int Console::ReadInt()
{
	auto str = ReadString();
	auto number = std::strtol(str, nullptr, 10);
	return number;
}

const char* Console::ReadString()
{
	std::string tempData;
	//char* data;
	std::getline(std::cin, tempData);
	std::string* data = new std::string(tempData);
	auto cppString = data->c_str();
	return cppString;
}
#else
void Console::Write(const char* data)
{
	Serial.print(data);
}

void Console::WriteLine(const char* data)
{
	Serial.println(data);
}

void Console::WriteLine(int data)
{
	Serial.println(data);
}

int Console::ReadInt()
{
	return Serial.read();
}
#endif