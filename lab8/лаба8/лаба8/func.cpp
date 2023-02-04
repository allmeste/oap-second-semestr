#include <iostream>
#include <windows.h>
#include<fstream>
#include<string>
#include "name.h"
#include "stdafx.h"
using namespace std;
void push1(int x, Stack1* s1)   //���������� �������� � � ����	
{

	Stack1* e = new Stack1;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� v 
	e->next = s1->head;   //������� ������� �� ��������� ������� 
	s1->head = e;
}

void push2(int x, Stack2* s2)   //���������� �������� � � ����	
{


	//��������� ������ ��� ������ ��������
	Stack2* e = new Stack2;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� v 
	e->next = s2->head;   //������� ������� �� ��������� ������� 
	s2->head = e;

}


void Show1(Stack1* s1)
{

	//����� ����� 1 �� �����
	Stack1* show = s1->head;	//��������� �� ������� �����
	int a;
	if (show == NULL)
		cout << " ���� ����! \n";
	else
	{
		cout << "���� ����: \n";
		while (show != NULL)
		{
			a = show->data;
			cout << a << "  ";
			show = show->next;		//������� � ���������� ��������
		}

	}

}

void Show2(Stack2* s2) {	//����� ����� 2 �� �����
	Stack2* show = s2->head;	//��������� �� ������� �����
	int a;
	if (show == NULL)
		cout << " ���� ����! \n";
	else {
		cout << "���� ����: \n";
		while (show != NULL)
		{
			a = show->data;
			cout << a << "  ";
			show = show->next;		//������� � ���������� ��������
		}

	}
}



void Peek(Stack1* s1, Stack2* s2, Stack* s)
{

	Stack1* p = s1->head;	//��������� �� ������� �����
	Stack2* g = s2->head;
	Stack* c = s->head;
	Stack* e = new Stack;
	int a = 0;
	int b = 0;
	while (p != NULL)
	{
		while (g != NULL)
		{
			if (s1 && s2)
			{

				int a = p->data;

				int b = g->data;
				if (a == b) {


					e->data = a;             //������ �������� x � ���� v 
					e->next = s->head;   //������� ������� �� ��������� ������� 
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
	cout << "������ ���� ������,��� ��� ��������� ������� 6 " << endl;

}
void Show3(Stack* s) {	//����� ����� 2 �� �����
	Stack* show = s->head;	//��������� �� ������� �����
	int a;
	if (show == NULL)
		cout << " ���� ����! \n";
	else {
		cout << "���� ����: \n";
		while (show != NULL)
		{
			a = show->data;
			cout << a << "  ";
			show = show->next;		//������� � ���������� ��������
		}

	}
}


void clean(Stack1* s1, Stack2* s2, Stack* s)
{
	Stack1* s1Del = s1;
	while ((s1))
	{
		s1Del = s1;
		s1 = s1->next;
		delete s1Del;
	}
	s1 = nullptr;
	cout << "������ ���� ������" << endl;

	Stack2* s2Del = s2;
	while ((s2)) {
		s2Del = s2;
		s2 = s2->next;
		delete s2Del;
	}
	s2 = nullptr;
	cout << "������ ���� ������" << endl;

	Stack* sDel = s;
	while ((s)) {
		sDel = s;
		s = s->next;
		delete sDel;
	}
	s = nullptr;
	cout << "������ ���� ������" << endl;
}


void file(Stack1* s1, Stack2* s2, Stack* s) {
	ofstream f1;
	f1.open("d1.txt");

	if (!f1.is_open())
	{
		cout << "������ �������� �����";
	}
	else
	{
		Stack1* show = s1->head;	//��������� �� ������� �����
		int a;
		while (show != NULL)
		{
			a = show->data;
			f1 << a;;
			show = show->next;		//������� � ���������� ��������
		}

	}

	ofstream f2;
	f2.open("d2.txt");

	if (!f2.is_open())
	{
		cout << "������ �������� �����";
	}
	else
	{
		Stack2* show = s2->head;	//��������� �� ������� �����
		int a;
		while (show != NULL)
		{
			a = show->data;
			f2 << a;;
			show = show->next;		//������� � ���������� ��������
		}

	}

	ofstream f3;
	f3.open("d3.txt");

	if (!f3.is_open())
	{
		cout << "������ �������� �����";
	}
	else
	{
		Stack* show = s->head;	//��������� �� ������� �����
		int a;
		while (show != NULL)
		{
			a = show->data;
			f3 << a;;
			show = show->next;		//������� � ���������� ��������
		}

	}
	cout << "����� ���������� �������� ������ �������" << endl;
}
