// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <limits>
#include "Reader.h"


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
	Reader reader;
	int value;
	
	do
	{
		value = parseInt();	
		if (value < 0)
			break;
	} while (reader.read(value));

	return 0;
}

