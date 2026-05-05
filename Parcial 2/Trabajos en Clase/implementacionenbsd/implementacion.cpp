#include <iostream>
using namespace std;

// 🔹 Nodo del árbol
class TreeNode {
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode() {
        value = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};

// 🔹 Árbol BST
class BST {
public:
    TreeNode *root;

    BST() {
        root = NULL;
    }

    bool isEmpty() {
        return (root == NULL);
    }

    void insertNode(TreeNode *new_node) {
        if (root == NULL) {
            root = new_node;
            cout << "Valor insertado como root\n";
        } else {
            TreeNode *temp = root;

            while (temp != NULL) {
                if (new_node->value == temp->value) {
                    cout << "El valor ya existe\n";
                    return;
                }
                else if (new_node->value < temp->value) {
                    if (temp->left == NULL) {
                        temp->left = new_node;
                        cout << "Insertado a la izquierda\n";
                        return;
                    }
                    temp = temp->left;
                }
                else {
                    if (temp->right == NULL) {
                        temp->right = new_node;
                        cout << "Insertado a la derecha\n";
                        return;
                    }
                    temp = temp->right;
                }
            }
        }
    }

    // 🔹 Recorrido Inorden
    void inorder(TreeNode* r) {
        if (r == NULL) return;
        inorder(r->left);
        cout << r->value << " ";
        inorder(r->right);
    }
};

// 🔹 MAINgit ini
int main() {
    BST arbol;
    int valor;
    char opcion;

    do {
        cout << "\nIngrese un valor para insertar: ";
        cin >> valor;

        TreeNode* nuevo = new TreeNode(valor);
        arbol.insertNode(nuevo);

        cout << "Desea insertar otro valor? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    cout << "\nRecorrido Inorden del arbol: ";
    arbol.inorder(arbol.root);

    cout << endl;
    return 0;
}