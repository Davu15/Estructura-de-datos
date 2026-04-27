#include <iostream>  //este permite la entrada y salida de datos
#include <string>    //este permite usar la clase string para manejar cadenas de texto

int main() {
    std::cout << "Hola Mundo!";

    using namespace std; //esto permite usar el espacio de nombres std sin tener que escribirlo cada vez
    cout << "Hola mundo 2!"; //esto imprime "Hola mundo 2!" en la consola
    cout << "Hola mundo 3!" << endl; //esto imprime "Hola mundo 3!" y luego un salto de línea


    // variables 

    int num = 10;
    float pi = 3.14;
    char letra = 'A';
    bool esVerdadero = true;
    std::string mensaje = "Hola Mundo!";

        return 0;
}