
#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

using namespace std;

// Loggin enum type
enum eid{ERROR=1,WARNING,INFO,INPUT,OUTPUT};

class Logger
{
	static void write(eid,string&);
public:
	
	//log independently
	static void err(string);
	static void warn(string);
	static void info(string);
	static void inp(string);
	
	//log combined
	static void write(string);

	static string time();		//current time
	static void system();		//system info
	static void graphics();		//graphics info	
};


#endif