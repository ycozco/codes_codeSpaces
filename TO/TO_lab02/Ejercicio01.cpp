#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AnalizadorOperacion {
public:
    AnalizadorOperacion(const string& operacion) : operacion_(operacion) {}

    vector<string> ObtenerOperadores() {
        vector<string> operadores;
        size_t inicio = 0;

        for (size_t i = 0; i < operacion_.size(); ++i) {
            if (operacion_[i] == '+' || operacion_[i] == '-') {
                operadores.push_back(operacion_.substr(inicio, i - inicio));
                operadores.push_back(string(1, operacion_[i]));
                inicio = i + 1;
            }
        }
        operadores.push_back(operacion_.substr(inicio));

        return operadores;
    }

private:
    string operacion_; // Declaración de la variable operacion_
};

class AdministradorOperaciones {
public:
    static int RealizarOperacion(int numero1, int numero2, char operador) {
        if (operador == '+') {
            return numero1 + numero2;
        } else if (operador == '-') {
            return numero1 - numero2;
        }
        return 0; // Manejo de error si el operador no es válido
    }
};

class ProcesadorOperacion {
public:
    static int Procesar(const string& operacion) {
        AnalizadorOperacion analizador(operacion);
        vector<string> operadores = analizador.ObtenerOperadores();

        int resultado = stoi(operadores[0]); // Convertir el primer número a entero

        for (size_t i = 1; i < operadores.size(); i += 2) {
            char operador = operadores[i][0];
            int numero = stoi(operadores[i + 1]);

            resultado = AdministradorOperaciones::RealizarOperacion(resultado, numero, operador);
        }

        return resultado;
    }
};

int main() {
    string operacion;
    cout << "Ingrese una operación matemática: ";
    cin >> operacion;

    int resultado = ProcesadorOperacion::Procesar(operacion);
    cout << "El resultado es: " << resultado << endl;

    return 0;
}