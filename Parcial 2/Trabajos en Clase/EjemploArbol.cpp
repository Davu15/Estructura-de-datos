#include <iostream>
#include <vector>
using namespace std;

// Definición del nodo
struct Nodo {
    string nombre;
    vector<Nodo*> hijos;

    // Constructor
    Nodo(string n) {
        nombre = n;
    }
};

// Función para agregar hijo
void agregarHijo(Nodo* padre, Nodo* hijo) {
    padre->hijos.push_back(hijo);
}

// Función para mostrar el árbol (recorrido)
void mostrarArbol(Nodo* nodo, int nivel = 0) {
    // Indentación
    for(int i = 0; i < nivel; i++) {
        cout << "  ";
    }

    cout << "- " << nodo->nombre << endl;

    // Recorrer hijos
    for(auto hijo : nodo->hijos) {
        mostrarArbol(hijo, nivel + 1);
    }
}

int main() {
    // 🔹 Raíz
    Nodo* gerenteGeneral = new Nodo("Gerente General");

    // 🔹 Gerentes intermedios
    Nodo* ventas = new Nodo("Gerente de Ventas");
    Nodo* operaciones = new Nodo("Gerente de Operaciones");
    Nodo* finanzas = new Nodo("Gerente de Finanzas");

    // 🔹 Empleados de ventas
    Nodo* empV1 = new Nodo("EMP 1 Ventas");
    Nodo* empV2 = new Nodo("EMP 2 Ventas");

    // 🔹 Empleados de operaciones
    Nodo* empO1 = new Nodo("EMP 1 Operaciones");
    Nodo* empO2 = new Nodo("EMP 2 Operaciones");

    // 🔹 Empleados de finanzas
    Nodo* empF1 = new Nodo("EMP 1 Finanzas");
    Nodo* empF2 = new Nodo("EMP 2 Finanzas");

    // 🔹 Construcción del árbol
    agregarHijo(gerenteGeneral, ventas);
    agregarHijo(gerenteGeneral, operaciones);
    agregarHijo(gerenteGeneral, finanzas);

    agregarHijo(ventas, empV1);
    agregarHijo(ventas, empV2);

    agregarHijo(operaciones, empO1);
    agregarHijo(operaciones, empO2);

    agregarHijo(finanzas, empF1);
    agregarHijo(finanzas, empF2);

    // 🔹 Mostrar estructura
    cout << "Estructura de la empresa:\n";
    mostrarArbol(gerenteGeneral);

    return 0;
}