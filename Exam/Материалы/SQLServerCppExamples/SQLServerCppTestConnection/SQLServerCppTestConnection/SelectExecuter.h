#pragma once
#include"InfoData.h"

#include <iostream>//operator<<
#include <fstream>//
#include<algorithm>//sort
#include<vector>//замена массива
#include<functional>//шаблоны дл€ сортировок less<int> и т.п.
#include<string>//работа со строками
#include<list>//замена списка

#include<iomanip>
//
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

using namespace std;
class SelectExecuter
{
protected:
	void showSQLError(unsigned int handleType, const SQLHANDLE& handle)
	{
		SQLCHAR SQLState[1024];
		//unsigned char SQLState[1024];
		SQLCHAR message[1024];
		if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, message, 1024, NULL))
			// Returns the current values of multiple fields of a diagnostic record that contains error, warning, and status information
			cout << "SQL driver message: " << message << "\nSQL state: " << SQLState << "." << endl;
	}
protected:
	SelectExecuter()
	{

	};
	SQLHANDLE SQLEnvHandle = NULL;//указатель на запущенный экземпл€р MS SQL Server
	SQLHANDLE SQLConnectionHandle = NULL;//указатель на настроенное соединение
	SQLHANDLE SQLStatementHandle = NULL;//указтель на созданные запрос
	SQLRETURN retCode = 0;
	SQLCHAR* SQLQuery;
	SQLCHAR* connectionString;
public:
	//char SQLQuery[] = "SELECT ProductName, ProductID, UnitPrice FROM Products";//текст запроса
	SelectExecuter(SQLCHAR SQLQuery[])
	{
		this->connectionString = (SQLCHAR*)"DRIVER={SQL Server}; SERVER=localhost, 1433; DATABASE=NORTHWIND; Trusted_Connection=Yes";
		this->SQLQuery = (SQLCHAR*)SQLQuery;
		Execute(this->SQLQuery);
	}
	SelectExecuter(SQLCHAR SQLQuery[], SQLCHAR connectionString[])
	{
		this->connectionString = (SQLCHAR*)connectionString;
			//"DRIVER={SQL Server}; SERVER=localhost, 1433; DATABASE=NORTHWIND; Trusted_Connection=Yes";
		this->SQLQuery = (SQLCHAR*)SQLQuery;
		Execute(this->SQLQuery);
	}
	//
	//перегрузка об€зательных операторов
	friend ostream& operator<< (ostream& os, SelectExecuter& data)
	{
		os << "connection String = " << data.connectionString << endl;
		return os;
	}
	friend ostream& operator<< (ostream& os, SelectExecuter* data)
	{
		os << "connection String = " << data->connectionString << endl;
		return os;
	}
	//
	void Execute(SQLCHAR* SQLQuery)
	{
		do
		{
			if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
				// соедин€юсь с экземпл€ром
				break;
			if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
				// атрибуты доступа к серверу
				break;
			if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
				//выдел€ю ресурсы дл€  соединение
				break;
			if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
				// Sets attributes that govern aspects of connections
				break;
			SQLCHAR retConString[1024]; // Conection string
			//switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"DRIVER={SQL Server}; SERVER=localhost, 1433; DATABASE=myDB; UID=myID; PWD=myPW;", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
			switch (SQLDriverConnect(SQLConnectionHandle, NULL, connectionString, SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
				// Establishes connections to a driver and a data source
			case SQL_SUCCESS:
				break;
			case SQL_SUCCESS_WITH_INFO:
				break;
			case SQL_NO_DATA_FOUND:
				showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
				retCode = -1;
				break;
			case SQL_INVALID_HANDLE:
				showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
				retCode = -1;
				break;
			case SQL_ERROR:
				showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
				retCode = -1;
				break;
			default:
				break;
			}

			if (retCode == -1)
				break;

			if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))
				// выдел€ю ресурсы дл€ запроса
				break;

			if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
				// выполн€ю текст sql команды на сервере
				showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
				break;
			}
			else {
				vector<InfoData*> result;
				getResult(SQLStatementHandle, result);
				for (int i = 0; i < result.size(); i++)
				{
					cout << result[i]->id << " " << result[i]->name << endl;
				}
			}
			//
		} while (FALSE);
	}
	void getResult(SQLHANDLE SQLStatementHandle, vector<InfoData*>& result)
	{
		char name[256];
		int id;
		long double price;
		while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
			// Fetches the next rowset of data from the result
			SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &name, sizeof(name), NULL);
			SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &id, sizeof(id), NULL);
			SQLGetData(SQLStatementHandle, 3, SQL_C_DEFAULT, &price, sizeof(price), NULL);
			// Retrieves data for a single column in the result set
			//cout << name << " " << id << " " << std::get_money(price) << endl;
			//MyAdres adr = new Adr(id,name, price);
			//vec.add(adr);//list<MyAdres> vec;
			InfoData* data = new InfoData;
			data->id = id;
			data->name = name;
			result.push_back(data);
		}

	}
	virtual ~SelectExecuter()
	{
		SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
		SQLDisconnect(SQLConnectionHandle);
		SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
		SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
	};
};

