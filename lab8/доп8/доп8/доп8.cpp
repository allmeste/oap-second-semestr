#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include<Windows.h>

using namespace std;

struct stack {
	int data;
	stack* next;
};

void main() {
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	void print(stack * p);
	void func(string a);
	void push(stack * &p, int length);

	stack* first = nullptr;
	string a;
	cout << "Введите строку: " ;
	cin >> a;
	cout << "Строка после преобразований: ";
	func(a);
}

void print(stack* p) {
	while (p != nullptr) {
		cout << p->data << "->";
		p = p->next;
	}
	cout << "->nullptr" << endl;
}

void func(string a) {
	if (a.size() % 2 != 0) {
		cout << "Cтрока состоит из нечетного количества символов!" << endl;
		return;
	}
	int length = a.size();
	string firstStr = a.substr(0, length / 2);
	string secondStr = a.substr(length / 2);
	reverse(firstStr.begin(), firstStr.end());
	reverse(secondStr.begin(), secondStr.end());
	cout << firstStr << secondStr << endl;
}

void push(stack*& p, int length)
{
	stack* pv = new stack;
	pv->data = length;
	pv->next = p;
	p = pv;
}