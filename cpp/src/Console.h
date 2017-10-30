#pragma once

class Console
{
public:
	static void Write(const char* data);
	static void WriteLine(const char* data);
	static void WriteLine(int data);
	static int ReadInt();
	static const char* ReadString();
};