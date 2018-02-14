#include "stdafx.h"
#include "Reader.h"

Reader::Reader()
{
}

Reader::~Reader()
{
}

bool Reader::read(int value)
{
	if (value < MIN || value > MAX)
	{
		std::cout << "Provided value is outside range <0; 99999>" << std::endl;
		return false;
	}

	bool hasThousands = value >= 1000;
	bool hasHundreds = (value % 1000) >= 100;
	bool hasTens = (value % 100) != 0;
	bool overTweanty = (value % 100) >= 20;
	bool overTen = (value % 100) >= 10;

	std::string output = "";

	if (hasThousands)
	{
		output = readThousand(value) + SPACE;
	}
	
	if (hasHundreds)
	{
		output += readHundred(value) + SPACE;
	}

	if (hasTens)
	{
		if (hasHundreds || hasThousands)
		{
			output += AND + SPACE;
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
	
	std::cout << output << std::endl;
	return true;
}

std::string Reader::readDigit(int value)
{
	return DIGITS[value % 10];
}

std::string Reader::readTeen(int value)
{
	int teen = value % 100;
	if (teen < 10 || teen > 20)
	{
		throw std::invalid_argument("Invalid argument");
	}
	return TEENS[teen - 10];
}

std::string Reader::readTen(int value)
{
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
