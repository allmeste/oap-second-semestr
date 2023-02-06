#include <iostream>
using namespace std;
float f(float x, float n);


void main()
{
	float m, n;
	float c;
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите m" << endl;
	cin >> m;
	cout << "Введите n" << endl;
	cin >> n;
	if (n >= 0)
		c = f(m, n);
	else
		cout << "n является отрицательным";
	cout << "Значение функции " << c;
}

float f(float x, float n)
{
	float c;
	if (n == 0)
	{
		return 1;

	}
	else if (n < 1)
	{
		return -1;
	}
	else
	{
		c = 2*f(n-1,x);
		return c;
	}
}





