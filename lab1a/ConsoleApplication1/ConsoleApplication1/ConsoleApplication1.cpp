#include <iostream>
int* pfmin(int* p, int n);
int* pfmax(int* p, int n);

void main()
{
	using namespace std;
	setlocale(LC_ALL, "rus");
	int N, raz, r, m;
	cout << "Введите размерность массива" << endl;
	cin >> N;
	int* masB = new int[N];
	for (int i = 0; i < N; i++)
	{
		cout << "Введите элемент[" << i << "]" << endl;
		cin >> masB[i];
	}
	*pfmin(masB, N);
	r = *pfmin(masB, N);
	cout << *pfmin(masB, N) << endl;
	*pfmax(masB, N);
	m = *pfmax(masB, N);
	cout << *pfmax(masB, N) << endl;
	raz = m - r;
	cout << "Разность максимального и минимального элемента рана " << raz << endl;

}
int* pfmin(int* p, int k)
{
	int* pmin;
	
	for (pmin = p; k > 0; p++, k--)
		if (*p < *pmin)
			pmin = p;
	return pmin;

}
int* pfmax(int* p, int k)
{

	int* pmax;
	for (pmax = p; k > 0; p++, k--)
		if (*p < *pmax)
			pmax = p;
	return pmax;
}



