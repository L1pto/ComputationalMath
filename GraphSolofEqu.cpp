#include <iostream>
#include <cmath>
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;
double f(double x);  // исходная функция
double df(double x); //производная функции
double min = -1;     // левая границы для графика
double max = 1.5;    // правая граница для графика
int points = 5000;   // количество точек на графике
double key = 0.82;   // точный корень уравнения
int main()
{
    double lowkey1, highkey2;
    double step = (max - min) / points;
    std::vector<double> x(points);
    for (int i = 0; i < points; i++)
        x.at(i) = min + i * step; // заполнение массива точками для графика
    plt::plot(
        x, [](double d)
        { return 0; },
        "r-", x, [](double d)
        { return f(d); },
        "k-"); //построение графика
    plt::show();
    std::cout << "Введите нижнюю границу корня по графику: ";
    std::cin >> lowkey1;
    std::cout << "Введите верхнюю границу корня по графику: ";
    std::cin >> highkey2;
    std::cout << "Соблюдается теорема о приближении корней? ";
    if (fabs((lowkey1 + highkey2) / 2 - key) <=
        abs(f((lowkey1 + highkey2) / 2)) / abs(df(key))) //реализация проверки теоремы
    {
        std::cout << "Да" <<'\n’;} else
        {
            std::cout << "Нет" <<'\n’;}
        }
        double f(double x) // исходная функция
        {
            return 5 * pow(x, 4) - 2 * pow(x, 3) + 3 * pow(x, 2) + x - 4;
        }
        double df(double x) //производная функции
        {
            return 20 * pow(x, 3) - 6 * pow(x, 2) + 6 * x + 1;
        }
    }
    
}
