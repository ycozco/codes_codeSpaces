#include<iostream>

using namespace std;

struct Nodo {
	int valor;
	Nodo *siguiente;
	~Nodo() {
		cout << "\nNodo eliminado " << valor;
	}
};

void copiaArreglo(int arreglo[], int size, Nodo **inicio);
void imprimeLista(Nodo *inicio);
void destruyeLista(Nodo *inicio);

int main()
{
	int arreglo[] = { 1,2,3,4,5,6,7,8,9,10 };
	const int tama = sizeof(arreglo) / sizeof(*arreglo);
	Nodo *inicio = nullptr;

	copiaArreglo(arreglo, tama, &inicio);
	imprimeLista(inicio);
	destruyeLista(inicio);

	int espera;
	cin >> espera;

	return 0;
}

void copiaArreglo(int arreglo[], int size, Nodo **inicio) {
	Nodo *iNodo;
	int i = 0;
	*inicio = new Nodo;
	(**inicio).valor = arreglo[i];
	(**inicio).siguiente = nullptr;
	i++;
	iNodo = *inicio;
	while (i < size) {
		iNodo->siguiente = new Nodo;
		iNodo = iNodo->siguiente;
		iNodo->valor = arreglo[i];
		iNodo->siguiente = nullptr;
		i++;
	}
}

void imprimeLista(Nodo *inicio) {
	Nodo *iNodo;
	iNodo = inicio;
	while (iNodo!=nullptr) {
		cout << iNodo->valor << " ";
		iNodo = iNodo->siguiente;
	}
}

void destruyeLista(Nodo *inicio) {
	Nodo *iNodo;
	Nodo *AuxNodo;
	iNodo = inicio;
	while (iNodo->siguiente != nullptr) {
		AuxNodo = iNodo->siguiente;
		delete iNodo;
		iNodo = AuxNodo;
	}
	delete iNodo;
}