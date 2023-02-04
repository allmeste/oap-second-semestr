#include <iostream>
#include <windows.h>
#include<fstream>
#include<string>
using namespace std;

struct Stack1 {			//Стуктура элемента стека
	int data;
	Stack1* head;		//Указатель на вершину стека
	Stack1* next;		//Указатель на следующий элемент
};

struct Stack2 {			//Стуктура элемента стека
	int data;
	Stack2* head;		//Указатель на вершину стека
	Stack2* next;		//Указатель на следующий элемент
};

struct Stack {			//Стуктура элемента стека
	int data;
	Stack* head;		//Указатель на вершину стека
	Stack* next;		//Указатель на следующий элемент
};


void push1(int x, Stack1* s1);				//Добавить элемент в стек 1
void push2(int x, Stack2* s2);			//Добавить элемент в стек 2
void Show1(Stack1* s1);					//Вывести стек
void Show2(Stack2* s2);		
void Show3(Stack* s);	//Вывести стек
void file(Stack1* s1, Stack2* s2, Stack* s);
void clean(Stack1* s1, Stack2* s2, Stack s);
void Peek(Stack1* s1, Stack2* s2, Stack* s);


void push1(int x, Stack1* s1)   //Добавление элемента х в стек	
{

	Stack1* e = new Stack1;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле v 
	e->next = s1->head;   //перенос вершины на следующий элемент 
	s1->head = e;
}

void push2(int x, Stack2* s2)   //Добавление элемента х в стек	
{
	

		    //выделение памяти для нового элемента
	Stack2* e = new Stack2;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле v 
	e->next = s2->head;   //перенос вершины на следующий элемент 
	s2->head = e;
	
}


void Show1(Stack1* s1) 
{
	
	                            //Вывод стека 1 на экран
	Stack1* show = s1->head;	//Указатель на вершину стека
	int a;
	if (show == NULL)
		cout << " Стек пуст! \n";
	else
	{
		cout << "Весь стек: \n";
		while (show != NULL)
		{
			a = show->data;
			cout << a << "  ";
			show = show->next;		//Перейти к следующему элементу
		}
	
	}
	
}

void Show2(Stack2* s2) {	//Вывод стека 2 на экран
	Stack2* show = s2->head;	//Указатель на вершину стека
	int a;
	if (show == NULL)
		cout << " Стек пуст! \n";
	else {
		cout << "Весь стек: \n";
		while (show != NULL)
		{
			a = show->data;
			cout << a << "  ";
			show = show->next;		//Перейти к следующему элементу
		}
		
	}
}



void Peek(Stack1*s1, Stack2* s2, Stack* s)
{

	Stack1* p = s1->head;	//Указатель на вершину стека
	Stack2* g = s2->head;
	Stack* c = s->head;
	Stack* e = new Stack;
	int a=0;
	int b=0;
	while (p != NULL)
	{
		while (g != NULL)
		{
			if (s1 && s2)
			{

				int a = p->data;

				int b = g->data;
				if (a == b) {

					
					e->data = a;             //запись элемента x в поле v 
					e->next = s->head;   //перенос вершины на следующий элемент 
					s->head = e;
		
					(g) = (g)->next;
					(p) = (p)->next;

				}
				else {
					(g) = (g)->next;
					(p) = (p)->next;
				}
			}
		}
	}
	cout << "Третий стек создан,для его просмотра нажмите 6 " << endl;
		
}
void Show3(Stack* s) {	//Вывод стека 2 на экран
	Stack* show = s->head;	//Указатель на вершину стека
	int a;
	if (show == NULL)
		cout << " Стек пуст! \n";
	else {
		cout << "Весь стек: \n";
		while (show != NULL)
		{
			a = show->data;
			cout << a << "  ";
			show = show->next;		//Перейти к следующему элементу
		}

	}
}


void clean(Stack1* s1, Stack2* s2, Stack* s) 
{
	Stack1* s1Del = s1;
	while ((s1 ))
	{
		s1Del = s1;
		s1 = s1->next;
		delete s1Del;
	}
	s1 = nullptr;
	cout << "Первый стек удален" << endl;

	Stack2* s2Del = s2;
	while ((s2)) {
		s2Del = s2;
		s2 = s2->next;
		delete s2Del;
	}
	s2 = nullptr;
	cout << "Второй стек удален" << endl;

	Stack* sDel = s;
	while ((s )) {
		sDel = s;
		s = s->next;
		delete sDel;
	}
	s = nullptr;
	cout << "Третий стек удален" << endl;
 }


void file(Stack1* s1, Stack2* s2, Stack* s) {
	ofstream f1;
	f1.open("d1.txt");

	if (!f1.is_open())
	{
		cout << "Ошибка открытия файла";
	}
	else
	{
		Stack1* show = s1->head;	//Указатель на вершину стека
		int a;
		while (show != NULL)
		{
			a = show->data;
			f1 << a;;
			show = show->next;		//Перейти к следующему элементу
		}

	}

	ofstream f2;
	f2.open("d2.txt");

	if (!f2.is_open())
	{
		cout << "Ошибка открытия файла";
	}
	else 
	{
		Stack2* show = s2->head;	//Указатель на вершину стека
		int a;
			while (show != NULL)
			{
				a = show->data;
				f2 << a;;
				show = show->next;		//Перейти к следующему элементу
			}

	}

	ofstream f3;
	f3.open("d3.txt");

	if (!f3.is_open())
	{
		cout << "Ошибка открытия файла";
	}
	else
	{
		Stack* show = s->head;	//Указатель на вершину стека
		int a;
		while (show != NULL)
		{
			a = show->data;
			f3 << a;;
			show = show->next;		//Перейти к следующему элементу
		}

	}
	cout << "Файлы содержащие значения стеков созданы"<<endl;
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice=0,x=0;
	Stack1* s1 = new Stack1;	//выделение памяти для элемента стека
	s1->head = NULL;			//указатель на вершину стека - NULL

	Stack2* s2 = new Stack2;
	s2->head = NULL;

	Stack* s = new Stack;
	s->head = NULL;

	while(choice !=9) {
		cout << " Выберите команду: " << endl;
		cout << "1 - Добавление в Stack1" << endl;
		cout << "2 - Добавление в Stack2" << endl;
		cout << "3 - Вывод Stack1" << endl;
		cout << "4 - Вывод Stack2" << endl;
		cout << "5 - Создание Stack" << endl;
		cout << "6 - Вывод Stack" << endl;
		cout << "7 - запись в файл" << endl;
		cout << "8- удаление стеков" << endl;
		cin >> choice;
	

		switch (choice) {
		case 1: cout << "Введите элемент: " << endl;
			cin >> x;
			push1(x, s1);
			break;						//Добавить элемент в стек
		case 2: cout << "Введите элемент: " << endl;
			cin >> x;
			push2(x, s2);
			break;						//Добавить элемент в стек
		case 3: Show1(s1); break;
		case 4: Show2(s2); break;
		case 5: Peek (s1, s2, s); break;
		case 6:Show3(s); break;//Вывести стек
		case 7: file(s1, s2, s); break;
		case 8:clean(s1, s2, s); 
		}
	}
}

