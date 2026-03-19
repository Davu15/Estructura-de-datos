#include <iostream>
#include <vector>

using namespace std;

class Reproductor{

private:
    vector<string> canciones;
    int actual;

public:

    Reproductor(){
        actual = 0;
    }

    // agregar canción
    void agregar(){

        string nombre;
        cout<<"Ingrese nombre de la cancion: ";
        cin>>nombre;

        canciones.push_back(nombre);

        cout<<"Cancion agregada\n";
    }

    // mostrar canción actual
    void mostrarActual(){

        if(canciones.size() == 0){
            cout<<"No hay canciones\n";
            return;
        }

        cout<<"Reproduciendo: "<<canciones[actual]<<endl;
    }

    // siguiente
    void siguiente(){

        if(canciones.size() == 0){
            cout<<"No hay canciones\n";
            return;
        }

        actual++;

        if(actual >= canciones.size()){
            actual = 0;
        }

        mostrarActual();
    }

    // anterior
    void anterior(){

        if(canciones.size() == 0){
            cout<<"No hay canciones\n";
            return;
        }

        actual--;

        if(actual < 0){
            actual = canciones.size() - 1;
        }

        mostrarActual();
    }

    // ?? eliminar canción
    void eliminar(){

        if(canciones.size() == 0){
            cout<<"No hay canciones para eliminar\n";
            return;
        }

        string nombre;
        cout<<"Ingrese nombre de la cancion a eliminar: ";
        cin>>nombre;

        for(int i=0;i<canciones.size();i++){

            if(canciones[i] == nombre){

                canciones.erase(canciones.begin() + i);

                cout<<"Cancion eliminada\n";

                // ajustar índice actual
                if(actual >= canciones.size()){
                    actual = 0;
                }

                return;
            }

        }

        cout<<"Cancion no encontrada\n";
    }

    // mostrar lista
    void mostrarLista(){

        if(canciones.size() == 0){
            cout<<"No hay canciones\n";
            return;
        }

        cout<<"\nLista de canciones:\n";

        for(int i=0;i<canciones.size();i++){
            cout<<i<<" - "<<canciones[i]<<endl;
        }
    }

};

int main(){

    Reproductor r;
    int op;

    do{

        cout<<"\n===== REPRODUCTOR =====\n";
        cout<<"1. Agregar cancion\n";
        cout<<"2. Mostrar actual\n";
        cout<<"3. Siguiente\n";
        cout<<"4. Anterior\n";
        cout<<"5. Eliminar cancion\n";
        cout<<"6. Mostrar lista\n";
        cout<<"7. Salir\n";

        cin>>op;

        switch(op){

            case 1: r.agregar(); break;
            case 2: r.mostrarActual(); break;
            case 3: r.siguiente(); break;
            case 4: r.anterior(); break;
            case 5: r.eliminar(); break;
            case 6: r.mostrarLista(); break;

        }

    }while(op != 7);

}
