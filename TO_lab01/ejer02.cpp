#include <iostream>
#include <iomanip> // Para usar setw
#include <vector>
#include <string>

using namespace std;

struct Jugador {
    string nombre;
    int goles;
    int asistencias;
};

int main() {
    vector<Jugador> jugadores = {
        {"Messi", 25, 10},
        {"Ronaldo", 28, 5},
        {"Neymar", 18, 12},
        {"Mbappe", 24, 8},
        {"Salah", 22, 6}
    };

    cout << left << setw(15) << "Jugador" << setw(10) << "Goles" << setw(15) << "Asistencias" << endl;
    cout << "------------------------------------------------" << endl;

    for (const Jugador& j : jugadores) {
        cout << left << setw(15) << j.nombre << setw(10) << j.goles << setw(15) << j.asistencias << endl;
    }

    return 0;
}
