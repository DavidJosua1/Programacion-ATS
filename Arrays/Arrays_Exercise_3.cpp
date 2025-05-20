#include <iostream>
using namespace std;

void mostrar(int*);

int main(){
    int A[]={1,2,3,4,5};
    mostrar(A);

    return 0;
}
void mostrar(int* a){
    for(int i=0;i<5;i++){
        cout<<*(a+i)<<" su indice es: "<<i<<endl;
    }
}