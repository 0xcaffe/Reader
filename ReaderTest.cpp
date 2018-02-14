#include "ReaderTest.h"

ReaderTest::ReaderTest()
{
}

ReaderTest::~ReaderTest()
{
}

int ReaderTest::assert(std::string string1, std::string string2)
{
	return (string1 == string2) ? 1 : 0;
}

void ReaderTest::testReadDigit(void)
{
	int passed = 0;
	Reader reader;
	passed += assert("zero", reader.readDigit(0));
	passed += assert("five", reader.readDigit(5));
	passed += assert("nine", reader.readDigit(9));
	passed += assert("seven", reader.readDigit(17));
	passed += assert("two", reader.readDigit(2352));
	try 
	{
		reader.readDigit(-15);
	}
	catch (const std::invalid_argument& exception)
	{
		passed++;
	}

	if (passed == 6)
	{
		std::cout << "TEST ReaderTest::testReadDigit PASSED " << std::endl;
	} 
	else 
	{
		std::cout << "TEST ReaderTest::testReadDigit FAILED " << std::endl;
	}	
}

void ReaderTest::testReadTeen(void)
{
	int passed = 0;
	Reader reader;
	passed += assert("ten", reader.readTeen(10));
	passed += assert("nineteen", reader.readTeen(19));
	passed += assert("fourteen", reader.readTeen(14));

	try 
	{
		reader.readTeen(20);
	}
	catch (const std::invalid_argument& exception)
	{
		passed++;
	}

	try 
	{
		reader.readTeen(9);
	}
	catch (const std::invalid_argument& exception)
	{
		passed++;
	}

	try 
	{
		reader.readTeen(-4);
	}
	catch (const std::invalid_argument& exception)
	{
		passed++;
	}

	if (passed == 6)
	{
		std::cout << "TEST ReaderTest::testReadTeen PASSED " << std::endl;
	} 
	else 
	{
		std::cout << "TEST ReaderTest::testReadTeen FAILED " << std::endl;
	}
}

void ReaderTest::testReadTen(void)
{
	int passed = 0;
	Reader reader;
	passed += assert("twenty", reader.readTen(20));
	passed += assert("ninety-nine", reader.readTen(99));
	passed += assert("twenty-one", reader.readTen(21));
	passed += assert("sixty", reader.readTen(60));
	passed += assert("seventy-six", reader.readTen(76));
	try 
	{
		reader.readTen(-234);
	}
	catch (const std::invalid_argument& exception)
	{
		passed++;
	}

	if (passed == 6)
	{
		std::cout << "TEST ReaderTest::testReadTen PASSED " << std::endl;
	} 
	else 
	{
		std::cout << "TEST ReaderTest::testReadTen FAILED " << std::endl;
	}
}

void ReaderTest::testReadHundred(void)
{
	int passed = 0;
	Reader reader;
	passed += assert("one hundred", reader.readHundred(120));
	passed += assert("nine hundred", reader.readHundred(999));
	passed += assert("zero hundred", reader.readHundred(21));
	passed += assert("five hundred", reader.readHundred(34534));
	passed += assert("eight hundred", reader.readHundred(876));
	try 
	{
		reader.readHundred(-234);
	}
	catch (const std::invalid_argument& exception)
	{
		passed++;
	}

	if (passed == 6)
	{
		std::cout << "TEST ReaderTest::testReadHundred PASSED " << std::endl;
	} 
	else 
	{
		std::cout << "TEST ReaderTest::testReadHundred FAILED " << std::endl;
	}
}

void ReaderTest::testReadThousand(void)
{
	int passed = 0;
	Reader reader;
	passed += assert("zero thousand", reader.readThousand(4));
	passed += assert("one thousand", reader.readThousand(1000));
	passed += assert("ninety-nine thousand", reader.readThousand(99999));
	passed += assert("seventeen thousand", reader.readThousand(17642));
	passed += assert("eight thousand", reader.readThousand(108736));
	try 
	{
		reader.readThousand(-1);
	}
	catch (const std::invalid_argument& exception)
	{
		passed++;
	}

	if (passed == 6)
	{
		std::cout << "TEST ReaderTest::testReadThousand PASSED " << std::endl;
	} 
	else 
	{
		std::cout << "TEST ReaderTest::testReadThousand FAILED "<< passed << std::endl;
	}
}

void ReaderTest::testRead(void)
{
	int passed = 0;
	Reader reader;
	passed += assert("zero", reader.read(0));
	passed += assert("one", reader.read(1));
	passed += assert("nine", reader.read(9));
	passed += assert("fifteen", reader.read(15));
	passed += assert("twenty", reader.read(20));
	passed += assert("thirty-six", reader.read(36));
	passed += assert("ninety-nine", reader.read(99));
	passed += assert("one hundred", reader.read(100));
	passed += assert("one hundred and five", reader.read(105));
	passed += assert("two hundred and sixteen", reader.read(216));
	passed += assert("five hundred", reader.read(500));
	passed += assert("nine hundred and ninety-nine", reader.read(999));
	passed += assert("one thousand", reader.read(1000));
	passed += assert("one thousand and four", reader.read(1004));
	passed += assert("one thousand and eighteen", reader.read(1018));
	passed += assert("four thousand and twenty", reader.read(4020));
	passed += assert("seven thousand and fifty-four", reader.read(7054));
	passed += assert("ten thousand", reader.read(10000));
	passed += assert("twelve thousand and one", reader.read(12001));
	passed += assert("nineteen thousand nine hundred and ninety-nine", reader.read(19999));
	passed += assert("twenty thousand and two", reader.read(20002));
	passed += assert("fifty-four thousand and fifty-four", reader.read(54054));
	passed += assert("seventy-eight thousand nine hundred and twenty-one", reader.read(78921));
	passed += assert("ninety-nine thousand nine hundred and ninety-nine", reader.read(99999));

	try 
	{
		reader.read(-1);
	}
	catch (const std::invalid_argument& exception)
	{
		passed++;
	}

	try 
	{
		reader.read(100000);
	}
	catch (const std::invalid_argument& exception)
	{
		passed++;
	}

	if (passed == 26)
	{
		std::cout << "TEST ReaderTest::testRead PASSED " << std::endl;
	} 
	else 
	{
		std::cout << "TEST ReaderTest::testRead FAILED "<< passed << std::endl;
	}
}

void ReaderTest::runAll(void)
{
	testReadDigit();
	testReadTeen();
	testReadTen();
	testReadHundred();
	testReadThousand();
	testRead();
}
