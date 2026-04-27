#include <iostream>
#include "Cofi.h"  //CONECTA AL MAIN con al estructura y funciones 
using namespace std;

int main(){

    Pedido pedidos[50];	//vector de estructuras 
    int total = 10;		//numero de registros iniciales 
    int opcion;			//menu 
    int id;				//buscador de pedido
    int pos;			//posicion para encontrar el pedido en el vector

    // 10 registros iniciales
    pedidos[0]={1,"David","Cafe",2,1.50};
    pedidos[1]={2,"Estiven","Capuccino",1,2.00};
    pedidos[2]={3,"Jeampierre","Latte",2,2.50};
    pedidos[3]={4,"Pablo","Cafe",3,1.50};
    pedidos[4]={5,"Cesar","Mocaccino",1,2.80};
    pedidos[5]={6,"Diana","Cafe",2,1.50};
    pedidos[6]={7,"Cristian","Latte",1,2.50};
    pedidos[7]={8,"Snaider","Capuccino",2,2.00};
    pedidos[8]={9,"Shirley","Cafe",1,1.50};
    pedidos[9]={10,"Lesly","Latte",2,2.50};
	
	//Menu interactivos 
    do{

        cout<<"\n===== CAFETERIA ====="<<endl;
        cout<<"1 Registrar pedido"<<endl;
        cout<<"2 Mostrar pedidos"<<endl;
        cout<<"3 Buscar pedido"<<endl;
        cout<<"4 Modificar pedido"<<endl;
        cout<<"5 Eliminar pedido"<<endl;
        cout<<"6 Reporte final"<<endl;
        cout<<"7 Salir"<<endl;
        cout<<"Seleccione opcion: ";
        cin>>opcion;

        switch(opcion){
        case 1:
			cout<<"Recuer verificar los ID existentes"
            cout<<"ID: ";
            cin>>pedidos[total].id;

            cout<<"Cliente: ";
            cin>>pedidos[total].cliente;

            cout<<"Producto: ";
            cin>>pedidos[total].producto;

            cout<<"Cantidad: ";
            cin>>pedidos[total].cantidad;

            cout<<"Precio: ";
            cin>>pedidos[total].precio;

            total++;
        break;
        case 2:

            mostrarPedidos(pedidos,total);
        break;
        case 3:

            cout<<"Ingrese ID: ";
            cin>>id;

            pos = buscarPedido(pedidos,total,id);

            if(pos!=-1)
                cout<<"Cliente: "<<pedidos[pos].cliente<<endl;
            else
                cout<<"No encontrado"<<endl;
        break;
        case 4:

            cout<<"ID a modificar: ";
            cin>>id;

            pos = buscarPedido(pedidos,total,id);

            if(pos!=-1){

                cout<<"Nuevo cliente: ";
                cin>>pedidos[pos].cliente;

                cout<<"Nuevo producto: ";
                cin>>pedidos[pos].producto;

                cout<<"Nueva cantidad: ";
                cin>>pedidos[pos].cantidad;

                cout<<"Nuevo precio: ";
                cin>>pedidos[pos].precio;

            }
        break;
        case 5:

            cout<<"ID a eliminar: ";
            cin>>id;

            pos = buscarPedido(pedidos,total,id);

            if(pos!=-1){

                for(int i=pos;i<total-1;i++){

                    pedidos[i] = pedidos[i+1];

                }

                total--;
            }
        break;
        case 6:

            reporteFinal(pedidos,total);
        break;
        }
    }while(opcion!=7);  //El programa se repetira hasta que se seleccione el 7
    return 0;
}
