#include <iostream>
#include <string>

// Nodo para la lista enlazada
struct Nodo {
    int valor;
    char operacion;
    Nodo* siguiente;
    Nodo(int v, char op) : valor(v), operacion(op), siguiente(nullptr) {}
};

bool esDigito(char c) {
    return c >= '0' && c <= '9';
}

int operar(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int evaluar(const std::string& expresion) {
    Nodo* cabeza = nullptr;
    Nodo* actual = nullptr;
    std::string numero = "";
    for (char c : expresion) {
        if (esDigito(c)) {
            numero += c;
        } else {
            if (!cabeza) {
                cabeza = new Nodo(std::stoi(numero), c);
                actual = cabeza;
            } else {
                actual->siguiente = new Nodo(std::stoi(numero), c);
                actual = actual->siguiente;
            }
            numero = "";
        }
    }
    if (!numero.empty()) {
        if (!cabeza) {
            cabeza = new Nodo(std::stoi(numero), ' ');
        } else {
            actual->siguiente = new Nodo(std::stoi(numero), ' ');
        }
    }

   // Corrección del código empieza aquí
    Nodo* previo = nullptr;
    Nodo* nodoActual = cabeza;
    while (nodoActual && nodoActual->siguiente) {
        if (nodoActual->siguiente->operacion == '*' || nodoActual->siguiente->operacion == '/') {
            nodoActual->valor = operar(nodoActual->valor, nodoActual->siguiente->valor, nodoActual->siguiente->operacion);
            Nodo* temp = nodoActual->siguiente;
            nodoActual->siguiente = nodoActual->siguiente->siguiente;
            delete temp;
            if (previo) {
                previo->siguiente = nodoActual;  // Actualizar el nodo anterior para apuntar al nodo actual
            }
            continue;
        }
        previo = nodoActual;
        nodoActual = nodoActual->siguiente;
    }
    // Luego, evaluamos las sumas y restas
    nodoActual = cabeza;
    int resultado = nodoActual->valor;
    while (nodoActual->siguiente) {
        resultado = operar(resultado, nodoActual->siguiente->valor, nodoActual->siguiente->operacion);
        nodoActual = nodoActual->siguiente;
    }
    // Liberar memoria
    while (cabeza) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }

    return resultado;
}

int main() {
    std::string expresion;
    std::cout << "Ingrese la operación: ";
    std::getline(std::cin, expresion);

    std::cout << "Resultado: " << evaluar(expresion) << std::endl;

    return 0;
}
