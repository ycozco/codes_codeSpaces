#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Implementación de ShellSort para ordenar en orden descendente
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

int main() {
    srand(time(nullptr));  // Inicialización del generador de números aleatorios al comienzo del programa.

    int N;
    cout << "Ingrese un numero entero positivo N: ";
    cin >> N;

    if (N <= 0) {
        cout << "N debe ser un numero entero positivo." << endl;
        return 1;
    }

    char opcion;
    cout << "Ingrese 'g' para autogenerar numeros aleatorios o 'i' para ingresar manualmente: ";
    cin >> opcion;

    vector<int> numeros;

    if (opcion == 'g') {
        // Autogenerar números aleatorios
        for (int i = 0; i < N; ++i) {
            numeros.push_back(rand() % N + 1);
        }
    } else if (opcion == 'i') {
        // Ingresar números manualmente
        cout << "Ingrese " << N << " numeros enteros:" << endl;
        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
            numeros.push_back(num);
        }
    } else {
        cout << "Opcion no valida. Debe ingresar 'g' o 'i'." << endl;
        return 1;
    }

    // Ordenar de mayor a menor usando ShellSort
    shellSort(numeros);

    cout << (opcion == 'g' ? "Numeros generados" : "Numeros ingresados") << " y ordenados de mayor a menor:" << endl;
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
