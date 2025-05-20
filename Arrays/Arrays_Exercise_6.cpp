#include <iostream>
using namespace std;

void comparar(int[],int);

int main(){
    int A[]={1,2,3,4,5,15};
    comparar(A,6);

    return 0;
}
void comparar(int A[],int x){
    for(int i=0;i<x;i++){
        int suma=0;
        int temp=*(A+i);
        for(int j=0;j<x;j++){
            if(*(A+j)!=temp){
                suma+=*(A+j);
            }
        }
        if (temp==suma){
            cout<<endl<<temp<<" es la suma de los demas elementos\n";
        }
    }
}