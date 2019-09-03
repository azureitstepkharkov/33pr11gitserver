#pragma once
#include "InfoData.h"
#include <iostream>
//
#include<iomanip>//<<setw(10)
//stl
#include <fstream>//
#include<algorithm>//sort
#include<vector>//������ �������
#include<functional>//������� ��� ���������� less<int> � �.�.
#include<string>//������ �� ��������
#include<list>//������ ������
//
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

using namespace std;

class SelectExecutor
{
protected:
	SelectExecutor()
	{
		std::cout << "MS SQL Server Data Test!\n";
	}
	//+���������� �������
	SQLHANDLE SQLEnvHandle = NULL;//��������� �� �������� ��������� MS SQL Server
	SQLHANDLE SQLConnectionHandle = NULL;//��������� �� ��������� ���������� � ����� ������
	SQLHANDLE SQLStatementHandle = NULL;//��������� �� ������� 
	SQLRETURN retCode = 0;
	//char SQLQuery[1024];// = "SELECT ProductName, ProductID, UnitPrice FROM Products";//��� ����� �������
	SQLCHAR* SQLQuery;
	SQLCHAR* connectionString;
public:
	void showSQLError(unsigned int handleType, const SQLHANDLE& handle)
	{
		SQLCHAR SQLState[1024];
		SQLCHAR message[1024];
		if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, message, 1024, NULL))
			// Returns the current values of multiple fields of a diagnostic record that contains error, warning, and status information
			cout << "SQL driver message: " << message << "\nSQL state: " << SQLState << "." << endl;
	}
	
	//SelectExecutor("SELECT ProductName, ProductID, UnitPrice FROM Products");
	SelectExecutor(char SQLQuery[1024])
	{
		SQLCHAR connectionString[] = "DRIVER={SQL Server}; SERVER=localhost, 1433; DATABASE=NORTHWIND; Trusted_Connection=Yes";
		this->connectionString = (SQLCHAR*)connectionString;
		this->SQLQuery = (SQLCHAR*)SQLQuery;
		Execute(this->SQLQuery);
	};
	
	void Execute(char SQLQuery[1024])
	{
		this->SQLQuery = (SQLCHAR*)SQLQuery;
		Execute(this->SQLQuery);
	}
	void Execute(SQLCHAR* SQLQuery)
	{
		//char SQLQuery[] = "SELECT ProductName, ProductID, UnitPrice FROM Products";//��� ����� �������
		//(SQLCHAR*)
		do
		{
			//
			if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
				// ���������� � ����������� ����������� MS SQL Server
				break;
			if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
				// ������ �������������� - ����� �������� 
				break;
			if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
				// ������� ������ ��� ������� Connection
				break;
			if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
				// ������������� ���������� - �������
				break;
			SQLCHAR retConString[1024]; // Conection string
			//switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"DRIVER={SQL Server}; SERVER=localhost, 1433; DATABASE=myDB; UID=myID; PWD=myPW;", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
			switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)connectionString, SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {
				// ����������� ����������
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
				// ��������� ����� ��� ���������� ������ �������
				break;
			if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
				// ���������� ������� �� ����� sql ������� �� ����� �������
				showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
				break;
			}
			else {
				//������ - ��������� � ��������� �����
				//InfoData �������� �� ����� Adress
				vector<InfoData*> info;
				getDataFromSelect(SQLStatementHandle, info);
				for (int i = 0; i < info.size(); i++)
				{
					cout << info[i]->name << " " << info[i]->id << endl;
				}
			}
			//
		} while (FALSE);
	}
	void getDataFromSelect(SQLHANDLE SQLStatementHandle, vector<InfoData*>&info)
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
			InfoData* data = new InfoData();
			data->id = id;
			data->name = name;
			info.push_back(data);
		}
	}
	friend ostream& operator<< (ostream& os, SelectExecutor& data)
	{
		os << "connection string:  " << data.connectionString << endl;
		return os;
	}
	friend ostream& operator<< (ostream& os, SelectExecutor* data)
	{
		os << "connection string:  " << data->connectionString << endl;
		return os;
	}
	virtual ~SelectExecutor()
	{
		SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
		SQLDisconnect(SQLConnectionHandle);
		SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
		SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
	};
};

