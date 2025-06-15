#include<iostream>
using namespace std;
class matriz{
    int fila;
    int columna;
    int Datos[10][10];
    public:
    matriz();
    void leer_datos();
    void cambiar_dimension();
    void mostrar_datos();
    void sumar_matriz(matriz,matriz);
    matriz operator+ (const matriz);
};
matriz:: matriz(){
    fila=2;
    columna=2;
}
void matriz:: leer_datos(){
    for(int i=0;i<fila;i++){
        for(int j=0;j<columna;j++){
            cout<<"ingrese datos para la matriz: ";cin>>Datos[i][j];
        }
    }
}
void matriz:: cambiar_dimension(){
    cout<<"ingrese fila: ";cin>>fila;
    cout<<"ingrese columna: ";cin>>columna;
}
void matriz:: mostrar_datos(){
    for (int i = 0; i < fila; i++){
        for (int j = 0; j < columna; j++){
            cout<<Datos[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
void matriz:: sumar_matriz(matriz a,matriz b){
    for(int i=0;i<fila;i++){
        for(int j=0;j<columna;j++){
            Datos[i][j]=a.Datos[i][j]+b.Datos[i][j];
        }
    }
}
matriz matriz:: operator+ (const matriz B){
    matriz suma;
    for(int i=0;i<fila;i++){
        for(int j=0;j<columna;j++){
            suma.Datos[i][j]=Datos[i][j]+B.Datos[i][j];
        }
    }
    return suma;
}
int main(){
    matriz A,B,C;
    A.leer_datos();
    B.leer_datos();
    C=A+B;
    C.mostrar_datos();
    return 0;
}