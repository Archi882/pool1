#include <stdio.h>
#include <math.h>

/**
 * @brief Рассчитывает функцию А по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return возвращает значение функции А
 */
double a(const double x, const double y, const double z);

/**
 * @brief Рассчитывает функцию B по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return возвращает значение функции B
 */
double b(const double x, const double y, const double z);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main() {
    const double x = 0.61;
    const double y = 3.4;
    const double z = 16.5;
    
    printf("\nx = %.2lf\ny = %.1lf\nz = %.1lf\n", x, y, z);
    printf("a = %lf\nb = %lf\n", a(x, y, z), b(x, y, z));
    
    return 0;
}

double a(const double x, const double y, const double z) {
    return pow(x, 3) * pow(tan(x + y), 4) + (z / sqrt(x + y));
}

double b(const double x, const double y, const double z) {
    return (y * pow(x, 2) - z) / (exp(z * x) - 1);
}

