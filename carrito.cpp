#include <iostream>
using namespace std;
#include <string>

class producto(){

public:

    string nombre;
    int precios;
    auto stock;
}

class ItemProducto(){

Public:

    string tipop;
    int cantidad;    
    void mostrarinfo(){
        cout<<"Nombre: "<<producto.nombre<<endl;
        cout<<"Precio: "<<producto.precios<<endl;
        cout<<"Tipo: "<<tipop<<endl;
    }

class CarritoCompras(){

    void agregar(){ 

        cout<<"¿De que tipo es el producto?: "<<endl;
        cin>>ItemProducto.tipop;
        cout<<"Escriba el nombre del producto: "<<endl;
        cin>>producto.nombre;
        cout<<"Escriba el precio del producto: "<<endl;
        cin>>producto.precios>>endl;
        cout<<"Escriba la cantidad en stock: "<<endl;
        cin>>producto.stock;

    void calcular(){
    }

}
}
