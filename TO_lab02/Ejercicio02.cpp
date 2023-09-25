#include <iostream>

using namespace std;

struct Nodo {
    int valor;
    Nodo* siguiente;
    Nodo* anterior;
    ~Nodo() {
        cout << "\nNodo eliminado " << valor;
    }
};

class ListaDobleEnlazada {
public:
    ListaDobleEnlazada() {
        inicio = nullptr;
        fin = nullptr;
    }

    void insertarAlInicio(int valor) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->valor = valor;
        nuevoNodo->siguiente = nullptr;
        nuevoNodo->anterior = nullptr;

        if (!inicio) {
            inicio = fin = nuevoNodo;
        } else {
            nuevoNodo->siguiente = inicio;
            inicio->anterior = nuevoNodo;
            inicio = nuevoNodo;
        }
    }

    void imprimir() {
        Nodo* iNodo = inicio;
        while (iNodo != nullptr) {
            cout << iNodo->valor << " ";
            iNodo = iNodo->siguiente;
        }
        cout << endl;
    }

    void destruirLista() {
        Nodo* iNodo = inicio;
        while (iNodo) {
            Nodo* nodoAEliminar = iNodo;
            iNodo = iNodo->siguiente;
            delete nodoAEliminar;
        }
        inicio = fin = nullptr;
    }

    ~ListaDobleEnlazada() {
        destruirLista();
    }

private:
    Nodo* inicio;
    Nodo* fin;
};

int main() {
    int arreglo[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    const int tama = sizeof(arreglo) / sizeof(*arreglo);
    ListaDobleEnlazada lista;

    for (int i = 0; i < tama; ++i) {
        lista.insertarAlInicio(arreglo[i]);
    }

    lista.imprimir();
    lista.destruirLista();
    
    return 0;
}
