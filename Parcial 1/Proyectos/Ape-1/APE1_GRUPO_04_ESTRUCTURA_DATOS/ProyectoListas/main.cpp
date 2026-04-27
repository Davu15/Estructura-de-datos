#include <iostream>
#include <string>

using namespace std;

// =====================================================================
//                 ZONA DEL EQUIPO 1: LISTA SIMPLE
// =====================================================================

// 1. Plantilla del Nodo Simple
template <typename T>
class Nodo {
public:
    T info;
    Nodo<T>* siguiente;

    Nodo(T valor) {
        info = valor;
        siguiente = 0;
    }
};

// 2. Plantilla de la Lista Simple
template <typename T>
class ListaSimple {
private:
    Nodo<T>* primero;
    Nodo<T>* ultimo;

public:
    ListaSimple() {
        primero = 0;
        ultimo = 0;
    }

    void insertarInicio(T valor) {
        // TODO Equipo 1: L�gica aqu�
    }

    void insertarFinal(T valor) {
        // TODO Equipo 1: L�gica aqu� (Actualizar puntero 'ultimo')
    }

// 1. Buscar valor
    bool buscar(T valor) {
        Nodo<T>* actual = primero;
        while (actual != nullptr) {
            if (actual->info == valor) return true;
            actual = actual->siguiente;
        }
        return false;
    }

    // 2. Eliminar valor (Cuidado con los punteros)
    void eliminar(T valor) {
        if (primero == nullptr) return;
        Nodo<T>* actual = primero;
        Nodo<T>* anterior = nullptr;

        while (actual != nullptr && actual->info != valor) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (actual != nullptr) {
            if (actual == primero) {
                primero = primero->siguiente;
                if (primero == nullptr) ultimo = nullptr;
            } else {
                anterior->siguiente = actual->siguiente;
                if (actual == ultimo) ultimo = anterior;
            }
            delete actual;
            cout << "Eliminado correctamente." << endl;
        }
    }

    // 3. Mostrar lista
    void mostrarLista() {
        Nodo<T>* actual = primero;
        while (actual != nullptr) {
            cout << actual->info << " -> ";
            actual = actual->siguiente;
        }
        cout << "NULL" << endl;
    }

    // 4. Consultar primero y ultimo
    void consultarPrimeroUltimo() {
        if (primero != nullptr && ultimo != nullptr) {
            cout << "Primero: " << primero->info << ", Ultimo: " << ultimo->info << endl;
        }
    }
};


// =====================================================================
//                 ZONA DEL EQUIPO 2: LISTA DOBLE
// =====================================================================

// 3. Plantilla del Nodo Doble
template <typename T>
class NodoDoble {
public:
    T info;
    NodoDoble<T>* sig;
    NodoDoble<T>* ant;

    NodoDoble(T valor) {
        info = valor;
        sig = 0;
        ant = 0;
    }
};

// 4. Plantilla de la Lista Doble
template <typename T>
class ListaDoble {
private:
    NodoDoble<T>* primero;
    NodoDoble<T>* ultimo;

public:
    ListaDoble() {
        primero = 0;
        ultimo = 0;
    }

    void insertarInicio(T valor) {
        NodoDoble<T>* nuevo = new NodoDoble<T>(valor); //Defino un espacio en memoria para el nodo doble
        											   //el "*" indica que la variable nuevo sera un puntero
    	if(primero == 0){	//Esta estructura de control valida si existe nodos en la lista, si no 
    						//coloca al valor "nuevo" como head y tail
    		primero = nuevo;
    		ultimo = nuevo;
		}else{
			nuevo->sig = primero; //concatenamos a "nuevo" con el viejo primero
			primero->ant = nuevo; //Ahora el viejo primero reconoce a "nuevo" como su antecesor
			primero = nuevo; //como ultimo "nuevo" pasa a ser el primero en la fila
		}
	}

    void insertarFinal(T valor) {
        NodoDoble<T>* nuevo = new NodoDoble<T>(valor); //nuevamente se crea el espacio en memoria para el nodo doble
        if(ultimo == 0){
        	primero = nuevo;
        	ultimo = nuevo;
		} else{
			nuevo->ant = ultimo; //el antecesor de nuevo sera ahora ultimo
			ultimo->sig = nuevo; //asignamos a nuevo como lo que le sigue despues a ultimo
			ultimo = nuevo; //ahora nuevo pasa a ser el nuevo ultimo
			
		}
    }

    bool buscar(T valor) {
        NodoDoble<T>* actual = primero; // creacion de un nodo que sirve para realizar el recorrido con el while
        while(actual != 0){
        	if(actual->info == valor){ //aqui pregunta si, actual es equivalente al valor que busco?
        		return true; 		   //si es asi retornaria true
			}
			actual=actual->sig; //esta linea permite avanzar al siguiente nodo para que nuevamente compare
		}        
        return false; //Al recorrer toda la lista y no encontrar el valor a buscar se retorna "false"
    }

