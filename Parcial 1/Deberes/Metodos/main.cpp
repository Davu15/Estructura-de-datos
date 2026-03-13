#include "Notas.h"

int main(){

    Notas n;

    int op;

    do{

        cout<<"\nMENU\n";
        cout<<"1. Ingresar notas"<<endl;
        cout<<"2. Insertar nota"<<endl;
        cout<<"3. Buscar nota"<<endl;
        cout<<"4. Mostrar notas"<<endl;
        cout<<"5. Size"<<endl;
        cout<<"6. Salir (cantidad de notas)"<<endl;

        cout<<"Seleccione una opcion: ";
        cin>>op;

        switch(op){

        case 1:
            n.Ingresar();
            break;

        case 2:
            n.Insertar();
            break;

        case 3:
            n.Buscar();
            break;

        case 4:
            n.Mostrar();
            break;

        case 5:
            n.Size();
            break;

        }

    }while(op!=6);

    return 0;
}
