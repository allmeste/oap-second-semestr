#include <fstream>
#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int const N = 10;
    int k;
    char ch;
    ofstream f1;
    f1.open("d.txt");

    if (!f1.is_open())
    {
        cout << "Ошибка открытия файла";
    }
    else {
        cout << "Введите строку из нескольких слов " << endl;
        char a[100];
        gets_s(a);
        f1 << a;
        f1.close();

        ifstream f1;
        f1.open("d.txt");
        char buff[50];
        f1.getline(buff, 50); 
        cout << "Файл прочитан" << endl;
        f1.close();

        cout << "Ведите длину первой подстроки k " << endl;
        cin >> k;
        cout << "Две новые подстроки" << endl;
        {
            for (int i = 0; buff[i] != '\0'; i++)
            {
                cout << buff[i];
                if (i == k)
                {
                    cout << endl;
                }
            }
        }
    }
}
