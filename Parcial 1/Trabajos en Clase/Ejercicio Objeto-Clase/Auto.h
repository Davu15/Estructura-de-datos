#ifndef AUTO_H
#define AUTO_H

#include "Vehiculo.h"

// HERENCIA
class Auto : public Vehiculo{

public:
    Auto(string m="", int a=0, float p=0);

    void mostrar();
};

#endif
