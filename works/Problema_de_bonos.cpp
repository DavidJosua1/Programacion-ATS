#include <iostream>
using namespace std;

int main(){
    int bono,A[100],n_trabajador,sueldo,años_de_trabajo,desempeño;
    cout<<"ingrese la cantidad de trabajadores: ";cin>>n_trabajador;

    for(int i=0;i<n_trabajador;i++){
        double bono_por_Antiguedad;
        cout<<"ingrese el sueldo del trabajador: ";cin>>sueldo;
        cout<<"ingrese la Antiguedad del trabajador en años: ";cin>>años_de_trabajo;
        
        if(años_de_trabajo>6){
            bono_por_Antiguedad=15.0/100*sueldo;
        }else if(años_de_trabajo>4){
            bono_por_Antiguedad=10.0/100*sueldo;
        }else if(años_de_trabajo>1){
            bono_por_Antiguedad=5.0/100*sueldo;
        }else{
            bono_por_Antiguedad=0;
        }
        cout<<"El trabajador: "<<i+1<<" tendra un bono de: "<<bono_por_Antiguedad;
    }
}