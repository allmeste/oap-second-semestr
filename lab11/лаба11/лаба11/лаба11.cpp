#include <iostream>
using namespace std;
float f(float x, float n);
int fact(float a);

void main()
{
	float x, n;
	float b,c;
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите х" << endl;
	cin >> x;
	cout << "Введите n" << endl;
	cin >> n;
	c = f(x, n);
	b = pow(x, n)/fact(c);
	/*cin >> b;*/
	
	
	cout << "Значение выражения  x^n/(n-1)!=" << b;
}

float f(float x, float n)
{
	float c;
	if (n == 0) 
	{
		return 1;
		
	}
	else if (n == 1)
	{
		return x;
	}
	else
	{
		c = x * x / n / (n - 1)*f(x,n-2) ;
		return c;
	}
}

int fact(float a)
{
	if (a > 1)

		return  a * fact(a - 1);
		
	else 
		return 1;
	
}
	


