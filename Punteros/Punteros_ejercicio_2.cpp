#include<iostream>
using namespace std;

void numero_primo(int*);

int main(){
    int a;
    cout<<"ingrese el numero:\n";cin>>a;
    numero_primo(&a);

    return 0;

}

void numero_primo(int* a){
    char band='V';
    for(int i=2;i<*a;i++){
        if(*a%i==0){
            band='F';
        }
    }
    if(band=='V' && *a!=1){
        cout<<"el numero es primo\n";
        cout<<"su dirección de memoria es: "<<a<<endl;
    }else{
        cout<<"el numero no es primo\n";
        cout<<"su dirección de memoria es: "<<a<<endl;
    }

}