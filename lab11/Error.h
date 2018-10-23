#pragma once
#include <string>


class Error : public std::exception
{
private:
	std::string a;
public:
	Error(std::string s ) :exception(), a(s) {};
	std::string What() { return a; }
};