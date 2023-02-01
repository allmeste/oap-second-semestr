#include <iostream>
int* pfmin(int* p, int n);
int* pfmax(int* p, int n);

void main()
{
	using namespace std;
	setlocale(LC_ALL, "rus");
	const int  n = 100;
	int N, m;
	cout << "Введите размерность массива" << endl;
	cin >> N;
	int* masB= new int[n];
	for (int i = 0; i < N; i++)
	{
		cout << "Введите элемент" << "[" << i << "]" << endl;
		cin >> masB[i];

	}
	int* r = 0;

	cout << *pfmin(masB, N) << endl;
	cout << *pfmax(masB, N) << endl;
	cout << "Разность максимального и минимального элемента рана " << *pfmax(masB, N)- *pfmin(masB, N) << endl;

}
int* pfmin(int* p, int n)
{
	int i=0;
	int* pmin;
	for (pmin = p; i < n; p++,i++)
		if (*p < *pmin)
			pmin = p;
	return pmin;
}

int* pfmax(int* p, int n)
{
	int i=0;
	int* pmax;
	for (pmax = p; i < n; p++, i++)
		if (*p > *pmax)
			pmax = p;;
	return pmax;
}






