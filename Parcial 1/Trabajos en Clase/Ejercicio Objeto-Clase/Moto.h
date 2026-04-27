#ifndef MOTO_H
#define MOTO_H

#include "Vehiculo.h"

class Moto : public Vehiculo{

public:
    Moto(string m="", int a=0, float p=0);

    void mostrar();
};

#endif
