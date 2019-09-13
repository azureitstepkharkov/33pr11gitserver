#pragma once

#include <iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<list>
#include<ostream>

using namespace std;

class AddressInfo
{
protected:
	// конструктор по умолчанию
	AddressInfo() {};
	string nameCity;
	string nameStreet;
	string numHouse;
	int numFlat;



private:
	//конструктор копирования
	AddressInfo(AddressInfo& obj)
	{
		cout << "call AddressInfo(AddressInfo&)" << endl;
	}

public:

	//перегруженный конcтруктор
	AddressInfo(string nameCity, string nameStreet, string numHouse, int numFlat)
	{

		this->nameCity = nameCity;
		this->nameStreet = nameStreet;
		this->numHouse = numHouse;
		this->numFlat = numFlat;
	}


	~AddressInfo() {
		cout << "call ~AddressInfo()" << endl;
	};

	//перегрузка оператора <<
	friend ostream& operator<< (ostream& os,
		const AddressInfo& t)
	{
		os << " nameCity = "
			<< t.nameCity
			<< "nameStreet = "
			<< t.nameStreet
			<< "nameStreet = "
			<< t.nameStreet
			<< "numHouse = "
			<< t.numHouse;
		return os;



		// сеттеры и геттеры
	/*	void set_nameCity(string nameCity)
		{
			this->nameCity = nameCity;
		}
		string get_nameCity()
		{
			return this->nameCity;
		}


		void set_nameStreet(string nameStreet)
		{
			this->nameStreet = nameStreet;
		}

		string get_nameStreet()
		{
			return this->nameStreet;
		}


		void set_numHouse(string numHouse)
		{
			this->numHouse = numHouse;
		}

		string get_numHouse()
		{
			return this->numHouse;
		}


		void set_numFlat(int numFlat)
		{
			this->numFlat = numFlat;
		}

		int get_numFlat()
		{
			return this->numFlat;
		}
*/
	}



};

