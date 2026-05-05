#include <iostream>
#include <string>

using namespace std;

// Estructura de Nodo N-ario
template <typename T>
struct Node {
    T data;
    Node<T>* firstChild;
    Node<T>* nextSibling;

    Node(T val) : data(val), firstChild(NULL), nextSibling(NULL) {}
};

// --- FUNCIÓN BUSCAR ---
template <typename T>
Node<T>* findNode(Node<T>* root, T target) {
    if (root == NULL) return NULL;
    if (root->data == target) return root;

    // Buscar en el primer hijo
    Node<T>* found = findNode(root->firstChild, target);
    if (found) return found;

    // Buscar en el siguiente hermano
    return findNode(root->nextSibling, target);
}

// --- FUNCIÓN INSERTAR ---
template <typename T>
void addChild(Node<T>* parent, T value) {
    Node<T>* newNode = new Node<T>(value);
    if (parent->firstChild == NULL) {
        parent->firstChild = newNode;
    } else {
        Node<T>* temp = parent->firstChild;
        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = newNode;
    }
}

// --- FUNCIÓN ELIMINAR ---
// Elimina un nodo y todos sus descendientes de forma recursiva
template <typename T>
void deleteSubtree(Node<T>* node) {
    if (node == NULL) return;
    deleteSubtree(node->firstChild);
    deleteSubtree(node->nextSibling);
    delete node;
}

template <typename T>
bool removeNode(Node<T>*& root, T target) {
    if (root == NULL) return false;

    // Caso especial: El nodo a eliminar es la raíz
    if (root->data == target) {
        deleteSubtree(root->firstChild);
        delete root;
        root = NULL;
        return true;
    }

    Node<T>* current = root->firstChild;
    Node<T>* prev = NULL;

    while (current != NULL) {
        if (current->data == target) {
            if (prev == NULL) {
                root->firstChild = current->nextSibling;
            } else {
                prev->nextSibling = current->nextSibling;
            }
            // Antes de borrar el nodo, borramos sus hijos
            deleteSubtree(current->firstChild);
            delete current;
            return true;
        }
        // Intentar buscar en profundidad si no es el actual
        if (removeNode(current, target)) return true;

        prev = current;
        current = current->nextSibling;
    }
    return false;
}

// --- FUNCIÓN IMPRIMIR ---
template <typename T>
void printTree(Node<T>* root, int level = 0) {
    if (root == NULL) return;
    for (int i = 0; i < level; i++) cout << "    ";
    cout << "|-- " << root->data << endl;

    printTree(root->firstChild, level + 1);
    printTree(root->nextSibling, level);
}

// --- MENÚ PRINCIPAL ---
int main() {
    Node<string>* root = new Node<string>("EMPRESA");
    int opcion;
    string nombre, padre;

    do {
        cout << "\n--- MENU ARBOL N-ARIO ---" << endl;
        cout << "1. Insertar Nodo" << endl;
        cout << "2. Buscar Nodo" << endl;
        cout << "3. Eliminar Nodo" << endl;
        cout << "4. Ver Estructura" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione: ";
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1:
                cout << "Nombre del nuevo nodo: ";
                getline(cin, nombre);
                cout << "Nombre del padre: ";
                getline(cin, padre);
                {
                    Node<string>* pNode = findNode(root, padre);
                    if (pNode) {
                        addChild(pNode, nombre);
                        cout << "Agregado con exito." << endl;
                    } else {
                        cout << "Error: Padre no encontrado." << endl;
                    }
                }
                break;

            case 2:
                cout << "Nodo a buscar: ";
                getline(cin, nombre);
                if (findNode(root, nombre))
                    cout << "El nodo '" << nombre << "' EXISTE en el arbol." << endl;
                else
                    cout << "El nodo '" << nombre << "' NO existe." << endl;
                break;

            case 3:
                cout << "Nodo a eliminar (y sus hijos): ";
                getline(cin, nombre);
                if (nombre == "EMPRESA") {
                    cout << "No se puede eliminar la raiz principal desde aqui." << endl;
                } else if (removeNode(root, nombre)) {
                    cout << "Nodo eliminado." << endl;
                } else {
                    cout << "Nodo no encontrado." << endl;
                }
                break;

            case 4:
                cout << "\nESTRUCTURA ACTUAL:" << endl;
                printTree(root);
                break;
        }
    } while (opcion != 5);

    return 0;
}