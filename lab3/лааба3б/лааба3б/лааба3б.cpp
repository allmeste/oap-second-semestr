#include<iostream>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    setlocale(LC_ALL, "rus");
    using namespace std;
    FILE* f, *g;
    int a[100], t;
    errno_t  err;
    err=fopen_s(&f, "f.txt", "w");
    if (err != 0)
    {
        perror(" error-f.txt");
        return -1;
    }
    cout << "Введите размер  файла:" << endl;
    int n;
    cin >> n;
    fprintf(f, "%d\t", n);
    cout << "Введите компоненты файла f" << endl;
    int* fl = new int[n];
    for (int i = 1; i <= n; i++) {
        cout  << i <<  " элемент:" ;
        cin >> fl[i];
        fprintf(f, "%d\t", fl[i]);
    }
    fclose(f);
    fopen_s(&f, "f.txt", "r"); // открытие файла для считывания данных
    fopen_s(&g, "g.txt", "w");
    int count = 1;
     t = fl[0];  // певый символ исходного массива будет маркером
    for (int i = 0; i < n; i++)  // перебор всего массива без первого
    {
        if (fl[i] != t)     // если символ не равен маркеру
        {
            for (int j = i + 1; j < n; j++)  // перебор от следующего за рассмотр. символом
                if (fl[i] == fl[j])     // если символы совпали
                    fl[j] = t;       // маркируем повторяющиеся
            count++;            // увеличиваем счётчик
        }
    }
    
    count = 0;
    // теперь удаляем все маркированные элементы
    for (int i = 1; i < n; i++)
    {
        if (fl[i] != fl[0])     
            fl[++count] = fl[i];
        fprintf_s(g, "%d ", fl[i]);
    }

    cout << "Содержимое файла g: ";
    printf("\n");
    // итого
    for (int i = 1; i <= count; i++)
    {
        printf("%d", fl[i]);
    }
       
    
    fclose(f);
    fclose(g);
    return 0;
}
