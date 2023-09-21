#include "bubbleSort.cpp"
#include "heapSort.cpp"
#include "mergeSort.cpp"
#include "mergeSort2.cpp" 
#include "quickSort.cpp"
#include "shellSort.cpp"

#include <iostream>

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    std::cout << "Original Array: ";
    printArray(arr, n);

    bubbleSort(arr, n);
    std::cout << "Sorted array using BubbleSort: ";
    printArray(arr, n);

    // Recupera el orden original del array para probar el siguiente algoritmo
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    heapSort(arr2, n);
    std::cout << "Sorted array using HeapSort: ";
    printArray(arr2, n);

    // Recupera el orden original del array para probar el siguiente algoritmo
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    mergeSort(arr3, 0, n - 1);
    std::cout << "Sorted array using MergeSort: ";
    printArray(arr3, n);

    // Recupera el orden original del array para probar el siguiente algoritmo
    int arr4[] = {64, 34, 25, 12, 22, 11, 90};
    quickSort(arr4, 0, n - 1);
    std::cout << "Sorted array using QuickSort: ";
    printArray(arr4, n);

    // Recupera el orden original del array para probar el siguiente algoritmo
    int arr5[] = {64, 34, 25, 12, 22, 11, 90};
    shellSort(arr5, n);
    std::cout << "Sorted array using ShellSort: ";
    printArray(arr5, n);


    return 0;
}

// exec code: g++ main.cpp swap.cpp -o main && ./main