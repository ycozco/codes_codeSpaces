#include <iostream>

// Clase Nodo
class Nodo {
public:
    virtual double evaluar() = 0; // Método virtual puro para evaluar
};

// Clase Operand
class Operand : public Nodo {
    double valor;

public:
    Operand(double v) : valor(v) {}

    double evaluar() {
        return valor;
    }
};

// Clase para operador suma
class Suma : public Nodo {
    Nodo* izquierdo;
    Nodo* derecho;

public:
    Suma(Nodo* izq, Nodo* der) : izquierdo(izq), derecho(der) {}

    double evaluar() {
        return izquierdo->evaluar() + derecho->evaluar();
    }
};

// Clase para operador multiplicación
class Multiplicacion : public Nodo {
    Nodo* izquierdo;
    Nodo* derecho;

public:
    Multiplicacion(Nodo* izq, Nodo* der) : izquierdo(izq), derecho(der) {}

    double evaluar() {
        return izquierdo->evaluar() * derecho->evaluar();
    }
};

int main() {
    // Crear un árbol para la expresión (3 + 4) * 2
    Nodo* tres = new Operand(3);
    Nodo* cuatro = new Operand(4);
    Nodo* suma = new Suma(tres, cuatro);

    Nodo* dos = new Operand(2);
    Nodo* expresion = new Multiplicacion(suma, dos);

    std::cout << "(3 + 4) * 2 = " << expresion->evaluar() << std::endl;

    // Limpieza de memoria
    delete tres;
    delete cuatro;
    delete suma;
    delete dos;
    delete expresion;

    return 0;
}
