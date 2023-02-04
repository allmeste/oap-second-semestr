#define MYQUEUE1_EQE  0x0000 
struct Number
{
    int info;
    Number* next;
};
void create(Number** begin, Number** end, int p); //формирование элементов очереди
void view(Number* begin); //функция вывода элементов очереди 
Number* findEtal(Number* begin, int etal); //функция определения минимального элемента 
void DelEtal(Number** begin, Number** p); //функция удаления до минимального элемента 
#pragma once
