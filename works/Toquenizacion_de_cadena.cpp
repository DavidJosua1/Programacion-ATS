#include<iostream>
using namespace std;

int main(){
    char texto[100][100];
    int x,palabra=0;
    cout<<"Ingrese el numero de toquens(palabras) que se creara: ";cin>>x;
    while (palabra<x&&cin>>texto[palabra])
    {
        palabra++;
    }

    cout<<"\nse mostrara los toquens obtenidos: \n";
    for(int i=0;i<x;i++){
        cout<<texto[i]<<endl;
    }
}

