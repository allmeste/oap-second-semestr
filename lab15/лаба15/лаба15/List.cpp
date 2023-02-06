#include "List.h"
using namespace listx;
using namespace std;

bool Object::Insert(void* data)
{
	bool rc = 0;
	if (Head == NULL)
	{
		Head = new Element(NULL, data, Head);
		rc = true;
	}
	else
	{
		Head = (Head->Prev = new Element(NULL, data, Head));
		rc = true;
	}
	return rc;
}
Element* Object::Search(char* key, char* getkey(void*)) // найти заданный
{
	Element* rc = Head; // У на текущий Э-т
	while ((rc != NULL) && (strcmp(getkey(rc->Data), key) != 0)) // пока не дошли до конца и пока не найдём Э-т с искомым ключом														 // rc -> Data берём данные по У-лю на текущий Э-т							 // getkey(rc -> Data) при помощи этой функции получаем ключ из этих данных и далее сравниваем ключ getkey (rc -> Data) != key искомым ключом								 // если ключи не совпадают, то двигаемся дальше
		rc = rc->Next;
	return rc; // возращаем У-ль на найденный Э-т
}
void Object::Scan(void(*f)(Element*)) // проходит по всем Э-там и вызывает функцию f для каждого Э-а
{
	Element* e = Head;
	while (e != NULL)
	{
		f(e); // вместо f передаём в функцию любые другие функции (н-р вывод)
		e = e->GetNext();
	};
}
void Object::Scan(void(*f)(Element*), Element* e)
{
	f(e);
}

bool  Object::Delete(Element* e)    // удалить по У-лю
{
	bool rc = 0;
	if (rc = (e != NULL)) // проверка, чтобы У-лю был не NULL, если он NULL, то удалять нечего
	{
		if (e->Next != NULL) e->Next->Prev = e->Prev;
		// меняет У-ли соседям, если они есть
		if (e->Prev != NULL) e->Prev->Next = e->Next;	// для Э-а который идёт после удаляемого указываем в качестве предыдущего предудыщий от текущего (или от удаляемого)
		else Head = e->Next; // задаём в качестве новой головы следующий за удаляемым
		delete e; // освобождаем память, то есть удаляем Э-т
	}
	return rc; // вовзращаем удалён ли Э-т
}

bool Object::Delete(char* key, char* getkey(void*)) // удалить по значению
{
	return Delete(Search(key, getkey)); // находим Э-т с таким ключом и потом его удаляем
};

Element* Object::GetLast() // получаем У-ль (=ссылку) на последний Э-т
{
	// делаем 2 У-ля, когда первый убежал в нул то второй остался на последнем
	Element* e = Head, * rc = e;
	while (e != NULL)
	{
		rc = e;
		e = e->GetNext();
	};
	return rc;
}
Object Create() // создаёт новый список и возращает его
{
	return *(new Object());
}

