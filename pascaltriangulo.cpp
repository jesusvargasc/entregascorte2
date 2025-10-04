#include <iostream>
using namespace std;

int main (){
    int n;
    cout<<"Ingrese el número de filas del triángulo de Pascal: "<<endl;
    cin>>n;
    int pascal[n][n];
    
    for (int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            if (j==0 || j==i){
                pascal[i][j]=1;
            } else {
                pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
            }
        }
    }
    
    cout<<"El triángulo de Pascal con "<<n<<" filas es: "<<endl;
    for (int i=0;i<n;i++){
        for (int k=n-i;k>1;k--){
            cout<<" ";
        }
        for (int j=0;j<=i;j++){
            cout<<pascal[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}