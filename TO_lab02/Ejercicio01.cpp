#include <iostream>
#include <string>
#include <vector>

class AnalizadorEntrada {
public:
    static bool esOperacionValida(const std::string& entrada) {
        int contadorOperadores = 0;
        bool esperarOperador = false;

        for (char c : entrada) {
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                if (!esperarOperador) {
                    return false;
                }
                esperarOperador = false;
                contadorOperadores++;
                if (contadorOperadores > 5) {
                    return false;
                }
            } else if (isdigit(c) || c == '.') {
                esperarOperador = true;
            } else if (c != ' ') {
                return false;
            }
        }
        return esperarOperador && contadorOperadores > 0;
    }
};

class NucleoCalculadora {
public:
    static double calcular(const std::string& entrada) {
        std::vector<double> numeros;
        std::vector<char> operadores;

        double numeroActual = 0.0;

        for (char c : entrada) {
            if (isdigit(c) || c == '.') {
                numeroActual = numeroActual * 10 + (c - '0');
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                numeros.push_back(numeroActual);
                operadores.push_back(c);
                numeroActual = 0.0;
            }
        }
        numeros.push_back(numeroActual);
        
        size_t i = 0;
        while (i < operadores.size()) {
            if (operadores[i] == '*' || operadores[i] == '/') {
                double resultado = realizarOperacion(numeros[i], numeros[i + 1], operadores[i]);
                numeros[i] = resultado;
                numeros.erase(numeros.begin() + i + 1);
                operadores.erase(operadores.begin() + i);
            } else {
                i++;
            }
        }
        
        double resultado = numeros[0];
        for (size_t i = 0; i < operadores.size(); i++) {
            resultado = realizarOperacion(resultado, numeros[i + 1], operadores[i]);
        }

        return resultado;
    }
    
private:
    static double realizarOperacion(double operandoIzquierdo, double operandoDerecho, char operador) {
        switch (operador) {
            case '+':
                return operandoIzquierdo + operandoDerecho;
            case '-':
                return operandoIzquierdo - operandoDerecho;
            case '*':
                return operandoIzquierdo * operandoDerecho;
            case '/':
                if (operandoDerecho != 0.0) {
                    return operandoIzquierdo / operandoDerecho;
                } else {
                    std::cerr << "Error: Division por cero" << std::endl;
                    exit(1);
                }
            default:
                std::cerr << "Error: Operador no valido" << std::endl;
                exit(1);
        }
    }
};

class Calculadora {
public:
    static double procesarOperacion(const std::string& operacion) {
        if (!AnalizadorEntrada::esOperacionValida(operacion)) {
            std::cerr << "Error: Operacion matematica no valida." << std::endl;
            return 0.0;
        }
        return NucleoCalculadora::calcular(operacion);
    }
};

int main() {
    std::string entrada;

    std::cout << "Ingrese la operacion matematica (Como mucho 5 operadores): ";
    std::getline(std::cin, entrada);

    double resultado = Calculadora::procesarOperacion(entrada);

    std::cout << "Resultado: " << resultado << std::endl;

    return 0;
}
