#include<iostream>
using namespace std;

void generar_matriz(int[][100],int,int);
void suma_de_matrices(int[][100],int[][100],int[][100],int,int);
void imprimir_matriz(int[][100],int,int);

int main(){
   int A[100][100],B[100][100],C[100][100],x,y;
   cout<<"ingrese el numero de filas: ";cin>>x;
   cout<<"ingrese el numero de columnas: ";cin>>y;
   cout<<"Para la matriz A \n";
   generar_matriz(A,x,y);
   cout<<"Para la matriz B \n";
   generar_matriz(B,x,y);
   suma_de_matrices(A,B,C,x,y);
   cout<<"La suma de matrices es \n";
   imprimir_matriz(C,x,y);
   
    return 0;
}

void generar_matriz(int A[][100],int x,int y){
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<"ingrese el valor de la posición :"<<i<<"-"<<j<<endl;
            cin>>A[i][j];
        }
    }
}
void suma_de_matrices(int A[][100],int B[][100],int C[][100],int x,int y){
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
}
void imprimir_matriz(int A[][100],int x,int y){
     for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
