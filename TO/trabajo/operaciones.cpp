#include <stdio.h>

int main() {
    int num1, num2;

    // Solicitar los números al usuario
    printf("Introduce el primer número entero: ");
    if (scanf("%d", &num1) != 1) {
        printf("Error: Entrada no válida. Por favor, introduce un número entero.\n");
        return 1; // Salir con un código de error
    }

    printf("Introduce el segundo número entero: ");
    if (scanf("%d", &num2) != 1) {
        printf("Error: Entrada no válida. Por favor, introduce un número entero.\n");
        return 1; // Salir con un código de error
    }

    // Mostrar resultados
    printf("Suma: %d + %d = %d\n", num1, num2, num1 + num2);
    printf("Resta: %d - %d = %d\n", num1, num2, num1 - num2);
    printf("Multiplicación: %d * %d = %d\n", num1, num2, num1 * num2);

    // Verificar si el segundo número es 0 antes de calcular el módulo
    if (num2 == 0) {
        printf("Error: No se puede calcular el módulo con 0.\n");
    } else {
        printf("Módulo: %d %% %d = %d\n", num1, num2, num1 % num2);
    }

    return 0;
}

//path: trabajo/operaciones.cpp
//exec: g++ -o operaciones operaciones.cpp && ./operaciones
