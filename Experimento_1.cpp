#include <iostream>
#include <time.h>
using namespace std;

void Funcion_para_elegir_un_intervalo_aleatorio(int&,int&);
void Generar_matriz_aleatoria(int,double[][100],int,int);
void Imprimir_la_matriz_aleatoria(int,double[][100]);
void Funcion_para_convertir_la_matriz_en_booleana(int,int[][100],double[][100]);
void Imprimir_la_matriz_booleana(int,int[][100]);
char Funcion_para_saber_si_la_matriz_reflexiva(int[][100]);
int Funcion_recursiva_para_encontrar_la_matriz_reflexiva(int,double[][100],int,int,int[][100],int);

int main() {
    //Definiendo valores
    double A[100][100];
    int B[100][100];
    int x,izq,der,n=1;
    
    //Elegimos una matriz de orden aleatorio
    srand(time(NULL));
    x=rand()%4+2;

    cout<<"el orden de la matriz es de: "<<x<<"x"<<x<<endl;

    Funcion_para_elegir_un_intervalo_aleatorio(der,izq);

    cout<<"el intervalo de numeros en los que tomaran los elementos del par ordenado seram: ["<<izq<<" - "<<der<<"]"<<endl;

    cout<<Funcion_recursiva_para_encontrar_la_matriz_reflexiva(x,A,der,izq,B,n);
    
    return 0;
}

void Funcion_para_elegir_un_intervalo_aleatorio(int& a,int& b){
    int x=0;
    while (x<3)
    {
        a=rand()%7+3;
        b=rand()%7;
        x=a-b;
    }
    
}
void Generar_matriz_aleatoria(int x,double A[][100],int y,int w){
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            A[i][j]=rand()%(y-w+1)+w+(rand()%(y-w+1)+w)/10.0;
        }
    }
}
void Imprimir_la_matriz_aleatoria(int x,double A[][100]){
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if ((static_cast<int>(A[i][j] * 10) % 10) == 0){
                cout<<A[i][j]<<".0  ";
            }else{
                cout<<A[i][j]<<"  ";
            }
        }
        cout<<endl;
    }
}
void Funcion_para_convertir_la_matriz_en_booleana(int x,int B[][100],double A[][100]){
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){

            if(static_cast<int>(A[i][j])==(static_cast<int>((A[i][j]*10))%10)){
                B[i][j]=1;
            }
            else{
                B[i][j]=0;
            }
        }
    }
}
void Imprimir_la_matriz_booleana(int x,int B[][100]){
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            cout<<B[i][j]<<"  ";
        }
        cout<<endl;
    }
}
char Funcion_para_saber_si_la_matriz_reflexiva(int B[][100],int x){
    char flag='V';
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(i==j && B[i][j]==0){
                flag='F';
            }
        }
    }
    return flag;
}
int Funcion_recursiva_para_encontrar_la_matriz_reflexiva(int x,double A[][100],int y,int w,int B[][100],int n){ 
    Generar_matriz_aleatoria(x,A,y,w);
    cout<<endl;
    Imprimir_la_matriz_aleatoria(x,A);
    Funcion_para_convertir_la_matriz_en_booleana(x,B,A);
    cout<<endl;
    Imprimir_la_matriz_booleana(x,B);
    if(Funcion_para_saber_si_la_matriz_reflexiva(B,x)=='V'){
        cout<<endl<<"el numero de intentos es: ";
        return n;
    }else{
        n+=1;
        return Funcion_recursiva_para_encontrar_la_matriz_reflexiva(x,A,y,w,B,n);
    }
}