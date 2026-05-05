#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;

// 🔹 Nodo
struct Nodo {
    string valor;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(string v) {
        valor = v;
        izquierdo = derecho = nullptr;
    }
};

// 🔹 Verifica operador
bool esOperador(string c) {
    return (c == "+" || c == "-" || c == "*" || c == "/");
}

// 🔹 Prioridad
int prioridad(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 🔹 INFIXA → POSTFIJA
vector<string> infijaAPostfija(string exp) {
    stack<char> pila;
    vector<string> salida;
    string numero = "";

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        // Ignorar espacios
        if (c == ' ') continue;

        // Número (puede ser de varios dígitos)
        if (isdigit(c)) {
            numero += c;
        } else {
            if (!numero.empty()) {
                salida.push_back(numero);
                numero = "";
            }

            if (c == '(') {
                pila.push(c);
            }
            else if (c == ')') {
                while (!pila.empty() && pila.top() != '(') {
                    salida.push_back(string(1, pila.top()));
                    pila.pop();
                }
                pila.pop(); // quitar '('
            }
            else { // operador
                while (!pila.empty() && prioridad(pila.top()) >= prioridad(c)) {
                    salida.push_back(string(1, pila.top()));
                    pila.pop();
                }
                pila.push(c);
            }
        }
    }

    if (!numero.empty()) {
        salida.push_back(numero);
    }

    while (!pila.empty()) {
        salida.push_back(string(1, pila.top()));
        pila.pop();
    }

    return salida;
}

// 🔹 Construir árbol
Nodo* construirArbol(vector<string> postfija) {
    stack<Nodo*> pila;

    for (string token : postfija) {
        Nodo* nuevo = new Nodo(token);

        if (!esOperador(token)) {
            pila.push(nuevo);
        } else {
            Nodo* der = pila.top(); pila.pop();
            Nodo* izq = pila.top(); pila.pop();

            nuevo->izquierdo = izq;
            nuevo->derecho = der;

            pila.push(nuevo);
        }
    }
    return pila.top();
}

// 🔹 Evaluar
float evaluar(Nodo* raiz) {
    if (!esOperador(raiz->valor))
        return stof(raiz->valor);

    float izq = evaluar(raiz->izquierdo);
    float der = evaluar(raiz->derecho);

    if (raiz->valor == "+") return izq + der;
    if (raiz->valor == "-") return izq - der;
    if (raiz->valor == "*") return izq * der;

    if (raiz->valor == "/") {
        if (der == 0) {
            cout << "Error: division por cero\n";
            return 0;
        }
        return izq / der;
    }

    return 0;
}

// 🔹 Mostrar
void mostrar(Nodo* raiz) {
    if (raiz) {
        cout << "(";
        mostrar(raiz->izquierdo);
        cout << raiz->valor;
        mostrar(raiz->derecho);
        cout << ")";
    }
}

int main() {
    Nodo* raiz = nullptr;
    int opcion;
    string entrada;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Ingresar expresion (INFIXA)\n";
        cout << "2. Mostrar expresion\n";
        cout << "3. Evaluar expresion\n";
        cout << "4. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {

        case 1: {
            cout << "Ingrese expresion (ej: (35*2)/(5+5)): ";
            getline(cin, entrada);

            vector<string> postfija = infijaAPostfija(entrada);
            raiz = construirArbol(postfija);

            cout << "Expresion procesada correctamente.\n";
            break;
        }

        case 2: {
            if (raiz == nullptr) {
                cout << "Primero ingrese una expresion.\n";
            } else {
                cout << "Expresion: ";
                mostrar(raiz);
                cout << endl;
            }
            break;
        }

        case 3: {
            if (raiz == nullptr) {
                cout << "Primero ingrese una expresion.\n";
            } else {
                cout << "Resultado: " << evaluar(raiz) << endl;
            }
            break;
        }

        case 4: {
            cout << "Saliendo...\n";
            break;
        }

        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 4);

    return 0;
}