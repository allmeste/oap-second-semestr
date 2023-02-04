//#include<iostream> 
//#include<windows.h> 
//using namespace std;
//struct Number
//{
//    int info;
//    Number* next;
//};
//void create(Number** begin, Number** end, int p); //формирование элементов очереди
//void view(Number* begin); //функция вывода элементов очереди 
//Number* findEtal(Number* begin, int etal); //функция определения минимального элемента 
//void DelEtal(Number** begin, Number** p); //функция удаления до минимального элемента 
//int main()
//{
//    setlocale(LC_ALL, "rus");
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    int etal;
//    
//    Number* begin = NULL, * end, * t, *e;
//    t = new Number;
//    int p, size;
//    cout << "Введите длину очереди: ";
//    cin >> size;
//    cout << "Введите элементы очереди: " << endl;;
//    cin >> p;
//    t->info = p;        //первый элемент
//    t->next = NULL;
//    begin = end = t;
//    for (int i = 1; i < size; i++) //создание очереди
//    {
//        cin >> p;
//        create(&begin, &end, p);
//    }
//    cout << "\nПолученная очередь\n";
//    if (begin == NULL)   //вывод на экран
//        cout << "Пустая очередь" << endl;
//    else
//    {
//        view(begin);
//    }
//   
//     cout << "Введите эталон: " ;
//     cin >> etal;
//     t = findEtal(begin, etal);
//    
//     DelEtal(&begin, &t);   //удаление до минимального
//     cout << "Новая очередь: \n";
//     view(begin);
// 
//    return 0;
//}
//void create(Number** begin, Number** end, int p) //Формирование элементов очереди
//{
//    Number* t = new Number;
//    t->next = NULL;
//    if (*begin == NULL)
//        *begin = *end = t;
//    else
//    {
//        t->info = p;
//        (*end)->next = t;
//        *end = t;
//    }
//}
//void view(Number* begin) //Вывод элементов очереди 
//{
//    Number* t = begin;
//    if (t == NULL)
//    {
//        cout << "Пустая очередь\n";
//        return;
//    }
//    else
//        while (t != NULL)
//        {
//            cout << t->info << " ";
//            t = t->next;
//        }
//    cout << endl;
//}
//Number * findEtal(Number* begin,int etal) //Опрделение минимального элемента
//{
//   
//    Number* p = begin, *e=nullptr;
//    int min;
//    if (p == NULL)
//    {
//        cout << "Пустая очередь\n"; 
//    }
//    else
//    {
//     
//        while (p != NULL)
//        {
//            if (p->info == etal)
//            {
//                cout << "Введенный эталон имеется в очереди " << endl;
//                min = p->info;
//                e = p;
//            }
// 
//            p = p->next;
//            
//        }
//    }
//    return e;
//}
//void DelEtal(Number** begin, Number** e) //Удаление до минимального элемента 
//{
//    Number* p;
//    p = new Number;
//    while (*begin != *e)
//    {
//        p = *begin;
//        *begin = (*begin)->next;
//        delete p;
//    }
//}
