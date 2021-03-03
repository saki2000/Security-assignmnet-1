#pragma once
#include <fstream>
#include <iostream>

using namespace std;

class Logger
{
public:
	virtual void log(string str) = 0;
	virtual ~Logger() = default;
};

class PasswordLogger : public Logger
{
public:
	void log(string str)override;
};

class PrivligeLogger : public Logger
{
public:
	void log(string str)override;
};

class DataLogger : public Logger
{
public:
	void log(string str)override;
};