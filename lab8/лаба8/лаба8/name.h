#ifndef MY_AWESOME_HEADER_H
#define MY_AWESOME_HEADER_H
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

#endif

