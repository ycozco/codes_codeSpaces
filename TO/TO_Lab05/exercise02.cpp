#include <iostream>
using namespace std;

// Definición de la plantilla de clase 'Contenedor' con un tipo genérico T.
template <class T>
class Contendor {
    T elemento;
public:
    Contendor(T arg) { elemento = arg; }
    // Función 'add' que devuelve el elemento almacenado.
    T add() { return +elemento; }
};

template <>
class Contendor <char> {
    char elemento;
public:
    Contendor(char arg) { elemento = arg; }
    char uppercase()
    {
        if ((elemento >= 'a') && (elemento <= 'z')) {
            // Convierte la letra a mayúscula.
            elemento += 'A' - 'a';
        }
        return elemento;
    }
};

int main() {
    // Crea un objeto 'Contendor' para enteros y le pasa el valor 5.
    Contendor<int> cint(5);
    // Crea un objeto 'Contendor' para caracteres y le pasa el carácter 't'.
    Contendor<char> cchar('t');
    cout << cint.add() << endl;
    cout << cchar.uppercase() << endl;
    return 0;
}