    void eliminar(T valor) {
    	
    	//Si primero es nulo, entonces la lista esta vacia
    	if(primero==0){
    		cout <<"La lista esta vacia";
    		return;
		}else if(primero->info==valor){//Si el valor es el primero
			if(primero->sig==0){//solo hay un nodo
			delete primero;
			primero=0; //liberamos memoria
			ultimo=0;
			}else{//Hay mas nodos
			NodoDoble<T>* curr2 = primero ->sig; //Nodo auxiliar que apunte al elemento siguiente
			primero->sig->ant=0;//reasignamos el anterior del nodo siguiente a cero
			delete primero;//eliminamos el nodo primero
			primero=curr2;//reasignamos el puntero primero
			}
		}else if(ultimo->info==valor){//Si el valor es el ultimo
			NodoDoble <T> *curr3 = ultimo->ant;
        	ultimo->ant->sig=0;
        	delete ultimo;
        	ultimo=curr3;
    	}else{//El valor este en medio de la lista

    		NodoDoble<T>* curr = primero;
    		while(curr!= 0 ){
    			if(curr->info == valor){
    				NodoDoble<T>* prev = curr->ant;
    				NodoDoble<T>* next = curr->sig;
    				
    				prev->sig=next;
    				next->ant=prev;
    				
    				curr->sig=0;
    				curr->ant=0;
    				
    				delete curr;
    				return;
				}
				curr=curr->sig;
			}

				cout<<"El valor no existe en la lista"<<endl;
				
			
		}
	}

    void mostrarInicioAFin() {
        // Verificamos si la lista est� vac�a
        if (primero == 0) {
            cout << "La lista esta vacia\n";
            return;
        }

        NodoDoble<T>* curr = primero;
        cout << "Inicio -> Fin: ";
        
        // Recorremos usando 'sig'
        while (curr != 0) {
            cout << curr->info;
            if (curr->sig != 0) {
                cout << " <-> "; // Separador visual para listas dobles
            }
            curr = curr->sig;
        }
        cout << endl;
    }

    void mostrarFinAInicio() {
        // Verificamos si la lista est� vac�a
        if (ultimo == 0) {
            cout << "La lista esta vacia\n";
            return;
        }

        NodoDoble<T>* curr = ultimo;
        cout << "Fin -> Inicio: ";
        
        // Recorremos usando 'ant'
        while (curr != 0) {
            cout << curr->info;
            if (curr->ant != 0) {
                cout << " <-> "; // Separador visual para listas dobles
            }
            curr = curr->ant;
        }
        cout << endl;
    }
    
    

    void consultarPrimeroUltimo() {
        if (primero != 0 && ultimo != 0) {
            cout << "Primero: " << primero->info << " | Ultimo: " << ultimo->info << endl;
        } else {
            cout << "La lista esta vacia." << endl;
        }
    }
};


// =====================================================================
//                 ZONA DE PRUEBAS (MAIN)
// =====================================================================

int main() {
    ListaDoble<string> miPlaylist;
    int opcion;
    string cancion;

    do {
        cout << "\n--- GESTOR DE PLAYLIST (Equipo 2) ---" << endl;
        cout << "1. Insertar cancion al INICIO" << endl;
        cout << "2. Insertar cancion al FINAL" << endl;
        cout << "3. Buscar cancion" << endl;
        cout << "4. Eliminar cancion" << endl;
        cout << "5. Mostrar de Inicio a Fin" << endl;
        cout << "6. Mostrar de Fin a Inicio" << endl;
        cout << "7. Ver Primero y Ultimo" << endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear(); 
            fflush(stdin); 
            cout << "Error: Por favor, ingrese un numero valido para el menu." << endl;
            continue;
        }

        switch (opcion) {
            case 1:
                cout << "Nombre de la cancion: ";
                fflush(stdin); 
                getline(cin, cancion);
                miPlaylist.insertarInicio(cancion);
                break;

            case 2:
                cout << "Nombre de la cancion: ";
                fflush(stdin);
                getline(cin, cancion);
                miPlaylist.insertarFinal(cancion);
                break;

            case 3:
                cout << "Cancion a buscar: ";
                fflush(stdin);
                getline(cin, cancion);
                if (miPlaylist.buscar(cancion)) {
                    cout << "�Si esta en la lista!" << endl;
                } else {
                    cout << "No se encontro." << endl;
                }
                break;

            case 4:
                cout << "Cancion a eliminar: ";
                fflush(stdin);
                getline(cin, cancion);
                miPlaylist.eliminar(cancion);
                break;

            case 5:
                miPlaylist.mostrarInicioAFin();
                break;

            case 6:
                miPlaylist.mostrarFinAInicio();
                break;

            case 7:
                miPlaylist.consultarPrimeroUltimo();
                break;

            case 0:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (opcion != 0);

    return 0;
}
