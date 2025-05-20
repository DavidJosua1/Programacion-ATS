#include<iostream>
using namespace std;

void multiplicar_por_dos(int*,int*,int);
void generar_arreglo(int*,int);
void imprimir(int*,int);

int main(){
    int A[100], B[100],x;
    cout<<"ingrese el numero de elementos: ";cin>>x;
    generar_arreglo(A,x);
    multiplicar_por_dos(A,B,x);
    imprimir(B,x);

}

void multiplicar_por_dos(int* A,int* B,int x){
    for(int i=0;i<x;i++){
        *(B+i)=2**(A+i);
    }
}
void generar_arreglo(int* A,int x){
    for(int i=0;i<x;i++){
        cout<<"ingrese el numero de la posicion: "<<i<<": ";cin>>*(A+i);
    }
}
void imprimir(int* a,int x){
    cout<<"\nEl arreglo multiplicado por dos es: \n";
    for(int i=0;i<x;i++){
        cout<<*(a+i)<<endl;
    }
}