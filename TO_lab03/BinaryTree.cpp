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
    Nodo* cinco = new Operand(5);
    Nodo* tres4 = new Operand(34);
    Nodo* producto1 = new Suma(cinco, tres4);

    Nodo* uno = new Operand(1);
    Nodo* dos = new Operand(2);
    Nodo* producto2 = new Multiplicacion(uno, dos);

    Nodo* cinco4 = new Operand(54);

    Nodo* expresion1 = new Suma(cinco4, producto1);
    Nodo* expresion = new Suma(expresion1, producto2);

    std::cout << "54+(5*34)+(1*2)= " << expresion->evaluar() << std::endl;

    // Limpieza de memoria
    delete cinco;
    delete tres4;
    delete producto1;
    delete uno;
    delete dos;
    delete producto2;
    delete cinco4;
    delete expresion1;
    delete expresion;

    return 0;
}
