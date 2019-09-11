#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class StringHeper
{
public:
	StringHeper();
	~StringHeper();

	static std::string int2str(int x) {
		// converts int to string
		std::stringstream ss;
		ss << x;
		return ss.str();
	}
};


