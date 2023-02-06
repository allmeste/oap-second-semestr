#include "Hash.h"

using namespace hashTC;

int Object::HashFunction(char* key)  // хэш-функция 
{
	int h, a = 31415, b = 27183;
	for (h = 0; *key != 0; key++, a = a * b % (Size - 1))
		h = (a * h + *key) % Size;
	return (h < 0) ? h + Size : h;
}

Object hashTC::Create(int size, char* (*getkey)(void*)) //создаёт новую хэш-таблицу и возвращает её
{
	return *(new Object(size, getkey)); // выделяет память и возвращает хэш-таблицу
}

void Object::Insert(void* d)
// функция для добавленяи Э-а, передаётся в качестве аргумента сам вставляемый Э-т
{	// сразу получаем ключ из вставляемых данных, рассчитав хэш-функцию получаем позицию для вставки в хэш-таблицу
	char* t = GetKey(d), j = HashFunction(t);
	Data[j].Insert(d); // вызов функции Insert для j-ого списка, d - вставляемые данные
}
// внутри структуры Object, который находится  в пространстве имён hashTC, определяем функцию Search,
// принимающую целочисленный искомый ключ int key и возвращающую У на структуру Э-т из пространства имён listx
listx::Element* Object::Search(char* key) // поиск элемента по ключу
{
	int j = HashFunction(key); // рассчитываем хэш-функцию
							   // вызываем одноименную функцию Search для j-ого списка и передаём в неё искомый ключ и функцию получения ключа из Э-а
	return Data[j].Search(key, GetKey);
}

void Object::Delete(char* key) // удаление по ключам
{
	int j = HashFunction(key);
	Data[j].Delete(key, GetKey);
}

void Object::Scan(void(*f)(listx::Element*)) // принимает функцию вывода Э-а в качестве аргумента
{
	for (int i = 0; i < this->Size; i++) // циклом проодит по всему массиву списков и для каждого списка вызывает одноименную функцию Scan
	{
		std::cout << "Уровень парковки под номером " << i + 1 << ": " << std::endl;
		Data[i].Scan(f);
		std::cout << std::endl; // выводит переход на новую строку
	}
}

