#pragma once
class AdressInfo
{
protected:
	string city;
	string street;
	string houseN;
	string flatN;
	
public:
	AdressInfo(const AdressInfo & obj) {}
	AdressInfo() {};
	AdressInfo(string city,
		string street,
		string houseN,
		string flatN)
	{
		this->city = city;
		this->street = street;
		this->houseN = houseN;
		this->flatN = flatN;
	}

	void setCity(string city)
	{
		this->city = city;
	}
	void setStreet(string street)
	{
		this->street = street;
	}
	void setHouseN(string houseN)
	{
		this->houseN = houseN;
	}
	void setFlatN(string flatN)
	{
		this->flatN = flatN;
	}
	
	string getCity()
	{
		return city;
	}
	string getStreet()
	{
		return street;
	}
	string getHouseN()
	{
		return houseN;
	}
	string getFlatN()
	{
		return flatN;
	}

	friend ostream& operator << (ostream& os, const AdressInfo& adr)
	{
		os << "City: " << adr.city
			<< "\n"
			<< "Street: " << adr.street
			<< "\n"
			<< "Num of House: " << adr.houseN
			<< "\n"
			<< "Num of Flat: " << adr.flatN << endl;
		 
		return os;
	}

	~AdressInfo() {};
};

