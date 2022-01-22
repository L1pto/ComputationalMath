#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 0;
    cout << "Введите максимальную степень многочлена: ";
    cin >> n;              //заполняю массив 5 5 1 0 -11
    int *ptr = new int[n]; //выделяю память для нового массива
    auto k = 0;            //чтобы двигать массив
    cout << "Введите кооэфицинты соответствующие индексам ";
    cout << '\n';
    for (int i = n; i >= 0; --i) //заполнение исходного массива данными
    {
        cout << "Введите a[" << i << "]: ";
        cin >> *(ptr + k);
        ++k;
    }
    cout << '\n';
    cout << "Введите свободный коэффициент двучлена: ";
    int ebs; // 1
    cin >> ebs;
    int *ptr2 = new int[n]; //создаю второй массив для преобразования
    *ptr2 = *ptr;           // присваиваем первый член
    for (int i = 1; i <= n; i++)
    {
        *(ptr2 + i) = ((*(ptr + i)) + *(ptr2 + i - 1) * ebs); //схема Горнера
    }
    cout << "Ответ: (x-" << ebs << ")(";
    for (int i = 0; i <= n; ++i) //вывод получившегося многочлена
    {
        if (i == n)
        {
            cout << ')' << '+' << *(ptr2 + i);
        }
        else if (i == (n - 1))
        {
            cout << *(ptr2 + i) << "x^" << (n - i - 1);
        }
        else
        {
            cout << *(ptr2 + i) << "x^" << (n - i - 1) << '+';
        }
    }
    cout << '\n';
    //проверка умножением
    int checker = 0;
    int y = 0;
    int u1 = 0;
    int u = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        y = *(ptr2 + i);     // получившийся массив
        u = *(ptr2 + i + 1); //получившийся массив
        u1 = *(ptr + i + 1); // исходный массив
        sum = u - ebs * y;   //реализация умножения
        if (sum == u1)
        {
            ++checker;
        }
        else
        {
            --checker;
        }
    }
    cout << (checker == n ? "Проверка пройдена" : "Проверка не пройдена");
    delete[] ptr;
    delete[] ptr2; // освобождение памяти
}