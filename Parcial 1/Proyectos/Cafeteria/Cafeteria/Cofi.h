#ifndef COFI_H
#define COFI_H

#include <string>
using namespace std;

// estructura del pedido 
struct Pedido{
    int id;              //identificador del pedido
    string cliente;      //nombre del cliente
    string producto;	// producto que compra
    int cantidad;		// cantidad del producto
    float precio;       
};

//Declaracion de las funciones
//aqui solo se anuncian las funciones que aparecen en Cofi.cpp
void mostrarPedidos(Pedido pedidos[], int total);
int buscarPedido(Pedido pedidos[], int total, int id);
void reporteFinal(Pedido pedidos[], int total);

#endif
