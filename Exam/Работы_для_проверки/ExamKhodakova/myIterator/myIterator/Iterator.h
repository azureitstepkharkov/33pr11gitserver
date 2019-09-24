#pragma once
class Iterator {
public:
	virtual bool hasNext() = 0;
	virtual int current() = 0;
	virtual int begin() = 0;
	virtual int end() = 0;

};