#include<iostream> 
#include<windows.h> 
#include "names.h"
using namespace std;
void create(Number** begin, Number** end, int p) //Формирование элементов очереди
{
    Number* t = new Number;
    t->next = NULL;
    if (*begin == NULL)
        *begin = *end = t;
    else
    {
        t->info = p;
        (*end)->next = t;
        *end = t;
    }
}
void view(Number* begin) //Вывод элементов очереди 
{
    Number* t = begin;
    if (t == NULL)
    {
        cout << "Пустая очередь\n";
        return;
    }
    else
        while (t != NULL)
        {
            cout << t->info << " ";
            t = t->next;
        }
    cout << endl;
}
Number* findEtal(Number* begin, int etal) //Опрделение минимального элемента
{

    Number* p = begin, * e = nullptr;
    int min;
    if (p == NULL)
    {
        cout << "Пустая очередь\n";
    }
    else
    {

        while (p != NULL)
        {
            if (p->info == etal)
            {
                cout << "Введенный эталон имеется в очереди " << endl;
                min = p->info;
                e = p;
            }

            p = p->next;

        }
    }
    return e;
}
void DelEtal(Number** begin, Number** e) //Удаление до минимального элемента 
{
    Number* p;
    p = new Number;
    while (*begin != *e)
    {
        p = *begin;
        *begin = (*begin)->next;
        delete p;
    }
}
