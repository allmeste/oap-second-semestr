#include<iostream>
#include<algorithm>
#include "Heap.h"
using namespace std;

void main() {
	setlocale(LC_CTYPE, "Russian");
	int choice = 0;
	for (;;)
	{
		int n;
		cout << "1 - добавить элемент" << endl;
		cout << "2 - вывод кучи на экран" << endl;
		cout << "3 - удалить максимальный элемент" << endl;
		cout << "4 - Удаление элемента под номером i" << endl;
		cout << "5 - Удаление минимального элемента кучи" << endl;
		cout << "6 - Добавление элемента к второй кучи" << endl;
		cout << "7 - Вывод на экран второй кучи" << endl;
		cout << "8 - Задание слияния второй кучи с первой" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1:  cout << "Введите добавляемое значение :";  cin >> n; insert_elem(n); break;
		case 2:  HeapOut(); break;
		case 3: cout << "Максимальный элемент кучи который был удалён :" << DeleteMax() << endl; break;
		case 4: cout << "Введите номер элемента который хотите удалить :"; cin >> n; cout << "Удалённый элемент под номером " << n << " был " << DeleteI(n) << endl; break;
		case 5: cout << "Значение удалённого минимального элемента :" << DeleteMin() << endl; break;
		case 6:  cout << "Введите добавляемое значение :";  cin >> n; insert_elem1(n); break;
		case 7:PrintHeap1(); break;
		case 8: MergeHeaps(); PrintHeap(); break;
		default:  cout << endl << "Введена неверная команда!" << endl;
		}
	}


	return;
}