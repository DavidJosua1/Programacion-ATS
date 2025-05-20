#include<iostream>
using namespace std;

void establecer_en_cero(int[],int);
void votar(int[],int,int);
void resultados(int[],int);
void ganador(int[],int);

int main(){
    int c_votantes,n_candidatos, votos[100];
    cout<<"ingrese el numero de candidatos: ";cin>>n_candidatos;
    cout<<"ingrese el numero de votantes: ";cin>>c_votantes;
    establecer_en_cero(votos,n_candidatos);
    votar(votos,c_votantes,n_candidatos);
    resultados(votos,n_candidatos);
    ganador(votos,n_candidatos);

    return 0;
}
void establecer_en_cero(int A[],int c){
    for(int i=0;i<c;i++){
        A[i]=0;
    }
}
void votar(int A[],int x,int c){
    cout<<endl;
    for(int i=0;i<x;i++){
        int x;
        cout<<"ingrese por que candidato votara: ";
        cin>>x;
        for(int i=0;i<c;i++){
            if(x==i+1){
                A[i]++;
            }
        }
    }
}
void resultados(int A[],int c){
    cout<<endl;
    for(int i=0;i<c;i++){
        cout<<"la cantidad de votos del candidato "<<i+1<<" es: "<<A[i]<<endl;
    }
}
void ganador(int A[],int c){

    int puntaje=A[0],candidato=1;
    for(int i=1;i<c;i++){
        if(A[i]>puntaje){
            puntaje=A[i];
            candidato=i+1;
        }
    }
    cout<<"\nEl ganador es el candidato "<<candidato<<" con un total de votos de: "<<puntaje<<endl;
}