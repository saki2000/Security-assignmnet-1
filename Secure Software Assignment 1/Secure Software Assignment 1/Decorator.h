#pragma once
#include "Logger.h"
#include <memory>

enum class FormatType
{
	PLAIN,
	ENCRYPTEDPASS,
	ENCRYPTEDPRIV
};

class LoggerDecorator : public Logger
{
private:
	unique_ptr<Logger>content;
	FormatType formatType;
	void log(string str);
	string  passEncryption(string toEncrypt);
	string privEncryption(string toEncrypt);

public:
	LoggerDecorator(unique_ptr<Logger>content, FormatType formatType);
	virtual string formatMessage(string str);

	LoggerDecorator(const LoggerDecorator&) = delete;						//comapiler flag
	LoggerDecorator& operator=(const LoggerDecorator&) = delete;			// preventing compiler flag error
};