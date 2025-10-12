#include <iostream>
using namespace std;

int main (){
    int n;
    cout<<"Ingrese el número de días: "<<endl;
    cin>>n;
    int price[n];
    for (int i=0;i<n;i++){
        cout<<"Ingrese el precio del día "<<i+1<<": "<<endl;
        cin>>price[i];
    }
    int gananciamax=0;
    for(int i=0;i<n-1;i++){
            for (int j = i + 1; j < n; j++){
                int ganancia = price[j] - price[i];

                if (ganancia > gananciamax) {
                    gananciamax = ganancia; 


            }

        }
    }
    cout<<"la ganancia maxima es: "<<gananciamax<<endl;
}


 
