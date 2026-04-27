#include <iostream>
   #include <string>

   using namespace std;

   // 1. Estructura básica de los datos
   struct Solicitud {
       string nombreEstudiante;
       string descripcion;
   };

   // 2. Nodo genérico que usarán nuestras estructuras de datos
   struct Nodo {
       Solicitud dato;
       Nodo* siguiente;
      
       // Constructor del nodo
       Nodo(Solicitud s) {
           dato = s;
           siguiente = nullptr;
       }
   };

   // ==========================================
   // ESTRUCTURA 1: QUEUE (COLA) PARA PENDIENTES
   // ==========================================
   class ColaPendientes {
   private:
       Nodo* frente;
       Nodo* final;

   public:
       ColaPendientes() {
           frente = nullptr;
           final = nullptr;
       }

       void encolar(Solicitud s) {
           Nodo* nuevoNodo = new Nodo(s);
           if (frente == nullptr) {
               frente = nuevoNodo;
               final = nuevoNodo;
           } else {
               final->siguiente = nuevoNodo;
               final = nuevoNodo;
           }
       }

       bool estaVacia() {
           return frente == nullptr;
       }

       // Retorna la solicitud y la elimina de la cola
       Solicitud desencolar() {
           if (estaVacia()) {
               return {"", ""}; // Retorno vacío por seguridad
           }
           Nodo* temp = frente;
           Solicitud s = temp->dato;
           frente = frente->siguiente;
          
           if (frente == nullptr) {
               final = nullptr;
           }
          
           delete temp;
           return s;
       }

       void mostrar() {
           Nodo* actual = frente;
           if (!actual) cout << "  - No hay solicitudes pendientes.\n";
           while (actual != nullptr) {
               cout << "  - [" << actual->dato.nombreEstudiante << "] " << actual->dato.descripcion << "\n";
               actual = actual->siguiente;
           }
       }
   };

   // ==========================================
   // ESTRUCTURA 2: LIST (LISTA) PARA HISTORIAL
   // ==========================================
   class ListaHistorial {
   private:
       Nodo* cabeza;
       Nodo* cola; // Mantenemos un puntero al final para insertar en O(1)

   public:
       ListaHistorial() {
           cabeza = nullptr;
           cola = nullptr;
       }

       void agregar(Solicitud s) {
           Nodo* nuevoNodo = new Nodo(s);
           if (cabeza == nullptr) {
               cabeza = nuevoNodo;
               cola = nuevoNodo;
           } else {
               cola->siguiente = nuevoNodo;
               cola = nuevoNodo;
           }
       }

       void mostrar() {
           Nodo* actual = cabeza;
           if (!actual) cout << "  - El historial esta vacio.\n";
           while (actual != nullptr) {
               cout << "  - [" << actual->dato.nombreEstudiante << "] " << actual->dato.descripcion << "\n";
               actual = actual->siguiente;
           }
       }
   };

   // ==========================================
   // ESTRUCTURA 3: STACK (PILA) PARA RECIENTES
   // ==========================================
   class PilaRecientes {
   private:
       Nodo* tope;

   public:
       PilaRecientes() {
           tope = nullptr;
       }

       void apilar(Solicitud s) {
           Nodo* nuevoNodo = new Nodo(s);
           nuevoNodo->siguiente = tope;
           tope = nuevoNodo;
       }

       void mostrarRecientes(int cantidad = 3) {
           Nodo* actual = tope;
           int contador = 0;
           if (!actual) cout << "  - No hay solicitudes recientes.\n";
           while (actual != nullptr && contador < cantidad) {
               cout << "  - [" << actual->dato.nombreEstudiante << "] " << actual->dato.descripcion << "\n";
               actual = actual->siguiente;
               contador++;
           }
       }
   };

   // ==========================================
   // CLASE INTEGRADORA: SISTEMA DEL LABORATORIO
   // ==========================================
   class Laboratorio {
   private:
       ColaPendientes pendientes;
       ListaHistorial historial;
       PilaRecientes recientes;

   public:
       // Recibe una solicitud y la pone en la cola (espera)
       void recibirSolicitud(string nombre, string descripcion) {
           Solicitud nueva = {nombre, descripcion};
           pendientes.encolar(nueva);
           cout << "[+] Solicitud recibida: " << nombre << " - " << descripcion << "\n";
       }

       // Atiende al primero de la cola y lo mueve al historial y a recientes
       void atenderSiguiente() {
           if (pendientes.estaVacia()) {
               cout << "[!] No hay estudiantes esperando en la cola.\n";
               return;
           }

           Solicitud atendida = pendientes.desencolar();
          
           // Guardamos en ambas estructuras según lo requerido
           historial.agregar(atendida);
           recientes.apilar(atendida);

           cout << "[v] Solicitud ATENDIDA: " << atendida.nombreEstudiante << "\n";
       }

       void verPendientes() {
           cout << "\n--- COLA DE ESPERA (Pendientes) ---\n";
           pendientes.mostrar();
       }

       void verHistorialCompleto() {
           cout << "\n--- HISTORIAL COMPLETO (Atendidos) ---\n";
           historial.mostrar();
       }

       void verUltimosAtendidos() {
           cout << "\n--- ULTIMOS ATENDIDOS (Recientes) ---\n";
           recientes.mostrarRecientes(3); // Muestra los últimos 3 por defecto
       }
   };

   // ==========================================
   // PROGRAMA PRINCIPAL
   // ==========================================
   int main() {
       Laboratorio lab;

       cout << "=========================================\n";
       cout << "       EJECUCION DE CASOS DE PRUEBA      \n";
       cout << "=========================================\n";

       // ---------------------------------------------------------
       // PRUEBA 1: Cola vacía
       // ---------------------------------------------------------
       cout << "\n[PRUEBA 1] Cola vacia: intentar atender sin registros\n";
       // Comportamiento esperado: El sistema debe detectar que está vacía y no fallar.
       lab.atenderSiguiente();

       // ---------------------------------------------------------
       // PRUEBA 2: Un estudiante
       // ---------------------------------------------------------
       cout << "\n[PRUEBA 2] Un estudiante: agregar y atender una sola vez\n";
       lab.recibirSolicitud("Zoe", "Uso de multimetro");
       lab.atenderSiguiente();
       // Comprobacion: La cola debe quedar vacía tras atenderla.
       lab.verPendientes();

       // ---------------------------------------------------------
       // PRUEBA 3: Varios estudiantes (FIFO en pendientes)
       // ---------------------------------------------------------
       cout << "\n[PRUEBA 3] Varios estudiantes: verificar FIFO en pendientes\n";
       lab.recibirSolicitud("Alberto", "Cautin");
       lab.recibirSolicitud("Beatriz", "Fuente de poder");
       lab.recibirSolicitud("Carmen", "Protoboard");
      
       cout << "\nEstado inicial FIFO (Debe mostrar: Alberto -> Beatriz -> Carmen):\n";
       lab.verPendientes();
      
       cout << "\nAtendiendo al primero (Debe salir Alberto):\n";
       lab.atenderSiguiente();
      
       cout << "\nEstado despues de atender (Debe quedar: Beatriz -> Carmen):\n";
       lab.verPendientes();

       // ---------------------------------------------------------
       // PRUEBA 4: Historial completo (List)
       // ---------------------------------------------------------
       cout << "\n[PRUEBA 4] Historial: revisar orden completo cronologico\n";
       // Atendemos a los restantes para mandar sus registros al historial
       lab.atenderSiguiente(); // Atiende a Beatriz
       lab.atenderSiguiente(); // Atiende a Carmen
      
       // Comportamiento esperado: Debe mostrar el orden exacto en que fueron atendidos
       // Zoe -> Alberto -> Beatriz -> Carmen
       lab.verHistorialCompleto();

       // ---------------------------------------------------------
       // PRUEBA 5: Recientes (Stack)
       // ---------------------------------------------------------
       cout << "\n[PRUEBA 5] Recientes: confirmar ultimo atendido arriba\n";
       // Comportamiento esperado: La pila (Stack) es LIFO.
       // Si los ultimos fueron Alberto, Beatriz y Carmen (en ese orden),
       // la pila debe mostrar de arriba hacia abajo: Carmen -> Beatriz -> Alberto
       lab.verUltimosAtendidos();

       cout << "\n=========================================\n";
       cout << "           PRUEBAS FINALIZADAS           \n";
       cout << "=========================================\n";

       // ---------------------------------------------------------
   // CASO 2: Verificación de la política FIFO en Pendientes
   // ---------------------------------------------------------
   cout << "=== CASO 2: Verificacion de la politica FIFO en Pendientes ===" << endl;
  
   // Acción: Ingresan consecutivamente los estudiantes
   lab.recibirSolicitud("Alberto", "Uso de Cautin");
   lab.recibirSolicitud("Beatriz", "Fuente de poder");
   lab.recibirSolicitud("Carmen", "Protoboard");
  
   cout << "\nAccion: Se atiende una sola solicitud." << endl;
   // El sistema debe extraer a "Alberto" (el más antiguo)
   lab.atenderSiguiente();
  
   // Resultado comprobado: La cola retiene únicamente a "Beatriz" y "Carmen"
   cout << "\nResultado comprobado - Estado de la cola de espera:";
   lab.verPendientes();

   cout << "\n--------------------------------------------------------------\n\n";

   // ---------------------------------------------------------
   // CASO 3: Verificación de la política LIFO en Recientes
   // ---------------------------------------------------------
   cout << "=== CASO 3: Verificacion de la politica LIFO en Recientes ===" << endl;
  
   // Acción: Tras atender a Alberto (en el caso anterior), se atiende a Beatriz y Carmen.
   cout << "Accion: Se atiende a Beatriz y Carmen en ese orden cronologico." << endl;
   lab.atenderSiguiente(); // Atiende a Beatriz
   lab.atenderSiguiente(); // Atiende a Carmen
  
   // Resultado comprobado: La pila muestra a Carmen en la cima, seguida de Beatriz y Alberto.
   cout << "\nResultado comprobado - Ultimos atendidos (Inversion cronologica):";
   lab.verUltimosAtendidos();

   return 0;
   }