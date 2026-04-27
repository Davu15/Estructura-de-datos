#include <iostream>
#include "Cofi.h"  //COnecta con Cofi.h
using namespace std;

// esta funcion mostrara todos los pedidos
void mostrarPedidos(Pedido pedidos[], int total){

    for(int i=0;i<total;i++){

        cout<<"\nID: "<<pedidos[i].id<<endl;
        cout<<"Cliente: "<<pedidos[i].cliente<<endl;
        cout<<"Producto: "<<pedidos[i].producto<<endl;
        cout<<"Cantidad: "<<pedidos[i].cantidad<<endl;
        cout<<"Precio: "<<pedidos[i].precio<<endl;
    }
}

//Funcion para buscar el pedido
//Devuelve la posicion donde se encuentra 
int buscarPedido(Pedido pedidos[], int total, int id){
	
	//recorre todos los pedidos
    for(int i=0;i<total;i++){
		//busca el pedido del ID
        if(pedidos[i].id==id){
            return i; //devuelve la posicion del pedido 
        }
    }
    //POR SI encuentro nada
    return -1;
}

//CALCULA EL TOTAL DE VENTAS 
void reporteFinal(Pedido pedidos[], int total){

    float totalVentas=0;
	//recorre todos los pedidos 
    for(int i=0;i<total;i++){	
		//multiplica  cantidad por precio
        totalVentas += pedidos[i].cantidad * pedidos[i].precio;
    }
    cout<<"Total de ventas: "<<totalVentas<<endl;
}
