#ifndef VEHICULO_H
#define VEHICULO_H

#include <iostream>
#include <string>
using namespace std;

/*
CLASE BASE
Representa la informacion general de un vehiculo
*/

class vehiculo{

protected:
    string marca;
    int anio;      //Tipo de dato primitivo
    float precio;  //Tipo de dato primitivo

public:

    vehiculo(string m="", int a=0, float p=0);

    //Metodo virtual para POLIMORFISMO
    virtual void mostrar();
};

#endif
