#pragma once
#include "strings.h"
#include "ReaderTest.h"

static const int MIN = 0;
static const int MAX = 99999;

class Reader
{
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

