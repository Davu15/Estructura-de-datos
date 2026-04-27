#include <iostream>

using namespace std;

class PilaArreglo {
private:
    int pila[5]; // Arreglo de tamaño 5
    int tope;    // Índice del elemento superior

public:
    // 1. Inicializar (Constructor)
    PilaArreglo() {
        tope = -1; // -1 significa que la pila está vacía
    }

    // 2. Operación Push(x)
    void push(int x) {
        if (tope == 4) { // Si el tope llegó al final del arreglo (0,1,2,3,4)
            cout << "Error: Pila llena (Overflow)" << endl;
        } else {
            tope++;            // Incrementamos el tope
            pila[tope] = x;    // Guardamos el valor
            cout << "Push(" << x << ") -> Tope ahora es " << tope << endl;
        }
    }

    // 3. Operación Pop()
    void pop() {
        if (tope == -1) {
            cout << "Error: Pila vacia (Underflow)" << endl;
        } else {
            cout << "Pop(): sale el " << pila[tope] << endl;
            tope--; // Simplemente bajamos el índice
        }
    }

    // 4. Operación Top()
    void verTop() {
        if (tope == -1) {
            cout << "La pila esta vacia." << endl;
        } else {
            cout << "Top(): El elemento superior es " << pila[tope] << endl;
        }
    }

    // Función auxiliar para ver el estado actual
    void mostrarPila() {
        if (tope == -1) {
            cout << "[Vacia]" << endl;
            return;
        }
        cout << "Estado actual de la pila: ";
        for (int i = 0; i <= tope; i++) {
            cout << "[" << pila[i] << "] ";
        }
        cout << " <- Tope" << endl;
    }
};

int main() {
    PilaArreglo miPila;

    cout << "--- Ejecutando Ejercicio Guiado 1 ---" << endl;
    miPila.push(8);   // Paso 2
    miPila.push(15);  // Paso 3
    miPila.push(22);  // Paso 4
    miPila.mostrarPila();

    miPila.pop();     // Paso 5: Sale el 22
    miPila.verTop();  // Paso 6: Muestra el 15 sin borrarlo
    miPila.mostrarPila();

    cout << "\n--- Ejecutando Practica Inmediata ---" << endl;
    // Push(4), Push(9), Push(1), Pop(), Push(7), Top()
    miPila.push(4);
    miPila.push(9);
    miPila.push(1);
    miPila.pop();
    miPila.push(7);
    miPila.verTop();
    miPila.mostrarPila();

    return 0;
}
