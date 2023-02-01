#include <iostream>
int num(int n, int first, ...);
using namespace std;


void main()
{
	setlocale(LC_ALL, "rus");
	cout << num(6, 4, 4, 1, 2, 3, 3) << endl;
	cout <<  num(5,20,20,2,7,24) << endl;
	cout <<  num(10, 100,42,5,5,6,6,15,25,25,2) << endl;
}

int num(int n, int first, ...)
{
	int* p = &first;
	int num = 0;
	for (int i = 0; i <= n; i++)
	{
		if (p[i] == p[i+1])
		{
			num++;;
		}
	}
	cout << "Количество пар соседних элементов массива с одинаковыми значениями: " ;
	return num;
}



//
//#include <iostream>
//#include<stdarg.h>
//int compr (int n, ...);
//using namespace std;
//
//
//int main()
//{
//	setlocale(LC_CTYPE, "Rus");
//	compr(2, "rkrk rkrk", "str2 lll");
//	/*char m[] = " Test hello ";
//	char k[] = " gjg fggg g ";
//	char mass[]="  ";
//	cout << m << endl;
//	cout << k << endl;
//	*mass = compr(2, m, k);
//	for (int i = 0; mass[i] = '\0'; i++)
//	{
//		cout<<mass[i];
//	}*/
//}
//
//int compr(int n, ...)
//{
//	char* m;
//	va_list other_str;
//	va_start(other_str, n);
//	/*char* c = m;
//	char* a = m;*/
//	for (int i = 0; i < n; i++)
//	{
//		m = va_arg(other_str, char*);
//		for (int j = 0; m[j] != '\0'; j++) {
//			if (m[j] == ' ')
//			{
//				m[j] = m[j + 1];
//			}
//			else
//			{
//				m[j] = m[j];
//			}
//
//		}
//		cout << m[i];
//	}
//	va_end(other_str);
//
//	return m;
//}
////char compr(int n, const char* first, ...)
////{
////	char first1 = first[0];
////	char* ptrstr = &first1;
////	int  i = 0;
////	char b=0, *p=&first1;
////	for (int j = 0; j < n; j++)
////	{
////		while (*ptrstr != '/0')
////		{
//			
//			{
//				if (*ptrstr != ' ')
//					b += *p;
//				p++;
//			}
//
//		}
//		return b;
//	}
//}
