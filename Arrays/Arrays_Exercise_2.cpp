#include<iostream>
using namespace std;

void multiplicación_de_los_elementos_de_un_vector(int*);

int main(){
    int A[]={1,2,3,4,5};
    multiplicación_de_los_elementos_de_un_vector(A);

    return 0;
}

void multiplicación_de_los_elementos_de_un_vector(int* a){
    int mul=1;
    for(int i=0;i<5;i++){
        mul*=*(a+i);
    }

    cout<<"la multiplicacion acumulada es: "<<mul;
}