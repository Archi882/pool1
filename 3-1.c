#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <locale.h>

/**
 * @brief Рассчитывает значение функции y = 3x - 4*ln(x) - 5 в точке x
 * @param x - точка X
 * @return Рассчитанное значение
 */
const double function(const double x);

/**
 * @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
 * @return Считанное значение
 */
double defValid();

/**
 * @brief Проверка значения начала и конца интервала
 * @param start - Начало интервала
 * @param end - Конец интервала
 */
void checkEndStart(const double start, const double end);

/**
 * @brief Проверяет значение шага
 * @param step - шаг
 */
void checkStep(const double step);

/**
 * @brief Проверяет, определена ли функция в точке x
 * @param x - Значение параметра x
 * @return Возвращает 0, если функция определена, 1 — если не определена
 */
_Bool checkX(const double x);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно, иначе 1
 */
int main(void)
{
    setlocale(LC_ALL, "");

    printf("Enter the start of the interval: ");
    double start = defValid();
    printf("Enter the end of the interval: ");
    double end = defValid();
    printf("Enter step: ");
    double step = defValid();

    printf("Task: y = 3x - 4*ln(x) - 5\n");
    printf("interval: [%.1lf; %.1lf], step: %.1lf\n", start, end, step);

    checkEndStart(start, end);
    checkStep(step);

    printf("\n%-10s %s\n", "x", "y");
    for (double x = start; x < end + DBL_EPSILON; x += step)
    {
        if (checkX(x))
        {
            printf("%-10.2lf%s\n", x, "Function not defined");
        }
        else
        {
            printf("%-10.2lf%.4lf\n", x, function(x));
        }
    }

    return 0;
}

const double function(const double x)
{
    return 3.0 * x - 4.0 * log(x) - 5.0;
}

double defValid()
{
    double valid = 0;
    if (!scanf_s("%lf", &valid))
    {
        printf("Error\n");
        exit(1);
    }
    return valid;
}

void checkEndStart(const double start, const double end)
{
    if (!(start < end))
    {
        printf("The beginning must be less than the end.\n");
        exit(1);
    }
}

void checkStep(const double step)
{
    if (step <= DBL_EPSILON)
    {
        printf("The step must be positive.\n");
        exit(1);
    }
}

_Bool checkX(const double x)
{
    return (x <= DBL_EPSILON);
}