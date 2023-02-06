#include<iostream>
#include<conio.h> 
using namespace std;

struct Node {
    int key;
    Node* left, * right;
};

/* utility that allocates a new Node with the given key  */
Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}
Node* root = nullptr;
/* Function to find sum of all the elements*/
int addBT(Node* root)
{
    if (root == NULL)
        return 0;
    return (root->key + addBT(root->left) + addBT(root->right));
}

    void insert(int a, Node** t)  //Добавление элемента a 
    {
    	if ((*t) == NULL)              //если дерева нет, то создается элемент
    	{
    		(*t) = new Node;
    		(*t)->key = a;
    		(*t)->left = (*t)->right = NULL;
    		return;
    	}
    	if (a > (*t)->key)  //дерево есть, если а больше текущего
    		insert(a, &(*t)->right);  //то элемент помещается вправо
    	else
    		insert(a, &(*t)->left);   //иначе - влево
    }
    
    void print(Node* t, int u)    //Вывод на экран
    {
    	if (t == NULL)  return;
    	else
    	{
    		print(t->left, ++u);     //левое поддерево
    		for (int i = 0; i < u; ++i)
    			cout << "|";
    		cout << t->key << endl;
    		u--;
    	}
    	print(t->right, ++u);          // правое поддерево
    }
/* Driver program to test above functions*/
int main()
{
    setlocale(LC_CTYPE, "Russian");
    int count, temp;
    	cout << "Введите количество элементов  "; cin >> count;
    	for (int i = 0; i < count; ++i)
    	{
    		cout << "Введите число  ";	cin >> temp;
    		insert(temp, &root);
    	}
    	cout << "ваше дерево\n";
    	print(root, 0);
    	_getch();
    int sum = addBT(root);
    float asum = sum / count;
    cout << "Среднее арифметическое всех элементов дерева " << asum << endl;
    return 0;
}


//#include <iostream>
//#include<conio.h>  
//using namespace std;
//struct Node
//{
//	int data;             //Информационное поле
//	Node* left, * right;   //Указатели на левую и правую ветви дерева
//};
//Node* root = nullptr;
//
//void insert(int a, Node** t)  //Добавление элемента a 
//{
//	if ((*t) == NULL)              //если дерева нет, то создается элемент
//	{
//		(*t) = new Node;
//		(*t)->data = a;
//		(*t)->left = (*t)->right = NULL;
//		return;
//	}
//	if (a > (*t)->data)  //дерево есть, если а больше текущего
//		insert(a, &(*t)->right);  //то элемент помещается вправо
//	else
//		insert(a, &(*t)->left);   //иначе - влево
//}
//
//void print(Node* t, int u)    //Вывод на экран
//{
//	if (t == NULL)  return;
//	else
//	{
//		print(t->left, ++u);     //левое поддерево
//		for (int i = 0; i < u; ++i)
//			cout << "|";
//		cout << t->data << endl;
//		u--;
//	}
//	print(t->right, ++u);          // правое поддерево
//}
//int sum(Node* t, int u) //Подсчет количества слов
//{
//	int summ1, summ2;
//	if (t == NULL)  return;
//	else
//	{
//	  summ1=0, summ2=0;
//	  summ1 = sum(t->left, ++u);  //левое поддерево
//	  summ1+= sum(t->left, ++u);
//		for (int i = 0; i < u; ++i)
//			summ1 += t->data;
//		u--;
//       summ2 = sum(t->right, ++u);
//	   summ2+= sum(t->right, ++u);
//	}
//	 
//	return summ1 + summ2;
//}
//
//void main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	int count, temp;
//	cout << "Введите количество элементов  "; cin >> count;
//	for (int i = 0; i < count; ++i)
//	{
//		cout << "Введите число  ";	cin >> temp;
//		insert(temp, &root);
//	}
//	cout << "ваше дерево\n";
//	print(root, 0);
//	_getch();
//	//cout << "Среднее арифметическое дерава " << sum(tree) / count << endl;
//	
//}
//
