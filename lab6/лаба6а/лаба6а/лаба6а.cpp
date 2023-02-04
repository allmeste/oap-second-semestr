#include<iostream>
#include <windows.h>
#include "stdio.h"
using namespace std;
enum Type
{
	lux = 1, oneside, twoside,
	threeside, apartment
};
struct pasport{
	string name;
	char sername[20] ;
	string cod;
	int number;
};
  struct arrival //битовое поле
{
	unsigned short day : 5; //32 бита
	unsigned short mounth : 4;//16 бита
	unsigned short  year : 1;//2 бита
};

  struct hotel
  {
	  pasport data;
	  arrival coming;
	  arrival departure;
  } ht;
 
int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "Russian");
	struct hotel mass[3];
	char type;
	int a;
	int choice, length = 2;
	
	while (1)
	{
		cout << "1. - Запись информации о госте" << endl;
		cout << "2. - Поиск гостя по дате приезда" << endl;
		cout << "3. - Удаление гостя" << endl;
		cout << "4. - Выход"<<endl;
		cout << "Введите число: ";
		cin >> choice;
		cout << endl;
	
		switch (choice)
		{
		case 1:
			char str[5];
			int d;

			for (int i = 0; i < length; i++)
			{
				cout << "Паспортные данные: ";
				cout << "Введите имя гостя:  ";
				cin >> mass[i].data.name;
				cout << "Введите фамилию гостя:  ";
				cin >> mass[i].data.sername;
				cout << "Введите код паспорта:  ";
				cin >> mass[i].data.cod;
				cout << "Введите номер паспорта: ";
				cin >> mass[i].data.number;

				cout << endl << "Дата приезда : " << endl;
				cout << "День  : ";
				cin >> d;
				mass[i].coming.day = d;
				cout << "Месяц: ";
				cin >> d;
				mass[i].coming.mounth = d;
				cout << "Год  : ";
				cin >> d;
				mass[i].coming.year = d;

				cout << endl << "Дата отезда : " << endl;
				cout << "День:  ";
				cin >> d;
				mass[i].departure.day = d;
				cout << "Месяц:  ";
				cin >> d;
				mass[i].departure.mounth = d;
				cout << "Год  : ";
				cin >> d;
				mass[i].departure.year = d;
			}

			break;
		case 2:

			int day;
			int mounth;
			int year;

			cout << "Введите дату приезда гостя  ";
			cin >> day >> mounth >> year;
			cout << "Информация о найденном госте : " << endl;

			for (int j = 0; j < length; j++)
			{
				if (day == ht.coming.day && mounth == ht.coming.mounth && year == ht.coming.year)
				{
					cout << endl << "Паспортные данные: " << endl;
					cout << "Имя гостя ";
					cout << mass[j].data.name;
					cout << endl << " Фамилия гостя ";
					cout << mass[j].data.sername;
					cout << endl << "Код паспорта: ";
					cout << mass[j].data.cod;
					cout << endl << "Номер паспорта: ";
					cout << mass[j].data.number;


					cout << endl << "Дата отезда : " << endl;
					cout << "День  : ";
					cout << mass[j].coming.day;
					cout << endl << "Месяц  : ";
					cout << mass[j].coming.mounth;
					cout << endl << "Год  : ";
					cout << mass[j].coming.year<< endl;
				}
			}
			break;
		case 3:
			cout << " Удаление гостя по дню отъезда " << endl;
			cout << "Введите день отъезда  " << endl;
			cin >>a;
			

			            for (int j = 0; j < length; j++)
			            {
			                if (ht.departure.day == a )
			                {
			                    for (int k = j; k < length; k++)
			                    {
									mass[k] = mass[k + 1];
			                    }
			                    j--;
			                    length--;
			                }
			            }
			            cout << "Информация об госте удалена" << endl << endl;
			            break;
		case 4:
			exit(0);
		}
	}

}
	
///*co/*ut << "Введите тип размещения (от 1 до 5): \n 1-люкс \n 2-одноместный \n 3-двухместный \n 4-трехместный \n 5-апартаменты" << endl;
		/*cin >> type;
		if (strcmp(lux, type) == 0)
		{
			cout << "Вы забронировали номер ЛЮКС " << endl;
		}*/
		

