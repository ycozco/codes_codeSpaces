#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

bool esPrimo(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    std::vector<int> numeros;
    for (int i = 0; i < 100; ++i) {
        numeros.push_back(rand() % 1000); 
    }

    std::cout << "Vector generado: ";
    for (int num : numeros) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    int contadorPrimos = std::count_if(numeros.begin(), numeros.end(), [](int n) {
        return esPrimo(n) && n < 1000;
    });

    std::cout << "Cantidad de números primos menores que 1000 en el vector: " << contadorPrimos << std::endl;

    return 0;
}
