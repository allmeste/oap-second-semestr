#define MYQUEUE1_EQE  0x0000 
struct Number
{
    int info;
    Number* next;
};
void create(Number** begin, Number** end, int p); //������������ ��������� �������
void view(Number* begin); //������� ������ ��������� ������� 
Number* findEtal(Number* begin, int etal); //������� ����������� ������������ �������� 
void DelEtal(Number** begin, Number** p); //������� �������� �� ������������ �������� 
#pragma once
