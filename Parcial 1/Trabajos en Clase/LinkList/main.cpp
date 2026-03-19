#include <iostream>
using namespace std;


struct Nodo {
    int dato;
    Nodo* siguiente;
};

int main() {

    Nodo* cabeza = NULL; 
    int numElementos, valor;

    cout << "Ingrese el numero de elementos que tiene la lista ";
    cin >> numElementos;

    for (int i = 0; i < numElementos; i++) {

        cout << "Ingrese el valor del nodo" << i + 1 << ": ";
        cin >> valor;

       
        Nodo* nuevo = new Nodo;
        nuevo->dato = valor;


        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    // Mostrar la lista
    Nodo* temp = cabeza;

    cout << "\nLista : \n";

    while (temp != NULL) {
        cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }

    cout << "NULL\n";

    return 0;
}
