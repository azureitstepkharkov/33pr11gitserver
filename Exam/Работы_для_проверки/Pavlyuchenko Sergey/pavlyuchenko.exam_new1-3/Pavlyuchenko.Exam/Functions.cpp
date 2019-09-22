// В этом заголовочном файле содержмтся реализация функций для работы с проектом

#include "Functions.h"

void clearInput() {
	cin.clear();
	cin.ignore(132, '\n');
}
string checkSex() {
	string sex = "";
	short int chooseGender = -1; // Для выбора пола
	do {
		cout << "Выберите пол: " << endl;
		char genderMan[8] = "Мужской"; // Переменная мужского пола
		char genderWoman[8] = "Женский"; // Переменная женского пола
		cout << "\t1. " << genderMan << endl;
		cout << "\t2. " << genderWoman << endl;
		cout << "Введите 1 или 2: "; 
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
			cout << "Неверный выбор!" << endl;
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
		cout << "Введите число!" << endl;
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
		cout << "Введите число!" << endl;
		clearInput();
		Sleep(1000);
		system("color 07");
		cout << description;
	}
	return number;
}
string checkString(istream &in, string description) {
	string str = "";
	bool notThisData; // Проверка на правильность ввода данных
	do {
		system("color 07");
		cout << description;
		in.sync();
		in >> str;
		notThisData = ((str).find_first_not_of("0123456789") == std::string::npos);
		if (notThisData) {
			system("color 47");
			cout << "Введите строку!" << endl;
			Sleep(1000);
		}
	} while (notThisData);
	return str;
}
string checkPhone(istream &in) {
	string phone = "";
	bool notThisData; // Проверка на правильность ввода данных
	do {
		system("color 07");
		cout << "Телефон: ";
		in.sync();
		in >> phone;
		notThisData = ((phone).find_first_not_of("0123456789().+-") == std::string::npos);
		if (!notThisData) {
			system("color 47");
			cout << "Введите телефон!" << endl;
			Sleep(1000);
		}
	} while (!notThisData);
	return phone;
}
string checkPosition(istream &in) {
	enum positions { janitor = 1, handyman, programmer, driver, accountant, financialAnalyst, director, salesManager };	// Перечисление должностей
	string position = "";
	short int chooseAnswer = -1; // Для выбора ответа
	short int choosePosition = -1; // Для выбора должности
	bool notThisData; // Проверка на правильность ввода данных
	do {
		cout << "Выбрать должность или ввести свою: " << endl;
		cout << "\t1. Выбрать" << endl;
		cout << "\t2. Ввести свою" << endl;
		cout << "Введите 1 или 2: ";
		in.sync();
		cin >> chooseAnswer;
		switch (chooseAnswer) {
		case 1:
			cout << "Выберите должность: " << endl;
			cout << "\t1. Дворник" << endl;
			cout << "\t2. Разнорабочий" << endl;
			cout << "\t3. Программист" << endl;
			cout << "\t4. Водитель" << endl;
			cout << "\t5. Бухгалтер" << endl;
			cout << "\t6. Финансовый аналитик" << endl;
			cout << "\t7. Директор" << endl;
			cout << "\t8. Менеджер по продажам" << endl;
			cout << "Введите от 1 до 8: ";
			in.sync();
			cin >> choosePosition;
			switch (choosePosition) {
			case janitor:
				position = "Дворник";
				break;
			case handyman:
				position = "Разнорабочий";
				break;
			case programmer:
				position = "Программист";
				break;
			case driver:
				position = "Водитель";
				break;
			case accountant:
				position = "Бухгалтер";
				break;
			case financialAnalyst:
				position = "Финансовый аналитик";
				break;
			case director:
				position = "Директор";
				break;
			case salesManager:
				position = "Менеджер по продажам";
				break;
			default:
				break;
			}
			break;
		case 2:
			do {
				system("color 07");
				cout << "Должность: ";
				in.sync();
				in >> position;
				notThisData = ((position).find_first_not_of("0123456789") == std::string::npos);
				if (notThisData) {
					system("color 47");
					cout << "Введите строку!" << endl;
					Sleep(1000);
				}
			} while (notThisData);
			break;
		default:
			system("color 47");
			cout << "Неверный выбор!" << endl;
			Sleep(1000);
			system("color 07");
		}
	} while (chooseAnswer != 1 && chooseAnswer != 2);
	return position;
}
int checkCodePosition(istream &in) {
	enum positions { janitor = 1, handyman, programmer, driver, accountant, financialAnalyst, director, salesManager };	// Перечисление должностей
	int codePosition = 0;
	short int chooseAnswer = -1; // Для выбора ответа
	short int choosePosition = -1; // Для выбора должности
	bool notThisData; // Проверка на правильность ввода данных
	do {
		cout << "Выбрать должность или ввести её код: " << endl;
		cout << "\t1. Выбрать" << endl;
		cout << "\t2. Ввести её код" << endl;
		cout << "Введите 1 или 2: ";
		in.sync();
		cin >> chooseAnswer;
		switch (chooseAnswer) {
		case 1:
			cout << "Выберите должность: " << endl;
			cout << "\t1. Дворник" << endl;
			cout << "\t2. Разнорабочий" << endl;
			cout << "\t3. Программист" << endl;
			cout << "\t4. Водитель" << endl;
			cout << "\t5. Бухгалтер" << endl;
			cout << "\t6. Финансовый аналитик" << endl;
			cout << "\t7. Директор" << endl;
			cout << "\t8. Менеджер по продажам" << endl;
			cout << "Введите от 1 до 8: ";
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
			cout << "Код должности: ";
			while (!(in >> codePosition)) {
				system("color 47");
				cout << "Введите число!" << endl;
				clearInput();
				Sleep(1000);
				system("color 07");
				cout << "Код должности: ";
			}
			break;
		default:
			system("color 47");
			cout << "Неверный выбор!" << endl;
			Sleep(1000);
			system("color 07");
		}
	} while (chooseAnswer != 1 && chooseAnswer != 2);
	return codePosition;
}