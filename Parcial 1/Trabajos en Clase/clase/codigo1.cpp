#include <iostream>
#include <string>
#include <queue>   // Para las pendientes (FIFO)
#include <list>    // Para el historial de atendidos
#include <stack>   // Para los recientes (LIFO)

using namespace std;

// 1. Modelo de datos segun la imagen
struct Solicitud {
    string cedula;
    string nombre;
    string motivo;
};

// 2. Funcion base del integrador (Adaptada de la imagen)
void atenderSolicitud(queue<Solicitud>& pendientes, list<Solicitud>& atendidos, stack<Solicitud>& recientes) {
    if (pendientes.empty()) {
        cout << "⚠️ No hay solicitudes pendientes por atender." << endl;
        return;
    }

    // Obtener la solicitud del frente
    Solicitud actual = pendientes.front();
    pendientes.pop(); // Saca de la cola

    // Registrar en el historial (lista)
    atendidos.push_back(actual);

    // Apilar en los mas recientes (pila)
    recientes.push(actual);

    cout << "✅ Atendido: " << actual.nombre << " (Motivo: " << actual.motivo << ")" << endl;
}

int main() {
    // Colecciones mencionadas en la imagen
    queue<Solicitud> pendientes;
    list<Solicitud> atendidos;
    stack<Solicitud> recientes;

    int opcion;

    do {
        cout << "\n--- SISTEMA INTEGRADOR ---" << endl;
        cout << "1. Agregar nueva solicitud (Queue)" << endl;
        cout << "2. Atender siguiente solicitud (Logica de la imagen)" << endl;
        cout << "3. Ver ultima solicitud atendida (Stack)" << endl;
        cout << "4. Ver historial completo (List)" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            Solicitud s;
            cout << "Cedula: "; getline(cin, s.cedula);
            cout << "Nombre: "; getline(cin, s.nombre);
            cout << "Motivo: "; getline(cin, s.motivo);
            pendientes.push(s);
            cout << "📝 Solicitud agregada a la cola." << endl;

        } else if (opcion == 2) {
            atenderSolicitud(pendientes, atendidos, recientes);

        } else if (opcion == 3) {
            if (!recientes.empty()) {
                cout << "🕒 El mas recientemente atendido fue: " << recientes.top().nombre << endl;
            } else {
                cout << "La pila esta vacia." << endl;
            }

        } else if (opcion == 4) {
            cout << "--- HISTORIAL COMPLETO ---" << endl;
            for (const auto& s : atendidos) {
                cout << "- " << s.nombre << " [" << s.motivo << "]" << endl;
            }
        }

    } while (opcion != 5);

    return 0;
}