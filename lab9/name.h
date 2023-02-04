#ifndef MY_AWESOME_HEADER_H
#define MY_AWESOME_HEADER_H
struct Stack1 {			//�������� �������� �����
	int data;
	Stack1* head;		//��������� �� ������� �����
	Stack1* next;		//��������� �� ��������� �������
};

struct Stack2 {			//�������� �������� �����
	int data;
	Stack2* head;		//��������� �� ������� �����
	Stack2* next;		//��������� �� ��������� �������
};

struct Stack {			//�������� �������� �����
	int data;
	Stack* head;		//��������� �� ������� �����
	Stack* next;		//��������� �� ��������� �������
};


void push1(int x, Stack1* s1);				//�������� ������� � ���� 1
void push2(int x, Stack2* s2);			//�������� ������� � ���� 2
void Show1(Stack1* s1);					//������� ����
void Show2(Stack2* s2);
void Show3(Stack* s);	//������� ����
void file(Stack1* s1, Stack2* s2, Stack* s);
void clean(Stack1* s1, Stack2* s2, Stack s);
void Peek(Stack1* s1, Stack2* s2, Stack* s);

#endif

