#include <stdio.h>

/**
 * @brief Перечислимый тип для выбора метода обмена значений
 */
typedef enum {
    with = 1,
    without
} swap;

/**
 * @brief Меняет местами значения переменных A и B с использованием третьей переменной C
 * @param a - Параметр первой переменной
 * @param b - Параметр второй переменной
 * @param c - Параметр третьей переменной
 */
void swapWith(int* a, int* b, int* c) {
    *c = *a;    
    *a = *b;    
    *b = *c;    
}

/**
 * @brief Меняет местами значения переменных A и B без использования третьей переменной
 * @param a - Параметр первой переменной
 * @param b - Параметр второй переменной
 * @param c - Параметр третьей переменной (используется только для демонстрации)
 */
void swapWithout(int* a, int* b, int* c) {
    printf("Value of C before swap: %d\n", *c);   
    *a = *a + *b;  
    *b = *a - *b;  
    *a = *a - *b; 
    printf("Value of C after swap: %d (unchanged)\n", *c);
    printf("C was not used to swap values A and B\n");
}

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main() {
    int a,b,c = 0;
    int choice;
    printf("Enter value for A: ");
    if (scanf_s("%d", &a) != 1) {
        printf("Error: invalid input for A.\n");
        return 1;
    }
    
    printf("Enter value for B: ");
    if (scanf_s("%d", &b) != 1) {
        printf("Error: invalid input for B.\n");
        return 1;
    }
    
    printf("Enter value for C: ");
    if (scanf_s("%d", &c) != 1) {
        printf("Error: invalid input for C.\n");
        return 1;
    }
    
    printf("\nInitial values: A = %d, B = %d, C = %d\n", a, b, c);
    
    printf("\nSelect swap method:\n");
    printf("1. Using a third variable \n");
    printf("2. Without using a third variable \n");
    printf("Enter option number: ");
    
    if (scanf_s("%d", &choice) != 1) {
        printf("Error: invalid choice.\n");
        return 1;
    }
    
    switch (choice) {
        case with:
            printf("\n--- Method using variable C ---\n");
            printf("Value of C before swap: %d\n", c);
            swapWith(&a, &b, &c);
            printf("Value of C after swap: %d\n", c);
            printf("C was used as a buffer for swapping\n");
            break;
            
        case without:
            printf("\n--- Method without using variable C ---\n");
            swapWithout(&a, &b, &c);
            break;
            
        default:
            printf("Error: invalid option number.\n");
            return 1;
    }
    
    printf("\nResult after swap:\n");
    printf("A = %d\n", a);
    printf("B = %d\n", b);
    printf("C = %d\n", c);
    
    return 0;
}