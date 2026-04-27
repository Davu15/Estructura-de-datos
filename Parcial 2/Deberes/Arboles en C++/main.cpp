#include <iostream>
#include <string>
using namespace std;

struct Empleado {
    int codigo;
    string nombre;
    string cargo;
};

struct Nodo {
    Empleado dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(Empleado emp) {
        dato = emp;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

class ArbolBST {
private:
    Nodo* raiz;

    Nodo* insertar(Nodo* nodo, Empleado emp) {
        if (nodo == nullptr) {
            return new Nodo(emp);
        }

        if (emp.codigo < nodo->dato.codigo) {
            nodo->izquierdo = insertar(nodo->izquierdo, emp);
        } else if (emp.codigo > nodo->dato.codigo) {
            nodo->derecho = insertar(nodo->derecho, emp);
        } else {
            cout << "El codigo ya existe.\n";
        }

        return nodo;
    }

    Nodo* buscar(Nodo* nodo, int codigo) {
        if (nodo == nullptr || nodo->dato.codigo == codigo) {
            return nodo;
        }

        if (codigo < nodo->dato.codigo) {
            return buscar(nodo->izquierdo, codigo);
        } else {
            return buscar(nodo->derecho, codigo);
        }
    }

    void inorden(Nodo* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izquierdo);
            mostrarEmpleado(nodo);
            inorden(nodo->derecho);
        }
    }

    void preorden(Nodo* nodo) {
        if (nodo != nullptr) {
            mostrarEmpleado(nodo);
            preorden(nodo->izquierdo);
            preorden(nodo->derecho);
        }
    }

    void postorden(Nodo* nodo) {
        if (nodo != nullptr) {
            postorden(nodo->izquierdo);
            postorden(nodo->derecho);
            mostrarEmpleado(nodo);
        }
    }

    int altura(Nodo* nodo) {
        if (nodo == nullptr) {
            return 0;
        }

        int alturaIzq = altura(nodo->izquierdo);
        int alturaDer = altura(nodo->derecho);

        return 1 + max(alturaIzq, alturaDer);
    }

    void mostrarHojas(Nodo* nodo) {
        if (nodo != nullptr) {
            if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
                mostrarEmpleado(nodo);
            }
            mostrarHojas(nodo->izquierdo);
            mostrarHojas(nodo->derecho);
        }
    }

    void mostrarEmpleado(Nodo* nodo) {
        cout << "Codigo: " << nodo->dato.codigo
             << " | Nombre: " << nodo->dato.nombre
             << " | Cargo: " << nodo->dato.cargo << endl;
    }

public:
    ArbolBST() {
        raiz = nullptr;
    }

    void insertarEmpleado(Empleado emp) {
        raiz = insertar(raiz, emp);
    }

    void buscarEmpleado(int codigo) {
        Nodo* resultado = buscar(raiz, codigo);

        if (resultado != nullptr) {
            cout << "\nEmpleado encontrado:\n";
            mostrarEmpleado(resultado);
        } else {
            cout << "\nEmpleado no encontrado.\n";
        }
    }

    void mostrarRaiz() {
        if (raiz != nullptr) {
            cout << "\nRaiz del arbol:\n";
            mostrarEmpleado(raiz);
        } else {
            cout << "El arbol esta vacio.\n";
        }
    }

    void mostrarInorden() {
        cout << "\nRecorrido Inorden:\n";
        inorden(raiz);
    }

    void mostrarPreorden() {
        cout << "\nRecorrido Preorden:\n";
        preorden(raiz);
    }

    void mostrarPostorden() {
        cout << "\nRecorrido Postorden:\n";
        postorden(raiz);
    }

    void mostrarAltura() {
        cout << "\nAltura del arbol: " << altura(raiz) << endl;
    }

    void mostrarNodosHoja() {
        cout << "\nNodos hoja:\n";
        mostrarHojas(raiz);
    }
};

int main() {
    ArbolBST arbol;
    int opcion;

    do {
        cout << "\n===== MENU ARBOL BST EMPRESARIAL =====\n";
        cout << "1. Insertar empleado\n";
        cout << "2. Buscar empleado\n";
        cout << "3. Mostrar raiz\n";
        cout << "4. Recorrido inorden\n";
        cout << "5. Recorrido preorden\n";
        cout << "6. Recorrido postorden\n";
        cout << "7. Mostrar altura\n";
        cout << "8. Mostrar hojas\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            Empleado emp;
            cout << "Codigo: ";
            cin >> emp.codigo;
            cin.ignore();

            cout << "Nombre: ";
            getline(cin, emp.nombre);

            cout << "Cargo: ";
            getline(cin, emp.cargo);

            arbol.insertarEmpleado(emp);
        } 
        else if (opcion == 2) {
            int codigo;
            cout << "Ingrese codigo a buscar: ";
            cin >> codigo;
            arbol.buscarEmpleado(codigo);
        } 
        else if (opcion == 3) {
            arbol.mostrarRaiz();
        } 
        else if (opcion == 4) {
            arbol.mostrarInorden();
        } 
        else if (opcion == 5) {
            arbol.mostrarPreorden();
        } 
        else if (opcion == 6) {
            arbol.mostrarPostorden();
        } 
        else if (opcion == 7) {
            arbol.mostrarAltura();
        } 
        else if (opcion == 8) {
            arbol.mostrarNodosHoja();
        }

    } while (opcion != 0);

    return 0;
}