#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <cctype>

// Clase base para los nodos del árbol
class Node {
public:
    // Método virtual para evaluar el nodo
    virtual double evaluate() = 0;
    // Destructor virtual
    virtual ~Node() {}
};

// Clase para representar números (nodos hoja)
class NumberNode : public Node {
    double value; // Valor del número
public:
    // Constructor que inicializa el valor del nodo
    NumberNode(double v) : value(v) {}
    // Evaluar el nodo devuelve su valor
    double evaluate() override {
        return value;
    }
};

// Clase base para operadores binarios (+, -, *, /)
class BinaryOperatorNode : public Node {
protected:
    Node* left;  // Nodo hijo izquierdo
    Node* right; // Nodo hijo derecho
public:
    // Constructor que inicializa los nodos hijos
    BinaryOperatorNode(Node* l, Node* r) : left(l), right(r) {}
    // Destructor que libera la memoria de los nodos hijos
    ~BinaryOperatorNode() {
        delete left;
        delete right;
    }
};

// Clases para representar cada operador binario
class SumNode : public BinaryOperatorNode {
public:
    using BinaryOperatorNode::BinaryOperatorNode;
    double evaluate() override {
        return left->evaluate() + right->evaluate();
    }
};

class SubtractNode : public BinaryOperatorNode {
public:
    using BinaryOperatorNode::BinaryOperatorNode;
    double evaluate() override {
        return left->evaluate() - right->evaluate();
    }
};

class MultiplyNode : public BinaryOperatorNode {
public:
    using BinaryOperatorNode::BinaryOperatorNode;
    double evaluate() override {
        return left->evaluate() * right->evaluate();
    }
};

class DivideNode : public BinaryOperatorNode {
public:
    using BinaryOperatorNode::BinaryOperatorNode;
    double evaluate() override {
        return left->evaluate() / right->evaluate();
    }
};

// Función para tokenizar la expresión
// Convierte la expresión en una lista de tokens (números, operadores, paréntesis)
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream stream(s);
    char ch;
    while (stream >> ch) {
        if (isdigit(ch) || (ch == '.' && token.empty())) {
            token += ch;
            while (stream.peek() != EOF && (isdigit(stream.peek()) || stream.peek() == '.')) {
                token += stream.get();
            }
            tokens.push_back(token);
            token.clear();
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')') {
            tokens.push_back(std::string(1, ch));
        }
    }
    return tokens;
}

// Función para determinar la precedencia de los operadores
int precedence(const std::string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

// Función para convertir la lista de tokens a notación postfija (Notación Polaca Inversa)
// Esta notación facilita la construcción del árbol binario de expresiones
std::vector<std::string> toPostfix(const std::vector<std::string>& tokens) {
    std::vector<std::string> postfix;
    std::stack<std::string> ops;
    for (const auto& token : tokens) {
        if (isdigit(token[0]) || (token.size() > 1 && token[1] == '.')) {
            postfix.push_back(token);
        } else if (token == "(") {
            ops.push(token);
        } else if (token == ")") {
            while (!ops.empty() && ops.top() != "(") {
                postfix.push_back(ops.top());
                ops.pop();
            }
            ops.pop();
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(token)) {
                postfix.push_back(ops.top());
                ops.pop();
            }
            ops.push(token);
        }
    }
    while (!ops.empty()) {
        postfix.push_back(ops.top());
        ops.pop();
    }
    return postfix;
}

// Función para construir el árbol binario de expresiones a partir de la notación postfija
Node* constructTree(const std::vector<std::string>& postfix) {
    std::stack<Node*> stack;
    for (const auto& token : postfix) {
        if (isdigit(token[0]) || (token.size() > 1 && token[1] == '.')) {
            stack.push(new NumberNode(std::stod(token)));
        } else {
            Node* right = stack.top(); stack.pop();
            Node* left = stack.top(); stack.pop();
            if (token == "+") stack.push(new SumNode(left, right));
            else if (token == "-") stack.push(new SubtractNode(left, right));
            else if (token == "*") stack.push(new MultiplyNode(left, right));
            else if (token == "/") stack.push(new DivideNode(left, right));
        }
    }
    return stack.top();
}

int main() {
    std::string expression;
    std::cout << "Introduce una expresión matemática: ";
    std::getline(std::cin, expression);

    // Tokenizar la expresión
    auto tokens = tokenize(expression);
    // Convertir a notación postfija
    auto postfix = toPostfix(tokens);
    // Construir el árbol binario de expresiones
    Node* tree = constructTree(postfix);

    // Evaluar y mostrar el resultado
    std::cout << "Resultado: " << tree->evaluate() << std::endl;

    // Liberar memoria
    delete tree;
    return 0;
}
