#include <iostream>
#include <vector>

// Definición de la clase plantilla Pila
template <typename T>
class Pila {
private:
    std::vector<T> elementos;

public:
    void push(const T& elem) {
        elementos.push_back(elem);
    }

    T pop() {
        if (elementos.empty()) {
            throw std::out_of_range("Pila vacía");
        }
        T elem = elementos.back();
        elementos.pop_back();
        return elem;
    }

    T top() const {
        if (elementos.empty()) {
            throw std::out_of_range("Pila vacía");
        }
        return elementos.back();
    }

    bool empty() const {
        return elementos.empty();
    }

    size_t size() const {
        return elementos.size();
    }
};

int main() {
    Pila<int> pilaNumeros;
    pilaNumeros.push(1);
    pilaNumeros.push(2);
    pilaNumeros.push(3);

    Pila<char> pilaCaracteres;
    pilaCaracteres.push('a');
    pilaCaracteres.push('b');
    pilaCaracteres.push('c');

    std::cout << "Top de pilaNumeros: " << pilaNumeros.top() << std::endl;
    std::cout << "Top de pilaCaracteres: " << pilaCaracteres.top() << std::endl;

    // Ejemplo de manejo de excepciones para pila vacía
    try {
        pilaNumeros.pop();
        pilaNumeros.pop();
        pilaNumeros.pop();
        pilaNumeros.pop(); // Esto lanzará una excepción
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
