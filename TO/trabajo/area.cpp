#include <stdio.h>

// Definición de la constante pi
#define PI 3.14159265358979323846

int main() {
    double radio, area;

    // Solicitar el radio al usuario
    printf("Introduce el radio del círculo: ");
    scanf("%lf", &radio);

    // Calcular el área de la circunferencia
    area = PI * radio * radio;

    // Mostrar el resultado
    printf("El área de la circunferencia con radio %.2lf es: %.2lf\n", radio, area);

    return 0;
}
// path: trabajo/area.cpp
// exec: g++ -o area area.cpp && ./area