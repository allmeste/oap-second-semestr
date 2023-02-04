#include <iostream>
#include <windows.h>
#include<fstream>
#include<string>
#include "Header.h"

using namespace std;

struct Stack1* s1 = nullptr;
struct Stack2* s2 = nullptr;
struct Stack* s = nullptr;
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice = 0, x = 0;
	Stack1* s1 = new Stack1;	//выделение памяти для элемента стека
	s1->head = NULL;			//указатель на вершину стека - NULL

	Stack2* s2 = new Stack2;
	s2->head = NULL;

	Stack* s = new Stack;
	s->head = NULL;

	while (choice != 9) {
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
		case 5: Peek(s1, s2, s); break;
		case 6:Show3(s); break;//Вывести стек
		case 7: file(s1, s2, s); break;
		case 8:clear1(s1) ,clear2(s2), clear3(s);
		case 9: exit(0);
		}
	}
}
