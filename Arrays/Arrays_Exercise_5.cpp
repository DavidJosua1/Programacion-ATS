#include <iostream>
using namespace std;

void generar_arreglo(int*,int);
void encontrar_mayor(int*,int);

int main(){
    int A[100],x;
    cout<<"Ingrese el numero de elementos: ";cin>>x;
    generar_arreglo(A,x);
    encontrar_mayor(A,x);

    return 0;
}

void generar_arreglo(int* A,int x){
    for(int i=0;i<x;i++){
        cout<<"ingrese el valor de la posición "<<i<<": ";
        cin>>*(A+i);
    }
}

void encontrar_mayor(int* A,int x){
    int mayor=*(A);
    for(int i=1;i<x;i++){
        if(*(A+i)>mayor){
            mayor=*(A+i);
        }
    }

    cout<<"\nel mayor valor es: "<<mayor<<endl;
}