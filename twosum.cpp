#include <iostream>
using namespace std;

int main (){
    int target,n,pi,pj;
    cout<<"¿Cuántos números desea ingresar?: "<<endl;
    cin>>n;
    int nums[n];

    for (int i=0;i<n;i++){
        cout<<"Ingrese el número "<<i+1<<": "<<endl;
        cin>>nums[i];
    }
    cout<<"Ingrese el número objetivo: "<<endl;
    cin>>target;
    bool encontrado = false;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (nums[i]+nums[j]==target){
                cout<<"nums=[";
                    for (int i = 0; i < n; ++i) {
                        cout << nums[i];
                        if (i != n - 1) {
                            cout << ",";
        }
    }
                cout << "]" << endl;
                                cout<<"Los números que suman el objetivo son: "<<nums[i]<<" y "<<nums[j]<<endl;
                pi=i;
                pj=j;
                cout<<"Sus posiciones en el arreglo son: ["<<pi<<","<<pj<<"]"<<endl;
                encontrado = true;

                }

            }
        }
        if (!encontrado) {
            cout << "No hay números que sumen el objetivo" << endl;
        }    
    }



