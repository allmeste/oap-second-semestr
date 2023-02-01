#include <iostream> 
#include <stdio.h>
#include <cstdlib>
#include "locale.h"
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Rus");
    FILE* f1, * f2; //указатели на файлы для считывания и записи
    size_t fSizeOfA;  //size_t это unsinged int на 2 байта
    long endPos;
    errno_t err;//Тип errno_t возвращает в переменной err код возникающей при работе с файлом ошибки.

    err = fopen_s(&f1, "A.txt", "w"); // откроем файл для записи исходных знач
    if (err != 0)
    {
        perror("Error-A.txt");//Функция perror() при наличии ошибки выводит строку с сообщением, указанным в параметре функции.
        return -1;
    }

    cout << "Введите размер матрицы:" << endl;
    int n;
    cin >> n;
    fprintf(f1, "%d\t", n);

    int** source = new int* [n];

    for (int i = 0; i < n; i++)//j по строкам, i по столбцам, u число всех ячеек, то есть u=n*n
    {
        source[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cout << "Введите " << i << " " << j << " элемент массива    ";
            cin >> source[i][j];
            fprintf(f1, "%d\t", source[i][j]);
        }
    }

    cout<<endl << "Строки, из значений которых состоит массив документа A.txt\n";
    for (int i = 0; i < n; i++)//j по строкам, i по столбцам, u число всех ячеек, то есть u=n*n
    {
        for (int j = 0; j < n; j++)
        {
            cout << source[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] source[i];
    }
    delete[] source;
    fclose(f1);//закроем файл для открытия в другом режиме
    err = fopen_s(&f1, "A.txt", "r"); // открытие файла для считывания данных
    if (err != 0)
    {
        perror("ошибка открытия A.txt");
        return -1;
    }

    fseek(f1, 0L, SEEK_END); //установка текущей позиции на конец файла

    endPos = ftell(f1); //определение размера содержимого файлов

    fseek(f1, 0L, SEEK_SET); //установка текущей позииции

    if (!fopen_s(&f2, "B.txt", "w"))  //открытие для перезаписи или создание файла B
    {
        int x;
        fscanf_s(f1, "%d", &x);//узнаем размер массива в файле A.txt, в строке 25 кода записывается первое значение в файле и это размер матрицы

        int** arr = new int* [x];
        for (int i = 0; i < x; i++)
        {
            arr[i] = new int[x];
        }

        for (int i = 0; i < x; i++) //считывание данных из файлов в массив
        {
            for (int j = 0; j < x; j++)
            {
                fscanf_s(f1, "%d", &(arr[i][j]));
            }
        }

        cout << "Вывод массива, размер был взят из A.txt\n";
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < x; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Введите столбец для вывода" << endl;
        int k;
        cin >> k;

        for (int i = 0; i < x; i++) //запись данных из массивов в файл в необходимой последовательности
        {
            fprintf_s(f2, "%d ", arr[i][k]);
        }


        for (int i = 0; i < x; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        //освобождение памяти, выделенной для массивов

        cout << "Второй файл, содержащий в себе столбец, был успешно создан  " << std::endl;
    }
    else
    {
        cout << "Error-B.txt" <<endl;
        return -1;
    }
    fclose(f1); //закрытие всех файлов
    fclose(f2);

    return 0;
}
//#include <iostream>
//using namespace std;
//
//void main()
//{
//	setlocale(LC_CTYPE, "Rus");
//	FILE* fAptr, *fBptr; //указатели на файлы для считывания и записи
//	size_t fSizeOfA;
//	long endPos;
//	errno_t err;
//
//	err = fopen_s(&fAptr, "A.bin", "wb"); // откроем файл для записи исходных знач
//	if (err != 0) {
//		perror("ошибка открытия a.bin");
//		return;
//	}
//	cout << "Введите размер матрицы:" << endl; 
//	int n; cin >> n;//загоняется  в исходник значения
//	fprintf(fAptr, "%d\t", n);
//	int* source = new int[n * n];
//	for (int i = 0, u = 0; i < n; i++) {
//		for (int j = 0;j < n; j++, u++) {
//			cout << "Введите " << i + 1 << " " << j + 1 << " элемент массива" << endl;
//			cin >> source[u];
//			fprintf(fAptr, "%d\t", source[u]);
//		}
//	}
//	
//	delete[] source;
//	fclose(fAptr);//закроем файл для открытия в другом режиме
//	err = fopen_s(&fAptr, "A.bin", "r"); // открытие файла для считывания данных
//	if (err != 0) {
//		perror("ошибка открытия a.bin");
//		return;
//	}
//
//	fseek(fAptr, 0L, SEEK_END); //установка текущей позиции на конец файла
//
//	endPos = ftell(fAptr); //определение размера содержимого файлов
//
//	fseek(fAptr, 0L, SEEK_SET); //установка текущей позииции
//
//	if (!fopen_s(&fBptr, "B.txt", "wb")) { //открытие для перезаписи или создание файла B
//		int x;
//		fscanf_s(fAptr, "%d", &x);//узнаем размер массива
//		int** arr = new int* [x];
//		for (int i = 0; i < x; i++)
//			arr[i] = new int[x];
//		for (int u = 0; u < x; u++) //считывание данных из файлов в массив
//			for (int i = 0; i < x; i++) {
//				fscanf_s(fAptr, "%d", &(arr[u][i]));
//			}	
//		for (int g = 0; g < x; g++) {
//			for (int i = 0; i < x; i++) {
//				cout << arr[g][i] << " ";
//			}
//			cout << endl;
//		}
//		cout << "Введите столбец для вывода" << endl;
//		int k; cin >> k;
//
//		for (int i = 0; i < x; i++) { //запись данных из массивов в файл d в необходимой последовательности
//			fprintf_s(fBptr, "%d ", arr[i][k]);
//		}
//		fclose(fAptr); //закрытие всех файлов
//		fclose(fBptr);
//
//		delete[] arr; //освобождение памяти, выделенной для массивов
//
//		cout << "Файл был успешно создан" << std::endl;
//	}
//	else {
//		cout << "Ошибка создания файла" << std::endl;
//		return;
//	}
//	system("pause");
//}