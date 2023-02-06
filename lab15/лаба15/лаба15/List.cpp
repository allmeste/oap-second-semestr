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
Element* Object::Search(char* key, char* getkey(void*)) // ����� ��������
{
	Element* rc = Head; // � �� ������� �-�
	while ((rc != NULL) && (strcmp(getkey(rc->Data), key) != 0)) // ���� �� ����� �� ����� � ���� �� ����� �-� � ������� ������														 // rc -> Data ���� ������ �� �-�� �� ������� �-�							 // getkey(rc -> Data) ��� ������ ���� ������� �������� ���� �� ���� ������ � ����� ���������� ���� getkey (rc -> Data) != key ������� ������								 // ���� ����� �� ���������, �� ��������� ������
		rc = rc->Next;
	return rc; // ��������� �-�� �� ��������� �-�
}
void Object::Scan(void(*f)(Element*)) // �������� �� ���� �-��� � �������� ������� f ��� ������� �-�
{
	Element* e = Head;
	while (e != NULL)
	{
		f(e); // ������ f ������� � ������� ����� ������ ������� (�-� �����)
		e = e->GetNext();
	};
}
void Object::Scan(void(*f)(Element*), Element* e)
{
	f(e);
}

bool  Object::Delete(Element* e)    // ������� �� �-��
{
	bool rc = 0;
	if (rc = (e != NULL)) // ��������, ����� �-�� ��� �� NULL, ���� �� NULL, �� ������� ������
	{
		if (e->Next != NULL) e->Next->Prev = e->Prev;
		// ������ �-�� �������, ���� ��� ����
		if (e->Prev != NULL) e->Prev->Next = e->Next;	// ��� �-� ������� ��� ����� ���������� ��������� � �������� ����������� ���������� �� �������� (��� �� ����������)
		else Head = e->Next; // ����� � �������� ����� ������ ��������� �� ���������
		delete e; // ����������� ������, �� ���� ������� �-�
	}
	return rc; // ���������� ����� �� �-�
}

bool Object::Delete(char* key, char* getkey(void*)) // ������� �� ��������
{
	return Delete(Search(key, getkey)); // ������� �-� � ����� ������ � ����� ��� �������
};

Element* Object::GetLast() // �������� �-�� (=������) �� ��������� �-�
{
	// ������ 2 �-��, ����� ������ ������ � ��� �� ������ ������� �� ���������
	Element* e = Head, * rc = e;
	while (e != NULL)
	{
		rc = e;
		e = e->GetNext();
	};
	return rc;
}
Object Create() // ������ ����� ������ � ��������� ���
{
	return *(new Object());
}

