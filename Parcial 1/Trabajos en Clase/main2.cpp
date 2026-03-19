
#include <iostream>
using namespace std;

template <typename T>
class NodoDoble {
public:
    T info;
    NodoDoble<T>* next;
    NodoDoble<T>* prev;

    NodoDoble(T valor) {
        info = valor;
        next = 0;
        prev = 0;
    }
};

template <typename T>
class ListaDoble {

private:
    NodoDoble<T>* head;
    NodoDoble<T>* tail;

public:

    ListaDoble() {
        head = 0;
        tail = 0;
    }

    ~ListaDoble() {
        NodoDoble<T>* aux;
        while (head != 0) {
            aux = head;
            head = head->next;
            delete aux;
        }
        tail = 0;
    }

    bool estaVacia() {
        return head == 0;
    }

    void insertarFin(T valor) {
        NodoDoble<T>* nuevo = new NodoDoble<T>(valor);

        if (estaVacia()) {
            head = tail = nuevo;
        } else {
            nuevo->prev = tail;
            tail->next = nuevo;
            tail = nuevo;
        }
    }

    bool insertarDespuesDe(T buscado, T valor) {
        if (estaVacia()) return false;

        NodoDoble<T>* actual = head;

        while (actual != 0 && actual->info != buscado) {
            actual = actual->next;
        }

        if (actual == 0) return false;

        NodoDoble<T>* nuevo = new NodoDoble<T>(valor);

        nuevo->next = actual->next;
        nuevo->prev = actual;

        if (actual->next != 0) {
            actual->next->prev = nuevo;
        } else {
            tail = nuevo;
        }

        actual->next = nuevo;
        return true;
    }

    bool eliminar(T valor) {
        if (estaVacia()) return false;

        NodoDoble<T>* actual = head;

        while (actual != 0 && actual->info != valor) {
            actual = actual->next;
        }

        if (actual == 0) return false;

        if (actual == head) {
            head = head->next;

            if (head != 0) {
                head->prev = 0;
            } else {
                tail = 0;
            }

            delete actual;
            return true;
        }

        if (actual == tail) {
            tail = tail->prev;
            tail->next = 0;

            delete actual;
            return true;
        }

        actual->prev->next = actual->next;
        actual->next->prev = actual->prev;

        delete actual;
        return true;
    }

    void imprimirAdelante() {
        NodoDoble<T>* aux = head;

        while (aux != 0) {
            cout << aux->info << " <-> ";
            aux = aux->next;
        }

        cout << "NULL" << endl;
    }

    void imprimirAtras() {
        NodoDoble<T>* aux = tail;

        while (aux != 0) {
            cout << aux->info << " <-> ";
            aux = aux->prev;
        }

        cout << "NULL" << endl;
    }
};

int main() {

    ListaDoble<string> canciones;

    canciones.insertarFin("Intro");
    canciones.insertarFin("Rock");
    canciones.insertarFin("Balada");

    cout << "Recorrido hacia adelante:" << endl;
    canciones.imprimirAdelante();

    cout << "Recorrido hacia atras:" << endl;
    canciones.imprimirAtras();

    canciones.insertarDespuesDe("Rock", "Pop");
    cout << "Despues de insertar Pop:" << endl;
    canciones.imprimirAdelante();

    canciones.eliminar("Rock");
    cout << "Despues de eliminar Rock:" << endl;
    canciones.imprimirAdelante();

    return 0;
}
