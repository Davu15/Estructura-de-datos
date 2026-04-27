#include "Auto.h"

Auto::Auto(string m, int a, float p) : Vehiculo(m,a,p){}

// POLIMORFISMO
void Auto::mostrar(){

    cout<<"Tipo: Auto"<<endl;

    Vehiculo::mostrar();
}
