#include <iostream>
#include <vector>
#include <string>
#include <fmt/core.h>  // Asegúrate de tener instalada la biblioteca fmt

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

    cout << fmt::format("{:<15} {:<10} {:<15}\n", "Jugador", "Goles", "Asistencias");
    cout << string(40, '-') << endl;

    for (const Jugador &j : jugadores) {
        cout << fmt::format("{:<15} {:<10} {:<15}\n", j.nombre, j.goles, j.asistencias);
    }

    return 0;
}
