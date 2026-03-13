#include "Notas.h"

// Constructor
// Inicializa el tamaño del arreglo en 0
Notas::Notas(){
    n = 0;
}

// Metodo  para ingrear notas
// Permite ingresar varias notas al arreglo
void Notas::Ingresar(){

    int cantidad;

    cout<<"Cuantas notas desea ingresar: ";
    cin>>cantidad;

    for(int i=0;i<cantidad;i++){

        cout<<"Ingrese la nota "<<i+1<<": ";
        cin>>notas[n];

        // aumenta el tamaño lógico
        n++;
    }
}

// Metodo Insertar()
// Inserta una nueva nota en una posición específica
void Notas::Insertar(){

    int pos;
    float valor;

    cout<<"Ingrese la posicion donde desea insertar: ";
    cin>>pos;

    if(pos<0 || pos>n){
        cout<<"Posicion invalida"<<endl;
        return;
    }

    // mover elementos a la derecha
    for(int i=n;i>pos;i--){
        notas[i] = notas[i-1];
    }

    cout<<"Ingrese la nueva nota: ";
    cin>>valor;

    notas[pos] = valor;

    n++;
}

// Metodo Buscar()
// Busca una nota dentro del arreglo
void Notas::Buscar(){

    float valor;
    bool encontrado=false;

    cout<<"Ingrese la nota que desea buscar: ";
    cin>>valor;

    for(int i=0;i<n;i++){

        if(notas[i]==valor){

            cout<<"Nota encontrada en la posicion "<<i<<endl;
            encontrado=true;
        }
    }

    if(!encontrado){
        cout<<"Nota no encontrada"<<endl;
    }
}

// Metodo Mostrar()
// Recorre el arreglo y muestra todas las notas
void Notas::Mostrar(){

    cout<<"\nLista de notas\n";

    for(int i=0;i<n;i++){

        cout<<"Posicion "<<i<<" : "<<notas[i]<<endl;

    }
}

// Metodo Size()
// Muestra la cantidad de notas almacenadas
void Notas::Size(){

    cout<<"Cantidad de notas registradas: "<<n<<endl;

}
