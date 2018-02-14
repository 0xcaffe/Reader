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
	int value = parseInt();	
	try 
	{
		std::cout << reader.read(value) << std::endl;
	}
	catch (const std::invalid_argument& exception)
	{
		std::cout << exception.what() << std::endl;
	}	
	return 0;
}

