#include <iostream> // Necesario para std::cout y std::endl

int main() {
    using namespace std;  // Para poder usar cout y endl sin el prefijo std::

    unsigned short shortVar = 5;
    unsigned long longVar = 65535;
    long sVar = -65535;

    cout << "shortVar:\t" << shortVar << endl;
    cout << " Address of shortVar:\t "<< &shortVar << "\n";

    cout << "longVar:\t" << longVar << endl;
    cout << " Address of longVar:\t "<< &longVar << "\n";

    cout << "sVar:\t\t" << sVar << endl;
    cout << " Address of sVar:\t "<< &sVar << "\n";

    return 0;
}