//#include <iostream>
//#include <windows.h>
//#include "stdio.h"
//
//using namespace std;
//
//enum Specualities
//{
//    ICIT = 1, POIT, DEVI, MOB
//};
//struct TestResults//битовое поле
//{
//    unsigned short physics : 7;// 7 битов это 2^7=128
//    unsigned short math : 7;
//    unsigned short russian : 7;
//};
//
//struct DirectoryOfUnies
//{
//    string university;
//    char uniAdress;
//    TestResults result;
//    string price;
//    int spec;
//};
//
//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    setlocale(LC_ALL, "Russian");
//    struct DirectoryOfUnies mass[2];
//    int length = 2;
//
//    int choice, flag = 0, i = 0;
//    char buf[20];
//    char forSpec[10];
//    while (true)
//    {
//        cout << "1. - Запись инфы по унивверам" << endl;
//        cout << "2. - Поиск универа по прохрдному баллу" << endl;
//        cout << "3. - Удаление универа" << endl;
//        cout << "4. - Вывод всех универов" << endl;
//        cout << "5. - Выбор универов и их специальностей, где проходной балл меньше указанного" << endl;
//        cout << "6. - Выход" << endl << endl;
//        cout << "Введите число: ";
//        cin >> choice;
//        cout << endl;
//        switch (choice)
//        {
//        case 1:
//            int testsResults;
//            char str[5];
//            for (int i = 0; i < length; i++)
//            {
//                cout << "Название универа: ";
//                cin >> mass[i].university;
//
//                cout << "Адрес: ";
//                cin >> mass[i].uniAdress;
//
//                cout << "Минимум по физике: ";
//                cin >> testsResults;
//                mass[i].result.physics = testsResults;
//
//                cout << "Минимум по математике: ";
//                cin >> testsResults;
//                mass[i].result.math = testsResults;
//
//                cout << "Минимум по русскому: ";
//                cin >> testsResults;
//                mass[i].result.russian = testsResults;
//
//                cout << "Опалата по договору: ";
//                cin >> mass[i].price;
//
//                cout << "Специальность: ";
//                cin >> forSpec;
//                /*ICIT = 1, POIT, DEVI, MOB*/
//                if (strcmp(forSpec, "ИСИТ") == 0) mass[i].spec = ICIT;
//                if (strcmp(forSpec, "ПОИТ") == 0) mass[i].spec = POIT;
//                if (strcmp(forSpec, "ДЭиВИ") == 0) mass[i].spec = DEVI;
//                if (strcmp(forSpec, "ПОИБМС") == 0) mass[i].spec = MOB;
//            }
//            i = length;
//            break;
//        case 2:
//            int specNumb;
//            cout << "Поиск универа по номеру специальности" << endl;
//            cout << "Введите номер специальности" << endl;
//            cout << "Специальности: ИСИТ- 1, ПОИТ- 2, ДЭиВИ - 3, ПОИБМС - 4" << endl;
//            cin >> specNumb;
//
//            cout << "Информация о найденном универе: " << endl;
//            for (int j = 0; j < length; j++)
//            {
//                if (specNumb == mass[j].spec)
//                {
//
//                    cout << "Название универа: " << mass[i].university << endl;
//
//                    cout << "Адрес универа: " << mass[i].uniAdress << endl;
//
//                    cout << "Минимум по физике: " << mass[i].result.physics << endl;
//
//                    cout << "Минимум по математике: " << mass[i].result.math << endl;
//
//                    cout << "Минимум по русскому: " << mass[i].result.russian << endl;
//
//                    cout << "Опалата по договору: " << mass[i].price << endl;
//                }
//            }
//            cout << endl << endl;
//            break;
//
//        case 3:
//            cout << "Удаление универа с названием БГУИР: ";
//            cin >> buf;
//            for (int j = 0; j < i; j++)
//            {
//                if (mass[j].university == "БГУИР")
//                {
//                    for (int k = j; k < i; k++)
//                    {
//                        mass[k] = mass[k + 1];
//                    }
//                    j--;
//                    i--;
//                }
//            }
//            cout << "Информация об универе удалена" << endl << endl;
//            break;
//        case 4: cout << "Вывод информации обо всех универах: ";
//            for (int j = 0; j < length; j++)
//            {
//                cout << "Название универа: " << mass[j].university << endl;
//
//                cout << "Адрес универа: " << mass[j].uniAdress << endl;
//
//                cout << "Минимум по физике: " << mass[j].result.physics << endl;
//
//                cout << "Минимум по математике: " << mass[j].result.math << endl;
//
//                cout << "Минимум по русскому: " << mass[j].result.russian << endl;
//
//                Лера, [15.03.21 10:09]
//                    cout << "Опалата по договору: " << mass[j].price << endl;
//
//                cout << "Специальность(ИСИТ - 1, ПОИТ - 2, ДЭиВИ - 3, ПОИБМС - 4): " << mass[i].spec << endl;
//            }
//            break;
//        case 5: cout << "Выбор специальностей, где проходной балл меньше указанного";
//            int prohBall;
//            cout << "Введите проходной балл: ";
//            cin >> prohBall;
//            cout << "Информация о найденных универах: " << endl;
//            for (int j = 0; j < length; j++)
//            {
//                if ((mass[j].result.physics + mass[j].result.math + mass[j].result.russian) <= prohBall)
//                {
//                    cout << "Название универа: " << mass[j].university << endl;
//
//                    cout << "Адрес универа: " << mass[j].uniAdress << endl;
//
//                    cout << "Минимум по физике: " << mass[j].result.physics << endl;
//
//                    cout << "Минимум по математике: " << mass[j].result.math << endl;
//
//                    cout << "Минимум по русскому: " << mass[j].result.russian << endl;
//
//                    cout << "Опалата по договору: " << mass[j].price << endl;
//
//                    cout << "Специальность(ИСИТ - 1, ПОИТ - 2, ДЭиВИ - 3, ПОИБМС - 4): " << mass[i].spec << endl;
//                }
//            }
//            cout << endl << endl; break;
//        case 6: exit(0); break;
//        default: cout << "Неверный номер операции, повторите попытку." << endl << endl; break;
//        }
//    }
//    return 0;
//}
