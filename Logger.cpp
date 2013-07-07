
#ifndef LOGGER_CPP
#define LOGGER_CPP


#include "Logger.h"
#include <iostream>
#include <fstream>
#include <time.h>

//#include <gl/GL.h>
//#pragma comment(lib,"Opengl32.lib")

void Logger::err(string msg)
{
	write(ERROR,msg+"\n");
}
void Logger::warn(string msg)
{
	write(WARNING,msg+"\n");
}
void Logger::info(string msg)
{
	write(INFO,msg+"\n");
}
void Logger::inp(string msg)
{
	write(INPUT,msg+"\n");
}
void Logger::write(eid e,string& msg)
{
	ofstream ofs;

	switch(e)	
	{
		case ERROR:			
			ofs.open("LogError.txt",std::ofstream::out | std::ofstream::app); // std::ofstream::trunc  to apppend
			break;
		
		case WARNING:
			ofs.open("LogWarning.txt",std::ofstream::out | std::ofstream::app); 
			break;

		case INFO:
			ofs.open("LogInfo.txt",std::ofstream::out | std::ofstream::app); 
			break;

		case INPUT:
			ofs.open("LogError.txt",std::ofstream::out | std::ofstream::app); 
			break;

		default: break;
	}

	ofs<<msg;
	ofs.close();
	
}

string operator+(string a,string b)
{
	return a.append(b);
}

void Logger::write(string msg)
{
	ofstream ofs;	
	ofs.open("Log.txt",std::ofstream::out | std::ofstream::app); 	
	ofs<<msg;
	ofs.close();	
}

std::string Logger::time()
{
	time_t timer=NULL;
	struct tm st_tm;		 
	::time(&timer); 
	localtime_s(&st_tm,&timer);
	char s[30]={0};
	asctime_s(s,30,&st_tm);
	std::string str;
	//change format in future
	str.assign(s);
	return str;
}
void Logger::system()
{
	std::string out;
	out.append("------------SYSTEM-----------\n");
	out.append("  "+time()+"\n");
	
	//CPU
	out.append("System CPU version \n");

	//Architecture
	out.append("Architecture version \n");

	out.append("------------------------------\n");
	ofstream ofs;
	ofs.open("Log.txt",std::ofstream::out | std::ofstream::app); 
	ofs<<out;
	ofs.close();
}

void Logger::graphics()
{
	std::string out;
	out.append("-----------GRAPHICS-----------\n");
	out.append("  "+time()+"\n");
	
	//OpenGL version
	out.append("Opengl version \n");

	//Rendere
	out.append("Renderer \n");

	out.append("------------------------------\n");
	ofstream ofs;
	ofs.open("Log.txt",std::ofstream::out | std::ofstream::app); 
	ofs<<out;
	ofs.close();
}


#endif

