#include <iostream>
#include <complex>
#include <cmath>
#include <vector>
typedef std::complex<double> base;
void multiply(std::vector<base> &r, std::vector<base> &t, std::vector<base> &ans, int n, int &checker);
int main()
{
    using namespace std;
    setlocale(LC_ALL, "Russian");
    int N, koef = 0;
label:
    cout << "Введите 1 для прямого преобразования или -1 для обратного: ";
    cin >> koef;
    cout << "Введите количество элементов (1,2,4,8...): ";
    cin >> N;
    vector<base> a(N * N);
    vector<base> arr(N);
    vector<base> ans(N);
    for (int i = 0; i < N; i++)
    {
        std::cout << "Введите элемент, arr[" << i << "]: ";
        std::cin >> arr[i];
        for (int j = 0; j < N; j++)
        {
            base tmp(cos(-2 * (i) * (j)*M_PI / N * koef), sin(-2 * (i) * (j)*M_PI / N * koef));
            a[i * N + j] = tmp;
        }
    }
    multiply(a, arr, ans, N, koef);
    for (int i = 0; i < N; i++)
        std::cout << ans[i] << '\n';
    return 0;
}
void multiply(std::vector<base> &r, std::vector<base> &t, std::vector<base> &ans, int n, int &checker)
{
    base change;
    base q = 0;
    if (checker == 1)
    {
        for (int l = 0; l < n; l++)
        {
            for (int j = 0; j < n; j++)
            {
                change = r[l * n + j] * t[j];
                q = q + change;
            }
            ans[l] = q / (base)n;
            q = 0;
        }
    }
    else
    {
        for (int l = 0; l < n; l++)
        {
            for (int j = 0; j < n; j++)
            {
                change = r[l * n + j] * t[j];
                q = q + change;
            }
            ans[l] = q;
            q = 0;
        }
    }
}