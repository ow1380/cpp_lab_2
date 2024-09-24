#include <iostream>
#include <cmath>    // заголовочный файл для степеней

// функция двойного факториала
long double double_fac(int k) {
    long double fac = 1;    // объявляю переменную для факториала
    for (int i = k; i > 0; i -= 2) {    // иду от числа k до 1/2 по числам той же четности
        fac *= i;   // домножаю результат на число i
    }
    return fac;
}

// функция t
long double t(long double x) {
    long double sum1 = 0;    // переменная для верхней части дроби
    long double sum2 = 0;    // переменная для нижней части дроби
    for (int k = 0; k <= 10; k++) {
        sum1 += (pow(x, (2 * k + 1)) / (double_fac((2 * k + 1))));
    }
    for (int k = 0; k <= 10; k++) {
        sum2 += ((pow(x, (2 * k))) / (double_fac((2 * k))));
    }
    return (sum1 / sum2);
}

long double fun(long double y) {
    long double v = 0;  // верх дроби
    long double n = 0;  // низ дроби
    v = 7 * t(0.25) + (2 * t((1 + y)));
    n = 6 - t((pow(y, 2) - 1));
    return (v / n);
}

int main()
{
    std::cout << "y:" << std::endl;
    // ввод с клавиатуры действительного числа y
    long double y; std::cin >> y;
    std::cout << fun(y) << std::endl;
    return 0;
}
