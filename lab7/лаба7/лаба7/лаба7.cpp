#include <iostream>
#include<fstream>

using namespace std;
struct list
{
    int number;
    list* next;
};

void insert(list*&, float); //функция добавления элемента, передается адрес списка и символ, который добавляется 
float del(list*&, float);   //функция удаления, передается адрес списка и символ, который удаляется 
int IsEmpty(list*);         //функция, которая проверяет, пуст ли список
void printList(list*);      //функция вывода
void menu(void);  
void search(list* p);
void sum(list*);  
void  toFile(list*& p);
void  fromFile(list*& p);
int main()
{
    setlocale(LC_CTYPE, "Russian");
    list* first = NULL;
   
    int choice,n;
    float value;
    menu(); 
    cout << "Выбор: ";// вывести меню 
    cin >> choice;
    while (choice != 8)
    {
        switch (choice)
        {
        case 1: 
            cout << "Введите число "; // добавить число в список
            cin >> value;
            insert(first, value);
            cout << "Для повторного ввода введите 1" << endl;
            break;
        case 2:
            if (!IsEmpty(first)) // удалить число из списка
        {
            cout << "Введите удаляемое число ";
            cin >> value;
            if (del(first, value))
            {
                cout << "Удалено число " << value << endl;
            }
            else
                cout << "Число не найдено" << endl;
        }
              else
            cout << "Список пуст" << endl;
            break;
         case 3:
             search(first);
             break;
        case 4:
            printList(first);
            break;
        case 5:
            toFile(first);
            break;
        case 6:
            fromFile(first);
            break;
        case 7:
            sum(first);
            break;
        }

        cout << "Выбор: " ;
        cin >> choice;
    }
    return 0;
}

void menu(void)  //Вывод меню 
{
    cout << "Сделайте выбор:" << endl;
    cout << " 1 - Ввод числа" << endl;
    cout << " 2 - Удаление числа" << endl;
    cout << " 3 - Поиск элемента" << endl;
    cout << " 4 - Вывод в консольное окно" << endl;
    cout << " 5 - Запись в файл" << endl;
    cout << " 6 - Считывание из файла" << endl;
    cout << " 7 - Cумма отрицательных элементов, кратных 5" << endl;
    cout << " 8 - Выход" << endl;
}
void insert(list*& p, float value) //Добавление числа value в список 
{
    list* newP = new list;
    if (newP != NULL)     //есть ли место?  
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}
float del(list*& p, float value)  // Удаление числа 
{
    list* previous, * current, * temp;
    if (value == p->number)
    {
        temp = p;
        p = p->next;    // отсоединить узел 
        delete temp;      //освободить отсоединенный узел 
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value)
        {
            previous = current;
            current = current->next; // перейти к следующему 
        }
        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;
            delete(temp);
            return value;
        }
    }
    return 0;
}
int IsEmpty(list* p) //Список  пустой? (1-да, 0-нет) 
{
    return p == NULL;
}
void printList(list* p)  //Вывод списка 
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}
void  toFile(list* &p)
{
    list* temp = p;
    list buf;
    ofstream f1;
    f1.open("t.dat");
    if  (!f1.is_open())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (temp)
    {
        buf = *temp;
        f1.write((char*)&buf, sizeof(list));
        temp = temp->next;
    }
    f1.close();
    cout << "Список записан в файл t.dat\n";
}
void fromFile(list*& p)          //Считывание из файла
{
    list buf, * first = nullptr;
    ifstream f2("t.dat");
    if (!f2.is_open())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    f2.read((char*)&buf, sizeof(list));
    while (!f2.eof())
    {
        insert(first, buf.number);
        cout << "-->" << buf.number;
        f2.read((char*)&buf, sizeof(list));
    }
    cout << "-->NULL" << endl;
    f2.close();
    p = first;
    cout << "\nСписок считан из файла t.dat\n";
}
void sum(list* p)    
{
    float sm = 0;
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number < 0 && p->number % 5 == 0)
            {
                    sm = sm + (p->number);
                    p = p->next;
            }
            else {
                p = p->next;
            }
        }
        cout << "Сумма = " << sm << endl;
    }
}
void search(list* p)  
{
    int n;
    cout << "Введите элемент для поиска" << endl;
    cin >> n;
    if (p == NULL)
        cout << "Список пуст" << endl;
    else 
    {
        while (p != NULL)
        {
            if (p->number == n)
            {
                cout << "Заданный элемент найден в списке" << endl;
                p = p->next;
            }
            else {
                p = p->next;
            }
        }
    }
}

