#include"Decorator.h"

void LoggerDecorator::log(string str)
{
	str = formatMessage(str);
	content->log(str);
}

LoggerDecorator::LoggerDecorator(unique_ptr<Logger>logger, FormatType formatType)
{
	content = move(logger);
	this->formatType = formatType;
}

string  LoggerDecorator::passEncryption(string toEncrypt)
{
	unsigned char key = 0b11011011;						// random bits to encrypt file
	string output = toEncrypt;

	for (uint16_t i = 0; i < toEncrypt.size(); i++)
	{
		output[i] = toEncrypt[i] ^ key;				// simple encryption
	}
	return output;
}

string LoggerDecorator::privEncryption(string toEncrypt)
{
	char key = 0b00100100;						// random bits to encrypt file
	string output = toEncrypt;

	for ( uint16_t i = 0; i < toEncrypt.size(); i++)
	{
		output[i] = toEncrypt[i] ^ key;				// simple encryption
	}
	return output;
}

string LoggerDecorator::formatMessage(string str)
{
	switch (formatType)
	{
	case FormatType::PLAIN:
		return str;
		break;
	case FormatType::ENCRYPTEDPASS:
		return passEncryption(str);
		break;
	case FormatType::ENCRYPTEDPRIV:
		return privEncryption(str);
		break;
	default:
		return "";
	}
}