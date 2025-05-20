#include<iostream>
using namespace std;

void imprimir(int*);

int main(){
    int A[]={1,2,3,4,5};
    imprimir(A);

    return 0;
}

void imprimir(int* a){
    for(int i=4;i>=0;i--){
        cout<<*(a+i)<<endl;
    }
}