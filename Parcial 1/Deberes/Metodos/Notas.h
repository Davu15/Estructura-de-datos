#ifndef NOTAS_H
#define NOTAS_H

#include <iostream>
using namespace std;

class Notas{

private:

    // Arreglo que almacena las notas
    float notas[20];

    // Tamaño del arreglo
    int n;

public:

    // Constructor para iniciar el tamaño en 0
    Notas();

    // Permite ingresar varias notas
    void Ingresar();

    // Inserta una nota en una posicion especifica
    void Insertar();

    // Busca una nota dentro del arreglo
    void Buscar();

    // Muestra todas las notas registradas
    void Mostrar();

    // Muestra cuantas notas hay
    void Size();

};

#endif
