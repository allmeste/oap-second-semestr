#include<iostream>
#include <windows.h>
#include "stdio.h"
#include <fstream>
using namespace std;

union buf
{
	char name[10], secname[15];
	int bdday, bdmounth, bdyear;
	int aday, amounth, ayear, lday, lmounth, lyear;
	int number;
	char type[15];
};
	struct hotel {
		char name[10], secname[15];
		int bdday, bdmounth, bdyear;
		int aday, amounth, ayear, lday, lmounth, lyear;
		int number;
		char type[15];
	};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "Russian");
  	int choice, n,beg;
	hotel mass[15];
	buf buffer;
	const char* file = "hotel.bin";
	char str[20];
	cout << "Введите информацию о 3 гостях " << endl;
	
	for (int i = 0; i < 3; i++) {
		fstream in_out(file, ios::binary | ios::in | ios::out | ios::trunc);
		in_out.seekp(0);
		cout << "Введите фамилию гостя: ";
		beg = in_out.tellg();
		cin >> buffer.secname;
		in_out.write((char*)&buffer.secname, sizeof buffer.secname);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].secname, sizeof mass[i].secname);

		cout << "Введите имя гостя: ";
		beg = in_out.tellg();
		cin >> buffer.name;
		in_out.write((char*)&buffer.name, sizeof & buffer.name);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].name, sizeof mass[i].name);

		cout << "Введите дату рождения: ";
		cout << "День: ";
		beg = in_out.tellg();
		cin >> buffer.bdday;
		in_out.write((char*)&buffer.bdday, sizeof buffer.bdday);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].bdday, sizeof mass[i].bdday);

		cout << "Месяц: ";
		beg = in_out.tellg();
		cin >> buffer.bdmounth;
		in_out.write((char*)&buffer.bdmounth, sizeof buffer.bdmounth);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].bdmounth, sizeof mass[i].bdmounth);

		cout << "Год: ";
		beg = in_out.tellg();
		cin >> buffer.bdyear;
		in_out.write((char*)&buffer.bdyear, sizeof buffer.bdyear);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].bdyear, sizeof mass[i].bdyear);

		cout << "Введите дату приезда " << endl;
		cout << "День: ";
		beg = in_out.tellg();
		cin >> buffer.aday;
		in_out.write((char*)&buffer.aday, sizeof buffer.aday);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].aday, sizeof mass[i].aday);

		cout << "Месяц: ";
		beg = in_out.tellg();
		cin >> buffer.amounth;
		in_out.write((char*)&buffer.amounth, sizeof buffer.amounth);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].amounth, sizeof mass[i].amounth);

		cout << "Год: ";
		beg = in_out.tellg();
		cin >> buffer.ayear;
		in_out.write((char*)&buffer.ayear, sizeof buffer.ayear);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].ayear, sizeof mass[i].ayear);

		cout << "Введите дату отъезда " << endl;
		cout << "День: ";
		beg = in_out.tellg();
		cin >> buffer.lday;
		in_out.write((char*)&buffer.lday, sizeof buffer.lday);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].lday, sizeof mass[i].lday);

		cout << "Месяц: ";
		beg = in_out.tellg();
		cin >> buffer.lmounth;
		in_out.write((char*)&buffer.lmounth, sizeof buffer.lmounth);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].lmounth, sizeof mass[i].lmounth);

		cout << "Год: ";
		beg = in_out.tellg();
		cin >> buffer.lyear;
		in_out.write((char*)&buffer.lyear, sizeof buffer.lyear);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].lyear, sizeof mass[i].lyear);

		cout << "Введите номер: ";
		beg = in_out.tellg();
		cin >> buffer.number;
		in_out.write((char*)&buffer.number, sizeof buffer.number);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].number, sizeof mass[i].number);

		cout << "Введите тип размещения (люкс, одноместный, двухместный, трехместный, апартаменты): ";
		beg = in_out.tellg();
		cin >> buffer.type;
		in_out.write((char*)&buffer.type, sizeof buffer.type);
		in_out.seekp(beg);
		in_out.read((char*)&mass[i].type, sizeof mass[i].type);
		in_out.close();
		cout << endl << endl;
	}
		cout << "Вывод информации о заданном госте" <<endl;
		cout<< "Введите фамилию гостя : ";
		cin>> str;
		cout << "Информация о данном госте:"<< endl;
		for ( int i = 0; i < 3; i++)
		{
			if (strcmp(mass[i].secname, str) == 0)
			{
				cout << "Имя: "<< mass[i].name <<endl;
				cout << "Фамилия: " << mass[i].secname << endl;
				cout << "Дата рождения: " << mass[i].bdday<<"  "<<mass[i].bdmounth<<"  "<<mass[i].bdyear;
				cout << "Дата приезда: " << mass[i].aday << "  " << mass[i].amounth << "  " << mass[i].ayear;
				cout << "Дата отъезда: " << mass[i].lday << "  " << mass[i].lmounth << "  " << mass[i].lyear;
				cout << "Номер и тип размещения: " << mass[i].number << " " << mass[i].type << endl;
			}
			if (strcmp(mass[i].name, str) != 0 && i == 2) cout <<"Информации о данном госте нет";
		}
	
}

	