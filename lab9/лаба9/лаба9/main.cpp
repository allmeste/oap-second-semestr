#include<iostream> 
#include<windows.h> 
#include "names.h"
using namespace std;

struct  Number* head = nullptr;

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int etal;

    Number* begin = NULL, * end, * t, * e;
    t = new Number;
    int p, size;
    cout << "Введите длину очереди: ";
    cin >> size;
    cout << "Введите элементы очереди: " << endl;;
    cin >> p;
    t->info = p;        //первый элемент
    t->next = NULL;
    begin = end = t;
    for (int i = 1; i < size; i++) //создание очереди
    {
        cin >> p;
        create(&begin, &end, p);
    }
    cout << "\nПолученная очередь\n";
    if (begin == NULL)   //вывод на экран
        cout << "Пустая очередь" << endl;
    else
    {
        view(begin);
    }

    cout << "Введите эталон: ";
    cin >> etal;
    t = findEtal(begin, etal);

    DelEtal(&begin, &t);   //удаление до минимального
    cout << "Новая очередь: \n";
    view(begin);

    return 0;
}