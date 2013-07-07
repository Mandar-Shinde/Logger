

// Author: Mandar Shinde
// 

#include <iostream>
#include "Logger.h"

class ExceptionMessage 
{
public:
	std::string what()
	{
		return "Something Bad Happened Error No: 00001";
	}
};

int main()
{
	Logger::system();

	try
	{
		throw ExceptionMessage();
	}
	catch (ExceptionMessage e)
	{
		Logger::err(e.what());
		Logger::info("\nthis is probably occurs when you do this, Try that in place of this");
		Logger::write("This is single file log writing");
	}

	return 0;
}



