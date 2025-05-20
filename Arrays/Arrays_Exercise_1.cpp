#include<iostream>
using namespace std;

void suma(int*);

int main(){
    int A[]={1,2,3,4,5,6,7,8,9,10};
    suma(A);

    return 0;
}

void suma(int* A){
    int suma=0;
    for(int i=0;i<10;i++){
        suma+=*(A+i);
    }
    cout<<"la suma de los elemento del vector es: "<<suma;
}