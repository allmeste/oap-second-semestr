#include <iostream>

using namespace std;

int* pfmin(int* p[], int n);
int* pfmax(int* p[], int n);

int main()
{

	setlocale(LC_ALL, "rus");
	const int  n = 100;
	int N, raz, r, m;
	cout << "Введите размерность массива" << endl;
	cin >> N;
	int* masB = new int[n];
	for (int i = 0; i < N; i++)
	{
		cout << "Введите элемент" << "[" << i << "]" << endl;
		cin >> masB[i];

	}
	r = *pfmin(&masB, n);
	cout <<r  << endl;
	m = *pfmax(&masB, n);
	cout << m << endl;
	raz = m - r;
	cout << "Разность максимального и минимального элемента рана " << raz << endl;
	return 0;
}
int* pfmin(int* p[], int k)
{
	int i;
	int* pmin;
	pmin = p[0];
	for (i = 0; i < k; i++)
		if (*p[i] < *pmin)
			p[i] = pmin;
	return pmin;
}
int* pfmax(int* p[], int k)
{
	int i;
	int* pmax;
	pmax = p[0];
	for (i = 0; i < k; i++)
		if (*p[i] > * pmax)
			p[i] = pmax;
	return pmax;
}


