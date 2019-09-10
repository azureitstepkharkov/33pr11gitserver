#pragma once
#include <iostream>
#include <string>
#include <sstream>
class StringHelper
{
public:
	StringHelper() {};
	~StringHelper() {};
	static std::string int2str(int x) {
		// converts int to string
		std::stringstream ss;
		ss << x;
		return ss.str();
	}
};

