#include "Reader.h"

Reader::Reader()
{
}

Reader::~Reader()
{
}

std::string Reader::read(int value)
{
	if (value < MIN || value > MAX)
	{
		throw std::invalid_argument("Invalid argument. Value must be within range <0;99999>");
	}

	bool hasThousands = value >= 1000;
	bool hasHundreds = (value % 1000) >= 100;
	bool hasTens = (value % 100) != 0;
	bool overTweanty = (value % 100) >= 20;
	bool overTen = (value % 100) >= 10;

	std::string output = "";

	if (hasThousands)
	{
		output = readThousand(value);
	}
	
	if (hasHundreds)
	{
		if (hasThousands)
		{
			output += SPACE;
		}
		output += readHundred(value);
	}

	if (hasTens)
	{
		if (hasHundreds || hasThousands)
		{
			output += SPACE + AND + SPACE;
		}

		if (overTweanty)
		{
			output += readTen(value);
		}
		else
		{
			if (overTen)
			{
				output += readTeen(value);
			} 
			else
			{
				output += readDigit(value);
			}
		}
	}
	else
	{
		if (value == 0)
		{
			output = readDigit(0);
		}
	}
	
	return output;
}

std::string Reader::readDigit(int value)
{
	if (value < 0)
	{
		throw std::invalid_argument("Invalid argument");
	}
	return DIGITS[value % 10];
}

std::string Reader::readTeen(int value)
{
	int teen = value % 100;
	if (teen < 10 || teen > 19)
	{
		throw std::invalid_argument("Invalid argument");
	}
	return TEENS[teen - 10];
}

std::string Reader::readTen(int value)
{
	if (value < 0)
	{
		throw std::invalid_argument("Invalid argument");
	}
	bool hasDigit = (value % 10) != 0;
	if (hasDigit)
	{
		return TENS[(value % 100) / 10] + HYPHEN + readDigit(value);
	}
	else
	{
		return TENS[(value % 100) / 10];
	}
}

std::string Reader::readHundred(int value)
{
	return readDigit(value / 100) + SPACE + HUNDRED;
}

std::string Reader::readThousand(int value)
{
	if (value < 0)
	{
		throw std::invalid_argument("Invalid argument");
	}
	int thousands = value / 1000 % 100;
	std::string thousandsString;
	if (thousands >= 10)
	{
		if (thousands < 20)
		{
			thousandsString = readTeen(thousands);
		}
		else
		{
			thousandsString = readTen(thousands);
		}
	}
	else
	{
		thousandsString = readDigit(thousands);
	}
	return thousandsString + SPACE + THOUSAND;
}
