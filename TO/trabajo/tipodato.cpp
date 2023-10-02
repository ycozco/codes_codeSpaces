#include <stdio.h>

int main() {
    // Declaración de variables
    char datoChar = 'A';
    int datoInt = 3;
    float datoFloat = 3.0f;
    double datoDouble = 3.0;

    // Mostrar los datos
    printf("Dato de tipo char: %c\n", datoChar);
    printf("Dato de tipo int: %d\n", datoInt);
    printf("Dato de tipo float: %f\n", datoFloat);
    printf("Dato de tipo double: %lf\n", datoDouble);

    return 0;
}
//path: trabajo/tipodato.cpp
//exec: g++ -o tipodato tipodato.cpp && ./tipodato