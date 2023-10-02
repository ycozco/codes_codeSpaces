#include "bubbleSort.cpp"
#include "heapSort.cpp"
#include "mergeSort.cpp"
#include "mergeSort2.cpp"
#include "quickSort.cpp"
#include "shellSort.cpp"

#include <iostream>
#include <chrono>
#include <random>

const int TAMANIO = 10000;

// Función para generar un arreglo de números aleatorios
int* generarArregloRandom(int size) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 10000);

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = dist(mt);
    }

    return arr;
}

void imprimirArreglo(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int* arr = generarArregloRandom(TAMANIO);

    // Copias del arreglo original
    int* arr1 = new int[TAMANIO];
    int* arr2 = new int[TAMANIO];
    int* arr3 = new int[TAMANIO];
    int* arr4 = new int[TAMANIO];
    int* arr5 = new int[TAMANIO];

    std::copy(arr, arr + TAMANIO, arr1);
    std::copy(arr, arr + TAMANIO, arr2);
    std::copy(arr, arr + TAMANIO, arr3);
    std::copy(arr, arr + TAMANIO, arr4);
    std::copy(arr, arr + TAMANIO, arr5);

    // Medir el tiempo de BubbleSort
    auto inicio = std::chrono::high_resolution_clock::now();
    bubbleSort(arr1, TAMANIO);
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> tiempo = fin - inicio;

    std::cout << "Arreglo ordenado por BubbleSort: ";
    //imprimirArreglo(arr1, TAMANIO);
    std::cout << "Tiempo: " << tiempo.count() << " ms.\n";

    // Medir el tiempo de HeapSort
    inicio = std::chrono::high_resolution_clock::now();
    heapSort(arr2, TAMANIO);
    fin = std::chrono::high_resolution_clock::now();
    tiempo = fin - inicio;
    std::cout << "Arreglo ordenado por HeapSort: ";
    //imprimirArreglo(arr2, TAMANIO);
    std::cout << "Tiempo: " << tiempo.count() << " ms.\n";

    // Medir el tiempo de MergeSort
    inicio = std::chrono::high_resolution_clock::now();
    mergeSort(arr3, 0, TAMANIO - 1);
    fin = std::chrono::high_resolution_clock::now();
    tiempo = fin - inicio;
    std::cout << "Arreglo ordenado por MergeSort: ";
    //imprimirArreglo(arr3, TAMANIO);
    std::cout << "Tiempo: " << tiempo.count() << " ms.\n";

    // Medir el tiempo de QuickSort
    inicio = std::chrono::high_resolution_clock::now();
    quickSort(arr4, 0, TAMANIO - 1);
    fin = std::chrono::high_resolution_clock::now();
    tiempo = fin - inicio;
    std::cout << "Arreglo ordenado por QuickSort: ";
    //imprimirArreglo(arr4, TAMANIO);
    std::cout << "Tiempo: " << tiempo.count() << " ms.\n";

    // Medir el tiempo de ShellSort
    inicio = std::chrono::high_resolution_clock::now();
    shellSort(arr5, TAMANIO);
    fin = std::chrono::high_resolution_clock::now();
    tiempo = fin - inicio;
    std::cout << "Arreglo ordenado por ShellSort: ";
    // imprimirArreglo(arr5, TAMANIO);
    std::cout << "Tiempo: " << tiempo.count() << " ms.\n";
    // Limpieza de memoria
    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;

    return 0;
}

