#include <iostream>
#include <string>
using namespace std;

int main (){ 
    string columnTitle;
    cout<<"Ingrese el título de la columna (letras mayúsculas): "<<endl;
    cin>>columnTitle;
    int result=0;
    for (int i=0;i<columnTitle.length();i++){
        int c = columnTitle[i];
        result= result * 26 + (c - 'A' + 1);
    }

    cout<<"El número de columna es: "<<result<<endl;
}