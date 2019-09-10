#pragma once


class TypeStreet
{
private:
	string Typename;
	TypeStreet();
public:
	
	~TypeStreet();
	TypeStreet(const TypeStreet& obj);
	
	TypeStreet(string Typename);

	void setTypeStreetName(string Typename);
	
	string getTypeStreetName();
};