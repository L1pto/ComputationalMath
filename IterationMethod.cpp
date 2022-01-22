#include <iostream>
#include <cmath>
class Matr
{
private:
    int maxCounts = 20000;
    int n;
    double **masA;
    double *masB;

public:
    // конструктор, требует ввода размерности,
    // матрицы коэффициентов уравнений и
    // матрицы свободных членов
    Matr()
    {
        std::cout << "Введите размерность: ";
        std::cin >> n;
        masB = new double[n];
        masA = new double *[n];
        for (int i = 0; i < n; i++)
        {
            masA[i] = new double[n];
            for (int j = 0; j < n; j++)
            {
                std::cout << "Введите a[" << i << "][" << j << "]: ";
                std::cin >> masA[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            std::cout << "Введите b[" << i << "]: ";
            std::cin >> masB[i];
        }
    }
    // деструктор чистит память от
    // матрицы свободных членов
    // и матрицы коэффициентов уравнений
    ~Matr()
    {
        for (int i = 0; i < n; i++)
            delete[] masA[i];
        delete[] masA, masB;
    }
    // метод итераций длярешения СЛАУ
    void Itera()
    {
        double *currentVariableValues = new double[n];
        double *previousVariableValues = new double[n]();
        int counter = 0;
        do
        {
            // Посчитаем значения неизвестных на текущей итерации
            // в соответствии с теоретическими формулами
            for (int i = 0; i < n; i++)
            {
                // Инициализируем i-ую неизвестную значением
                // свободного члена i-ой строки матрицы
                currentVariableValues[i] = masB[i];
                // Вычитаем сумму по всем отличным от i-ой неизвестным
                for (int j = 0; j < n; j++)
                    if (i != j)
                        currentVariableValues[i] -= masA[i][j] *
                                                    previousVariableValues[j];
                // Делим на коэффициент при i-ой неизвестной
                currentVariableValues[i] /= masA[i][i];
            }
            previousVariableValues = currentVariableValues;
            counter++;
        } while (counter < maxCounts);
        for (int i = 0; i < n; i++)
            std::cout << "x[" << i << "] = " << previousVariableValues[i] << std::endl;
        delete[] currentVariableValues, previousVariableValues;
    }
};
int main()
{
    Matr *res = new Matr;
    res->Itera();
    delete res;
    return 0;
}
