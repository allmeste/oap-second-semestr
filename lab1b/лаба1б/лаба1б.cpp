#include <iostream>
int* fun(int** B, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((j == 1) && (i >= 0 && i < m))
            {
                if (B[i][j] > 0)
                {
                    B[i][j - 1] = -(B[i][j - 1]);
                }
            }
        }
    }
    return *B;
}
int main()
{
    using namespace std;
    setlocale(LC_ALL, "rus");
    int n, m, i, k;
    cout << "Ведите размерность матицы:" << endl;
    cout << "Количество строк  " ;
    cin >> n;
    cout << "Количество столбцов ";
    cin >> m;
    int** A = new int* [n];
    for (int i = 0; i < n; ++i)
        A[i] = new int[m];
    cout << "Введите элементы матрицы " << endl;;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "a[" << i << "][" << j << "]  ";
            cin >> A[i][j];
        }
    }
    cout << "Исходная матрица" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    fun(A, n, m);
    cout << "Новая матрица" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    delete[] A;
    return 0;
}




