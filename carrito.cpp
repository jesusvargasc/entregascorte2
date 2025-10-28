#include <iostream>
using namespace std;
#include <string>
#include <vector>

class producto(){

public:
    vector<vector<string>> productos;
    string s;
    string nombre;
    int precios;
    auto stock;
}

 void agregar(){ 
    cout<<"Desea agregar un producto?(si/no): "<<endl;
    cin>>s;
    while s == "si"{
        cout<<"¿De que tipo es el producto?: "<<endl;
        cin>>ItemProducto.tipop;
        cout<<"Escriba el nombre del producto: "<<endl;
        cin>>producto.nombre;
        cout<<"Escriba el precio del producto: "<<endl;
        cin>>producto.precios>>endl;
        cout<<"Escriba la cantidad en stock: "<<endl;
        cin>>producto.stock;
        productos.push_back({producto.nombre,producto.precios,producto.stock,ItemProducto.tipop});
        
        cout<<"¿Desea agregar un nuevo producto? (si/no): "<<endl;
        cin>>s;

        
    }


    void calcular(){
    }

}


class ItemProducto(){

Public:
    
    
    string tipop;
    
    void mostrarinfo(){

            for (int i = 0; i < datos.size(); i++) {
                for (int j = 0; j < datos[i].size(); j++) {
                    cout << datos[i][j] << " ";
                }
                cout << endl;
            }

    }

}
class CarritoCompras(){

}

   
