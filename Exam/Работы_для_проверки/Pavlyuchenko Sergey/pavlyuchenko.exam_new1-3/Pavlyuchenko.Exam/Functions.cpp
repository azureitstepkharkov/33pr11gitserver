// � ���� ������������ ����� ���������� ���������� ������� ��� ������ � ��������

#include "Functions.h"

void clearInput() {
	cin.clear();
	cin.ignore(132, '\n');
}
string checkSex() {
	string sex = "";
	short int chooseGender = -1; // ��� ������ ����
	do {
		cout << "�������� ���: " << endl;
		char genderMan[8] = "�������"; // ���������� �������� ����
		char genderWoman[8] = "�������"; // ���������� �������� ����
		cout << "\t1. " << genderMan << endl;
		cout << "\t2. " << genderWoman << endl;
		cout << "������� 1 ��� 2: "; 
		cin.sync();
		cin >> chooseGender;
		switch (chooseGender) {
		case 1:
			sex = genderMan;
			break;
		case 2:
			sex = genderWoman;
			break;
		default:
			system("color 47");
			cout << "�������� �����!" << endl;
			Sleep(1000);
			system("color 07");
		}
	} while (chooseGender != 1 && chooseGender != 2);
	return sex;
}
int checkNumber(istream &in, string description) {
	int number = 0;
	cout << description;
	while (!(in >> number)) {
		system("color 47");
		cout << "������� �����!" << endl;
		clearInput();
		Sleep(1000);
		system("color 07");
		cout << description;
	}
	return number;
}
double checkCalc(istream &in, string description) {
	double number = 0;
	cout << description;
	while (!(in >> number)) {
		system("color 47");
		cout << "������� �����!" << endl;
		clearInput();
		Sleep(1000);
		system("color 07");
		cout << description;
	}
	return number;
}
string checkString(istream &in, string description) {
	string str = "";
	bool notThisData; // �������� �� ������������ ����� ������
	do {
		system("color 07");
		cout << description;
		in.sync();
		in >> str;
		notThisData = ((str).find_first_not_of("0123456789") == std::string::npos);
		if (notThisData) {
			system("color 47");
			cout << "������� ������!" << endl;
			Sleep(1000);
		}
	} while (notThisData);
	return str;
}
string checkPhone(istream &in) {
	string phone = "";
	bool notThisData; // �������� �� ������������ ����� ������
	do {
		system("color 07");
		cout << "�������: ";
		in.sync();
		in >> phone;
		notThisData = ((phone).find_first_not_of("0123456789().+-") == std::string::npos);
		if (!notThisData) {
			system("color 47");
			cout << "������� �������!" << endl;
			Sleep(1000);
		}
	} while (!notThisData);
	return phone;
}
string checkPosition(istream &in) {
	enum positions { janitor = 1, handyman, programmer, driver, accountant, financialAnalyst, director, salesManager };	// ������������ ����������
	string position = "";
	short int chooseAnswer = -1; // ��� ������ ������
	short int choosePosition = -1; // ��� ������ ���������
	bool notThisData; // �������� �� ������������ ����� ������
	do {
		cout << "������� ��������� ��� ������ ����: " << endl;
		cout << "\t1. �������" << endl;
		cout << "\t2. ������ ����" << endl;
		cout << "������� 1 ��� 2: ";
		in.sync();
		cin >> chooseAnswer;
		switch (chooseAnswer) {
		case 1:
			cout << "�������� ���������: " << endl;
			cout << "\t1. �������" << endl;
			cout << "\t2. ������������" << endl;
			cout << "\t3. �����������" << endl;
			cout << "\t4. ��������" << endl;
			cout << "\t5. ���������" << endl;
			cout << "\t6. ���������� ��������" << endl;
			cout << "\t7. ��������" << endl;
			cout << "\t8. �������� �� ��������" << endl;
			cout << "������� �� 1 �� 8: ";
			in.sync();
			cin >> choosePosition;
			switch (choosePosition) {
			case janitor:
				position = "�������";
				break;
			case handyman:
				position = "������������";
				break;
			case programmer:
				position = "�����������";
				break;
			case driver:
				position = "��������";
				break;
			case accountant:
				position = "���������";
				break;
			case financialAnalyst:
				position = "���������� ��������";
				break;
			case director:
				position = "��������";
				break;
			case salesManager:
				position = "�������� �� ��������";
				break;
			default:
				break;
			}
			break;
		case 2:
			do {
				system("color 07");
				cout << "���������: ";
				in.sync();
				in >> position;
				notThisData = ((position).find_first_not_of("0123456789") == std::string::npos);
				if (notThisData) {
					system("color 47");
					cout << "������� ������!" << endl;
					Sleep(1000);
				}
			} while (notThisData);
			break;
		default:
			system("color 47");
			cout << "�������� �����!" << endl;
			Sleep(1000);
			system("color 07");
		}
	} while (chooseAnswer != 1 && chooseAnswer != 2);
	return position;
}
int checkCodePosition(istream &in) {
	enum positions { janitor = 1, handyman, programmer, driver, accountant, financialAnalyst, director, salesManager };	// ������������ ����������
	int codePosition = 0;
	short int chooseAnswer = -1; // ��� ������ ������
	short int choosePosition = -1; // ��� ������ ���������
	bool notThisData; // �������� �� ������������ ����� ������
	do {
		cout << "������� ��������� ��� ������ � ���: " << endl;
		cout << "\t1. �������" << endl;
		cout << "\t2. ������ � ���" << endl;
		cout << "������� 1 ��� 2: ";
		in.sync();
		cin >> chooseAnswer;
		switch (chooseAnswer) {
		case 1:
			cout << "�������� ���������: " << endl;
			cout << "\t1. �������" << endl;
			cout << "\t2. ������������" << endl;
			cout << "\t3. �����������" << endl;
			cout << "\t4. ��������" << endl;
			cout << "\t5. ���������" << endl;
			cout << "\t6. ���������� ��������" << endl;
			cout << "\t7. ��������" << endl;
			cout << "\t8. �������� �� ��������" << endl;
			cout << "������� �� 1 �� 8: ";
			in.sync();
			cin >> choosePosition;
			switch (choosePosition) {
			case janitor:
				codePosition = 1;
				break;
			case handyman:
				codePosition = 1;
				break;
			case programmer:
				codePosition = 3;
				break;
			case driver:
				codePosition = 2;
				break;
			case accountant:
				codePosition = 2;
				break;
			case financialAnalyst:
				codePosition = 3;
				break;
			case director:
				codePosition = 4;
				break;
			case salesManager:
				codePosition = 4;
				break;
			default:
				break;
			}
			break;
		case 2:
			cout << "��� ���������: ";
			while (!(in >> codePosition)) {
				system("color 47");
				cout << "������� �����!" << endl;
				clearInput();
				Sleep(1000);
				system("color 07");
				cout << "��� ���������: ";
			}
			break;
		default:
			system("color 47");
			cout << "�������� �����!" << endl;
			Sleep(1000);
			system("color 07");
		}
	} while (chooseAnswer != 1 && chooseAnswer != 2);
	return codePosition;
}