#include "Moto.h"

Moto::Moto(string m, int a, float p) : Vehiculo(m,a,p){}

void Moto::mostrar(){

    cout<<"Tipo: Moto"<<endl;

    Vehiculo::mostrar();
}
