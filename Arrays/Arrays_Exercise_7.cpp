#include<iostream>
using namespace std;

void unir_cadena(char*,char*,char*);
void mostrar_cadena(char*);

int main(){
    char A[]={'a','b','c','\0'};
    char B[]={'d','e','f','\0'};
    char C[6];
    unir_cadena(A,B,C);
    mostrar_cadena(C);
    return 0;
}
void unir_cadena(char* A,char* B,char* C){
    for(int i=0;i<6;i++){
        if(i<3){
            *(C+i)=*(A+i);
        }else{
            *(C+i)=*(B+i-3);
        }
    }
}

void mostrar_cadena(char*  C){
    for(int i=0;i<6;i++){
        cout<<*(C+i)<<endl;
    }
}