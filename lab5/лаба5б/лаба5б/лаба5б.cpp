#include<iostream>
#include<Windows.h>
void enter(int size);
void out(int size);
void find(char spc[16]);
void del();
using namespace std;
struct addres {
	char street[30];
	string num;
};
typedef struct Directory {

	string univercity;
	addres uni;
	char speciality[16];
	string score;
	string price;
} DIR;
Directory spec[30];
int choice;
FILE* f;
int main()
{
	char spc[16];
	int n;
	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do {
		cout << "Введите:" << endl;
		cout << "1-для ввода информации и записи в файл " << endl;
		cout << "2-для вывода записи и чтения из файла" << endl;
		cout << "3-для поиска по заданной специальности" << endl;
		cout << "4-для удаления структурной переменной " << endl;
		cout << "5-для выхода" << endl;
		cin >> choice;


		switch (choice)
		{
		case 1:cout << "Ввод информации" << endl;
			cout << "Ведите количество данных" << endl;
			cin >> n;
			enter(n);
		case 2:  out(2);
			continue;
		case 3: cout << "Введите специальность " << endl;
			cin >> spc;
			find(spc); continue;
		case 4:  del(); continue;

		}
	} while (choice != 5);
	return 0;
}
void enter(int size)
{

	DIR buf;
	if (!fopen_s(&f, "t.txt", "ab"))
	{
		for (int i = 0; i < size; i++)
		{
			cout << endl << "Название ВУЗа: ";
			cin >> buf.univercity;
			cout << "Адрес: " << endl;
			cout << "Улица: ";
			cin >> buf.uni.street;
			cout << "Номер дома: ";
			cin >> buf.uni.num;
			cout << "Специальность: ";
			cin >> buf.speciality;
			cout << "Проходной балл за прошлый год: ";
			cin >> buf.score;
			cout << "Стоимость обучения: ";
			cin >> buf.price;
			fwrite(&buf, sizeof(buf), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}
//вывод
void out(int size)
{
	DIR buf;
	if (!fopen_s(&f, "t.txt", "rb"))
	{
		cout << "\nНазвание ВУЗа          Адрес             Специальность    Проходной балл за прошый год    Стоимость обучения\n";
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			for (int i = 0; i < size; i++)
			{
				cout << buf.univercity << "\t            "
					<< buf.uni.street << buf.uni.num << "\t           "
					<< buf.speciality << "\t            "
					<< buf.score << "\t                       "
					<< buf.price << endl;
			}
			fread(&buf, sizeof(buf), 1, f);
		}
		cout << endl;
		fclose(f);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}
void find(char spc[])
{
	bool flag = false;  DIR buf;
	if (!fopen_s(&f, "t.txt", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(spc, buf.speciality) == 0)   //сравнение строк
			{
				cout << "\nВуз      адрес        проходной балл        цена \n";
				cout << buf.univercity << "   " << buf.uni.street << "    " << buf.uni.num << "             " << buf.score << "    " << buf.price << endl;
				flag = true; break;
			}
		}
		fclose(f);
		if (!flag) cout << "Ничего не найдено\n";
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}


void del()
{
	DIR buf;
	int f;
	char spec_del[16];
	cout << "\nСтрукткрированную переменную,которую необходимо удалить  " << endl;
	getchar();
	cin.getline(spec_del, 40);
	for (int i = 0; i < 100; i++) {
		if (buf.speciality[i] == *spec_del) {
			buf.speciality[i] = '/0';
		}
	}
	cout << buf.univercity << "\t            "
		<< buf.uni.street << buf.uni.num << "\t           "
		<< buf.speciality << "\t            "
		<< buf.score << "\t                       "
		<< buf.price << endl;

}
