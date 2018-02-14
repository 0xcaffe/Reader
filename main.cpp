#include <iostream>
#include <limits>
#include "Reader.h"
#include "ReaderTest.h"

int parseInt()
{
	int value;
	while (!(std::cin >> value)) 
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Error. Type in an integer." << std::endl;
		return -1;
	}
	return value;
}

int main()
{
	ReaderTest readerTest;
	readerTest.runAll();

	Reader reader;
	int value;
	
	for (;;)
	{
		value = parseInt();	
		if (value < 0) 
		{
			break;
		}

		std::cout << reader.read(value) << std::endl;
	}

	return 0;
}

