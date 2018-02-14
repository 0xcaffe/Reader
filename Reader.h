#pragma once
#include <string>
#include "ReaderTest.h"

class Reader
{
	const int MIN = 0;
	const int MAX = 99999;

	const std::string DIGITS[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	const std::string TEENS[10] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	const std::string TENS[10] = { "zero", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	const std::string HUNDRED = "hundred";
	const std::string THOUSAND = "thousand";
	const std::string AND = "and";
	const std::string HYPHEN = "-";
	const std::string SPACE = " ";
	
	std::string readDigit(int value);
	std::string readTeen(int value);
	std::string readTen(int value);
	std::string readHundred(int value);
	std::string readThousand(int value);

	friend class ReaderTest;

public:

	Reader();
	~Reader();
	std::string read(int value);
};

