#include <iostream>
using namespace std;

// Nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

class ListaCircular {
private:
    Nodo* cabeza;

public:
    ListaCircular() {
        cabeza = NULL;
    }

    // Verificar si esta vacia
    bool estaVacia() {
        return cabeza == NULL;
    }

    // Insertar al inicio
    void insertarInicio(int valor) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = valor;

        if (estaVacia()) {
            cabeza = nuevo;
            nuevo->siguiente = cabeza;
        } else {
            Nodo* temp = cabeza;

            while (temp->siguiente != cabeza) {
                temp = temp->siguiente;
            }

            nuevo->siguiente = cabeza;
            temp->siguiente = nuevo;
            cabeza = nuevo;
        }
    }

    // Insertar al final
    void insertarFinal(int valor) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = valor;

        if (estaVacia()) {
            cabeza = nuevo;
            nuevo->siguiente = cabeza;
        } else {
            Nodo* temp = cabeza;

            while (temp->siguiente != cabeza) {
                temp = temp->siguiente;
            }

            temp->siguiente = nuevo;
            nuevo->siguiente = cabeza;
        }
    }

    // Mostrar elementos
    void mostrar() {
        if (estaVacia()) {
            cout << "La lista esta vacia\n";
            return;
        }

        Nodo* temp = cabeza;

        do {
            cout << temp->dato << " -> ";
            temp = temp->siguiente;
        } while (temp != cabeza);

        cout << "(regresa al inicio)\n";
    }

    // Contar elementos
    int contar() {
        if (estaVacia()) return 0;

        int contador = 0;
        Nodo* temp = cabeza;

        do {
            contador++;
            temp = temp->siguiente;
        } while (temp != cabeza);

        return contador;
    }
};

// Programa principal con menu
int main() {
    ListaCircular lista;
    int opcion, valor;

    do {
        cout << "\n===== MENU LISTA CIRCULAR =====\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Mostrar elementos\n";
        cout << "4. Verificar si esta vacia\n";
        cout << "5. Contar elementos\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> valor;
                lista.insertarInicio(valor);
                break;

            case 2:
                cout << "Ingrese valor: ";
                cin >> valor;
                lista.insertarFinal(valor);
                break;

            case 3:
                lista.mostrar();
                break;

            case 4:
                if (lista.estaVacia())
                    cout << "La lista esta vacia\n";
                else
                    cout << "La lista NO esta vacia\n";
                break;

            case 5:
                cout << "Cantidad de elementos: " << lista.contar() << endl;
                break;

            case 0:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while (opcion != 0);

    return 0;
}
