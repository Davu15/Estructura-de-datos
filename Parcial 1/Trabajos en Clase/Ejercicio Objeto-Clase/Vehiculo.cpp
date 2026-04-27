#include "Vehiculo.h"

/*
CONSTRUCTOR
*/
Vehiculo::Vehiculo(string m, int a, float p){
    marca = m;
    anio = a;
    precio = p;
}

/*
Metodo mostrar
*/
void Vehiculo::mostrar(){

    cout<<"Marca: "<<marca<<endl;
    cout<<"Anio: "<<anio<<endl;
    cout<<"Precio: "<<precio<<endl;
}
