
#include <iostream>  
#include <string.h>  
#include <fstream>

using namespace std;

int main()
{
    //ofstream-буду записывать в файл
    //ifstream-буду читать файл
    //fstream fille("ourFille.txt", ios::in);//чтобы брать данные для чтения
    setlocale(LC_ALL, "RUS");
    ofstream fin;
    int row = 0, col = 0, k, i, j, length, count;
    char string1[] = " a first str first aaan ";
    char string2[] = "second stra second second aan";
    char string3[] = "third str a ";

    char words1[100][100];
    char words2[100][100];
    char words3[100][100];

    char buffer1[100] = "\0";
    char buffer2[100] = "\0";
    char buffer3[100] = "\0";

    fin.open("t1.txt");
    if (!fin.is_open())
    {
        cout << "Ошибка cоздания файла";
    }
    else
    {
        fin << string1 << endl << string2 << endl << string3 << endl;
    }
    fin.close();

    ifstream fout;
    fout.open("t1.txt");
    if (!fout.is_open())
    {
        cout << "Ошибка открытия файла";
    }
    else
    {
        //---------------------------------ДЛЯ СТРОКИ 1------------------------------------------------
        //разделить предложение на слова, которые отдельно запишутся в каждую строку двумерного массива

        for (k = 0; string1[k] != '\0'; k++)
        {

            if (string1[k] != ' ' && string1[k] != '\0')
            {
                //записывает все символы до пробела или до конца строки в двумерный массив
                words1[row][col++] = string1[k];//i-кол-во строк, j-кол-во символов каждой строки
            }
            else
            {
                words1[row][col] = '\0';
                //переходим на новую строку
                row++;
                //столбцы этой строки начинаются с 0
                col = 0;
            }

        }
        words1[row][col] = '\0';//добавляем нулевой символ к последней строке двумерного массива

        //хранит число строк
        length = row + 1;

        //чтобы сравнить 0 строку с 1..length-1 строками в двумерном массиве
        bool flag = true;
        for (i = 0; i < length && flag == true; i++)
        {
            count = 1;
            for (j = i + 1; j < length && flag == true; j++)
            {

                //i по строкам, j по символам строки
                if (strcmp(words1[i], words1[j]) == 0) // strcmp(words[i], words[j]) == 0 если строки равны, зайдет в if только если слово повторяется хотя бы второй раз
                {
                    count++;
                    //устанавливает в words[j] 0 чтобы избежать печатания одинковых слов несколько раз

                    strcpy_s(words1[j], "0");//вместо тех слов, которые уже встречались, запишутся ноли  

                    for (int m = 0; string1[m] != '\0'; m++)
                    {
                        buffer1[m] = string1[m];
                    }
                    flag = false;//если хотя бы 1 раз вместо повторяющегося слова запишется 0 в двумерный массив, то выйдет сразу из for-for-if
                }
            }
        }




        //---------------------------------ДЛЯ СТРОКИ 2------------------------------------------------
   //разделить предложение на слова, которые отдельно запишутся в каждую строку двумерного массива
        row = 0;
        col = 0;
        for (k = 0; string2[k] != '\0'; k++)
        {

         
                if (string2[k] != ' ' && string2[k] != '\0')
                {
                    //записывает все символы до пробела или до конца строки в двумерный массив
                    words2[row][col++] = string2[k];//i-кол-во строк, j-кол-во символов каждой строки
                }
                else
                {
                    words2[row][col] = '\0';
                    //переходим на новую строку
                    row++;
                    //столбцы этой строки начинаются с 0
                    col = 0;
                }

        }
        words2[row][col] = '\0';//добавляем нулевой символ к последней строке двумерного массива

        //хранит число строк
        length = row + 1;

        //чтобы сравнить 0 строку с 1..length-1 строками в двумерном массиве
        flag = true;
        for (i = 0; i < length && flag == true; i++)
        {
            count = 1;
            for (j = i + 1; j < length && flag == true; j++)
            {

                //i по строкам, j по символам строки
                if (strcmp(words2[i], words2[j]) == 0) // strcmp(words[i], words[j]) == 0 если строки равны, зайдет в if только если слово повторяется хотя бы второй раз
                {
                    count++;
                    //устанавливает в words[j] 0 чтобы избежать печатания одинковых слов несколько раз
                    strcpy_s(words2[j], "0");//вместо тех слов, которые уже встречались, запишутся ноли  

                    for (int m = 0; string2[m] != '\0'; m++)
                    {
                        buffer2[m] = string2[m];
                    }
                    flag = false;//если хотя бы 1 раз вместо повторяющегося слова запишется 0 в двумерный массив, то выйдет сразу из for-for-if
                }
            }
        }


        //---------------------------------ДЛЯ СТРОКИ 3------------------------------------------------
  //разделить предложение на слова, которые отдельно запишутся в каждую строку двумерного массива
        row = 0;
        col = 0;
        for (k = 0; string3[k] != '\0'; k++)
        {

            if (string3[k] != ' ' && string3[k] != '\0')
            {
                //записывает все символы до пробела или до конца строки в двумерный массив
                words3[row][col++] = string3[k];//i-кол-во строк, j-кол-во символов каждой строки
            }
            else
            {
                words3[row][col] = '\0';
                //переходим на новую строку
                row++;
                //столбцы этой строки начинаются с 0
                col = 0;
            }

        }
        words3[row][col] = '\0';//добавляем нулевой символ к последней строке двумерного массива

        //хранит число строк
        length = row + 1;

        //чтобы сравнить 0 строку с 1..length-1 строками в двумерном массиве
        flag = true;
        for (i = 0; i < length && flag == true; i++)
        {
            count = 1;
            for (j = i + 1; j < length && flag == true; j++)
            {

                //i по строкам, j по символам строки
                if (strcmp(words3[i], words3[j]) == 0) // strcmp(words[i], words[j]) == 0 если строки равны, зайдет в if только если слово повторяется хотя бы второй раз
                {
                    count++;
                    //устанавливает в words[j] 0 чтобы избежать печатания одинковых слов несколько раз
                    strcpy_s(words3[j], "0");//вместо тех слов, которые уже встречались, запишутся ноли

                
                        for (int m = 0; string3[m] != '\0'; m++)
                        {
                            buffer3[m] = string3[m];
                        }

                    flag = false;//если хотя бы 1 раз вместо повторяющегося слова запишется 0 в двумерный массив, то выйдет сразу из for-for-if
                }
            }
        }
    }
    fout.close(); //Закрываем файл

    ofstream finn;
    finn.open("t2.txt");
    if (!finn.is_open())
    {
        cout << "Ошибка открытия файла";
    }
    else
    {
        finn << buffer1 << endl;
        finn << buffer2 << endl;
        finn << buffer3 << endl;
    }
    finn.close();


    char stringNumbers[] = "alla avoid bad mood";
    int numbersCounter = 0;
    int numberOfWord = 0;
    int thenumberOfWordOfMaxFiguresInIt = 0;
    int max = numbersCounter;
    int buf[2];

    fin.open("t1.txt", ios::app);
    if (!fin.is_open())
    {
        cout << "Ошибка cоздания файла";
    }
    else
    {
        fin << stringNumbers << endl;
    }
    fin.close();

    fout.open("t1.txt");
    for (int k = 0; stringNumbers[k] != '\0'; k++)
    {
        if (stringNumbers[k] == 'a')
        {
            numbersCounter++;
        }
        if (stringNumbers[k] == ' ' || stringNumbers[k + 1] == '\0')
        {
            numberOfWord++;
            if (numbersCounter >= max)
            {
                max = numbersCounter;
                thenumberOfWordOfMaxFiguresInIt = numberOfWord;
            }
            numbersCounter = 0;
        }
    }

    buf[0] = thenumberOfWordOfMaxFiguresInIt;
    buf[1] = max;


    finn.open("t2.txt", ios::app);
    if (!finn.is_open())
    {
        cout << "Ошибка";
    }
    else
    {
        finn << "Номер слова с больим количеcтвом букв 'a' " << '\t';
        finn << buf[0] << '\n';
        finn << "Количество букв 'a' в этом слове" << '\t';
        finn << buf[1] << '\n';
    }
    return 0;
}


