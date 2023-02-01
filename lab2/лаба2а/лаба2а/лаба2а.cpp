#include <iostream> 
#include<math.h>
double metodPr(double(*)(double), double, double, double);    
double f(double); 
double f1(double);

int main()
{
	setlocale(LC_ALL, "rus");
	int a1=1, b1=2, a2=1, b2=3;
	double e=0.001;
	using namespace std;
	double z,y;
	
	cout << "Точность вычислений е=0,001" << endl;
	z = metodPr(f, a1, b1,e);
	y= metodPr(f1, a2, b2, e);
	cout << "Результат1=" << z << endl;
	cout << "Результат2=" << y << endl;
}

double metodPr(double (*fun)(double), double a, double b, double h)
{
	double x, s = 0.0;

	while ( abs(a-b)>(2*h))
	{
		x = (a + b) / 2;
	if( fun(x)*fun(a) <= (2*h))
	{
		b = x;
	}
	else
	{
		a = x;
	}
	}
	return x;
}

double f(double x)
{
	return (pow(2.720,x)+x-4);
}
double f1(double x)
{
	return (pow(x,2)-4);
}

