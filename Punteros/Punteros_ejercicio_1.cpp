#include <iostream>
using namespace std;

void par_impar(int*);

int main(){
    int a;
    cout<<"ingrese el numero\n";
    cin>>a;
    par_impar(&a);

    return 0;
}
void par_impar(int* a){
    if(*a%2==0){
        cout<<"el numero es par\n";
        cout<<"su direccion de memoria es: "<<a;
    } else{
        cout<<"el numero es impar\n";
        cout<<"su direccion de memoria es: "<<a;
    }
}