//#include <fstream>
//#include <iostream>
//#include< string>
//int main()
//{
//    using namespace std;
//    setlocale(LC_ALL, "rus");
//    char buff[100];
//    ofstream f1;
//    char a[100] = "First string";
//    char b[100] = "Second string";
//    char c[100] = "Third string";
//    f1.open("t.txt");
//    if (!f1.is_open())
//    {
//        cout << "Ошибка cоздания файла";   
//    }
//    else{ 
//        
//        f1 << a <<'\n'<< b << '\n' << c;
//        
//   }
//    f1.close();
//
//    ifstream fin;
//    fin.open("t.txt");
//    if (!fin.is_open())
//    {
//        cout << "Ошибка открытия файла";
//    }
//    else
//    {
//        const int len = 30, strings = 3;
//        const char ch = '\n';
//        char mass[len][strings];
//        cout << "Строки из первго файла:" << endl;
//        ifstream fs("t.txt");
//
//        if (!fs) return 1;
//
//        for (int r = 0; r < strings; r++)
//        {
//            fs.getline(mass[r], len - 1, ch); //Считываем строки в массив
//            cout << mass[r] << endl; //Выводи строку из массива
//        }
//
//
//
//        fs.close(); //Закрываем файл
//        return 0;
//    }
       //  fin.getline(buff, 100);
       // 
       //
     
       // for (int r = 0; r < strings; r++)
       //{
       //    fin.getline(mass[r], len - 1, ch); //Считываем строки в массив
       //    cout << "String " << r + 1 << " = " << mass[r] << endl;

       //}
       //fin.close();
       //for(int i=0; i<3;i++)
       //cout << buff << endl;
    
  
  










