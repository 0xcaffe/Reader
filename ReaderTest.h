#pragma once
#include <iostream>
#include "Reader.h"

class ReaderTest
{
	int assert(std::string string1, std::string string2);

public:

	ReaderTest();
	~ReaderTest();

	void testReadDigit(void);
	void testReadTeen(void);
	void testReadTen(void);
	void testReadHundred(void);
	void testReadThousand(void);
	void testRead(void);

	void runAll(void);
};

