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
    cout << "������� ����� �������: ";
    cin >> size;
    cout << "������� �������� �������: " << endl;;
    cin >> p;
    t->info = p;        //������ �������
    t->next = NULL;
    begin = end = t;
    for (int i = 1; i < size; i++) //�������� �������
    {
        cin >> p;
        create(&begin, &end, p);
    }
    cout << "\n���������� �������\n";
    if (begin == NULL)   //����� �� �����
        cout << "������ �������" << endl;
    else
    {
        view(begin);
    }

    cout << "������� ������: ";
    cin >> etal;
    t = findEtal(begin, etal);

    DelEtal(&begin, &t);   //�������� �� ������������
    cout << "����� �������: \n";
    view(begin);

    return 0;
}