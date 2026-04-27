#include <iostream>
#include "Auto.h"
#include "Moto.h"

using namespace std;

int main(){

    // ARREGLO ESTATICO
    Vehiculo* vehiculos[10];

    int total = 0;
    int opcion;

    do{

        cout<<"\n1 Registrar Auto";
        cout<<"\n2 Registrar Moto";
        cout<<"\n3 Mostrar";
        cout<<"\n4 Salir";
        cout<<"\nOpcion: ";
        cin>>opcion;

        if(opcion==1){

            string marca;
            int anio;
            float precio;

            cout<<"Marca: ";
            cin>>marca;

            cout<<"Anio: ";
            cin>>anio;

            cout<<"Precio: ";
            cin>>precio;

            // INSTANCIACION
            vehiculos[total] = new Auto(marca,anio,precio);

            total++;
        }

        else if(opcion==2){

            string marca;
            int anio;
            float precio;

            cout<<"Marca: ";
            cin>>marca;

            cout<<"Anio: ";
            cin>>anio;

            cout<<"Precio: ";
            cin>>precio;

            vehiculos[total] = new Moto(marca,anio,precio);

            total++;
        }

        else if(opcion==3){

            for(int i=0;i<total;i++){

                // POLIMORFISMO
                vehiculos[i]->mostrar();

                cout<<endl;
            }
        }

    }while(opcion!=4);

    return 0;
}