//#include<iostream>
//#include<fstream>
//
//int main()
//{
//  //копирование из файла F1 в файл F2 строк, которые содержат не менее двух одинаковых слов
//    ifstream is("f1_first.txt");
//    ofstream os("f2_first.txt");
//    if (!is || !os) return 1;
//    string str, word;
//    unordered_set<string> uset;
//    while (getline(is, str)) {
//        uset.clear();
//        stringstream ss(str);
//
//        while (ss >> word) {
//            if (!uset.insert(word).second) {
//                os << str << '\n';
//                break;
//            }
//        }
//    }
//    is.close();
//    os.close();
//    //Определяем номер слова, в котором больше всего цифр
//    ifstream isss("f1_first.txt");
//    string str1;
//    while (getline(isss, str1)) {
//        string s, word, mostDig, mostLet;
//        int i, count_letters, count_digits, max_letters = 0, max_digits = 0;
//        stringstream words(str1);
//        while (isss >> word) {
//            i = 0;
//            count_letters = 0;
//            count_digits = 0;
//            while (word[i])
//            {
//                if (word[i] >= 'a') count_digits++;
//               
//                i++;
//            }
//            if (count_digits > max_digits) { max_digits = count_digits;}
//          
//        }
//        cout << "Word with max digits: " << mostDig;
//    }
//    return 0;
//}
//
//
//
//
////


//
//#include <iostream>
//#include <unordered_set>
//#include <string>
//#include <fstream>
//#include <sstream>
//
//int main()
//{
//    std::ifstream is("input.txt");
//    std::ofstream os("output.txt");
//    if (!is || !os) return 1;
//    std::string str, word;
//    std::unordered_set<std::string> uset;
//
//    while (std::getline(is, str)) {
//        uset.clear();
//        std::stringstream ss(str);
//
//        while (ss >> word) {
//            if (!uset.insert(word).second) {
//                os << str << '\n';
//                break;
//            }
//        }
//    }
//
//    is.close();
//    os.close();
//    return 0;
//}
