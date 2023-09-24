#include <iostream>
#include <string>
#include <stack>
#include <cctype>

// Función para determinar la precedencia de los operadores
int precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Función para realizar una operación
int operar(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// Función para evaluar la expresión
int evaluar(const std::string& expresion) {
    std::stack<int> valores;
    std::stack<char> ops;

    for (int i = 0; i < expresion.length(); i++) {
        if (expresion[i] == ' ') continue;

        if (isdigit(expresion[i])) {
            int val = 0;
            while (i < expresion.length() && isdigit(expresion[i])) {
                val = (val * 10) + (expresion[i] - '0');
                i++;
            }
            valores.push(val);
            i--;
        } else {
            while (!ops.empty() && precedencia(ops.top()) >= precedencia(expresion[i])) {
                int val2 = valores.top();
                valores.pop();

                int val1 = valores.top();
                valores.pop();

                char op = ops.top();
                ops.pop();

                valores.push(operar(val1, val2, op));
            }
            ops.push(expresion[i]);
        }
    }

    while (!ops.empty()) {
        int val2 = valores.top();
        valores.pop();

        int val1 = valores.top();
        valores.pop();

        char op = ops.top();
        ops.pop();

        valores.push(operar(val1, val2, op));
    }

    return valores.top();
}

int main() {
    std::string expresion;
    std::cout << "Ingrese la operación: ";
    std::getline(std::cin, expresion);

    std::cout << "Resultado: " << evaluar(expresion) << std::endl;

    return 0;
}
