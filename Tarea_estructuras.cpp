#include<iostream>
#include<cmath>
using namespace std;
int X[1000],Y[1000],A[1000][1000],B[1000][1000], C[1000][1000];
void generar_matriz_aleatoria(int&,int&,int&,int&,int[],int[],int[][1000]);
void calcular_intervalo_aleatorio(int*,int*);
void determinar_numero_de_elementos_de_la_relacion(int*,int*,int,int);
void generar_relacio_aleatoria(int[],int[],int,int,int);
void imprimir_relacion(int[],int[],int);
void convertir_a_booleana(int,int,int,int,int[][1000],int[],int[]);
void disyuncion_de_matrices(int&,int&,int&,int&,int[],int[],int[][1000],int[][1000]);
void conjuncion_de_matrices(int&,int&,int&,int&,int[],int[],int[][1000],int[][1000]);
void producto_de_matrices(int&,int&,int&,int&,int[],int[],int[][1000],int[][1000]);
void encontrar_matriz_reflexiva(int&,int&,int&,int&,int[],int[],int[][1000],int[][1000]);
void encontrar_matriz_irreflexiva(int&,int&,int&,int&,int[],int[],int[][1000],int[][1000]);
void imprimir_matriz(int[][1000],int);
void imprimir_matriz1(int[][1000],int);

int main(){

    int i_inferior,i_superior,n_elementos,n_filas,x;
    srand(time(NULL));
    cout<<"\ningrese un numero dependiendo de lo que busque\n";
    cin>>x;
    switch (x)
    {
    case 1:disyuncion_de_matrices(i_inferior,i_superior,n_elementos,n_filas,X,Y,A,B);
        break;
    case 2:conjuncion_de_matrices(i_inferior,i_superior,n_elementos,n_filas,X,Y,A,B);
        break;
    case 3:producto_de_matrices(i_inferior,i_superior,n_elementos,n_filas,X,Y,A,B);
        break;
    case 4:encontrar_matriz_reflexiva(i_inferior,i_superior,n_elementos,n_filas,X,Y,A,B);
        break;
    case 5:encontrar_matriz_irreflexiva(i_inferior,i_superior,n_elementos,n_filas,X,Y,A,B);
        break;
    default:
        break;
    }

    
    
    return 0;
}

void calcular_intervalo_aleatorio(int* i_inferior,int* i_superior){
    int x;
    x=0;
    while (x<2)
    {
        *i_superior=rand()%4+2;
        *i_inferior=rand()%4;
        x=*i_superior-*i_inferior;
    }
    cout<<"El intervalo de numeros que se tomara es: ["<<*i_inferior<<"-"<<*i_superior<<"]";
}
void determinar_numero_de_elementos_de_la_relacion(int* n_elementos,int* n_filas,int i_superior,int i_inferior){
    *n_filas=i_superior-i_inferior+1;
    *n_elementos=rand()%(*n_filas**n_filas)+1;
}
void generar_relacio_aleatoria(int X[],int Y[],int n_elementos,int i_superior,int i_inferior){
    for (int i = 0; i < n_elementos; i++) {
        bool repetido;
        do {
            repetido = false;
            X[i] = rand() % (i_superior-i_inferior+1) + i_inferior;
            Y[i] = rand() % (i_superior-i_inferior+1) + i_inferior;

            for (int j = 0; j < i; j++) {
                if (X[i] == X[j] && Y[i] == Y[j]) {
                    repetido = true;
                    break;
                }
            }
        } while (repetido);
    }

}
void imprimir_relacion(int X[],int Y[],int n_elementos){
     cout<<"\nLa relacion es: [";
    for (int i = 0; i < n_elementos; i++)
    {
        cout<<"{"<<X[i]<<","<<Y[i]<<"}";
        if(n_elementos-1!=i){
            cout<<",";
        }
    }
    cout<<"]"<<endl;

}
void convertir_a_booleana(int n_filas,int i_superior,int i_inferior,int n_elementos,int A[][1000],int X[],int Y[]){
    for(int i=0;i<n_filas;i++){
        for(int j=0;j<n_filas;j++){
            bool indicar=false;
            for(int z=0;z<n_elementos;z++){
                if(X[z]==i+i_inferior&&Y[z]==j+i_inferior){
                    indicar=true;
                    break;
                }
            }
            if(indicar){
                A[i][j]=1;
            }else{
                A[i][j]=0;
            }
        }
    }
}
void generar_matriz_aleatoria(int& i_inferior, int& i_superior, int& n_elementos, int& n_filas, int X[], int Y[], int A[][1000]) {
    calcular_intervalo_aleatorio(&i_inferior, &i_superior);
    determinar_numero_de_elementos_de_la_relacion(&n_elementos, &n_filas, i_superior, i_inferior);
    generar_relacio_aleatoria(X, Y, n_elementos, i_superior, i_inferior);
    imprimir_relacion(X, Y, n_elementos);
    convertir_a_booleana(n_filas, i_superior, i_inferior, n_elementos, A, X, Y);
}
void imprimir_matriz(int A[][1000],int n_filas){
        cout << "\nMatriz booleana:\n";
    for (int i = 0; i < n_filas; i++) {
        for (int j = 0; j < n_filas; j++) {
          cout << A[i][j] << "  ";
        }
    cout << endl;
    }
}
void imprimir_matriz1(int A[][1000],int n_filas){
        cout << "\n";
    for (int i = 0; i < n_filas; i++) {
        for (int j = 0; j < n_filas; j++) {
          cout << A[i][j] << "  ";
        }
    cout << endl;
    }
}
void disyuncion_de_matrices(int& i_inferior, int& i_superior, int& n_elementos, int& n_filas, int X[], int Y[], int A[][1000],int B[][1000]){
    calcular_intervalo_aleatorio(&i_inferior, &i_superior);
    cout<<"\nPara la primera matriz: \n";
    determinar_numero_de_elementos_de_la_relacion(&n_elementos, &n_filas, i_superior, i_inferior);
    generar_relacio_aleatoria(X, Y, n_elementos, i_superior, i_inferior);
    imprimir_relacion(X, Y, n_elementos);
    convertir_a_booleana(n_filas, i_superior, i_inferior, n_elementos, A, X, Y);
    imprimir_matriz(A,n_filas);
    cout<<"\nPara la segunda matriz: \n";
    determinar_numero_de_elementos_de_la_relacion(&n_elementos, &n_filas, i_superior, i_inferior);
    generar_relacio_aleatoria(X, Y, n_elementos, i_superior, i_inferior);
    imprimir_relacion(X, Y, n_elementos);
    convertir_a_booleana(n_filas, i_superior, i_inferior, n_elementos, B, X, Y);
    imprimir_matriz(B,n_filas);
    cout<<"\nA ∨ B es: \n";

    for(int i=0;i<n_filas;i++){
        for(int j=0;j<n_filas;j++){
            if(A[i][j]==1||B[i][j]==1){
                C[i][j]=1;
            }else{
                C[i][j]=0;
            }
        }
    }
    imprimir_matriz1(C,n_filas);
}
void conjuncion_de_matrices(int& i_inferior, int& i_superior, int& n_elementos, int& n_filas, int X[], int Y[], int A[][1000],int B[][1000]){
    calcular_intervalo_aleatorio(&i_inferior, &i_superior);
    cout<<"\nPara la primera matriz: \n";
    determinar_numero_de_elementos_de_la_relacion(&n_elementos, &n_filas, i_superior, i_inferior);
    generar_relacio_aleatoria(X, Y, n_elementos, i_superior, i_inferior);
    imprimir_relacion(X, Y, n_elementos);
    convertir_a_booleana(n_filas, i_superior, i_inferior, n_elementos, A, X, Y);
    imprimir_matriz(A,n_filas);
    cout<<"\nPara la segunda matriz: \n";
    determinar_numero_de_elementos_de_la_relacion(&n_elementos, &n_filas, i_superior, i_inferior);
    generar_relacio_aleatoria(X, Y, n_elementos, i_superior, i_inferior);
    imprimir_relacion(X, Y, n_elementos);
    convertir_a_booleana(n_filas, i_superior, i_inferior, n_elementos, B, X, Y);
    imprimir_matriz(B,n_filas);
    cout<<"\nA ∧ B es: \n";

    for(int i=0;i<n_filas;i++){
        for(int j=0;j<n_filas;j++){
            if(A[i][j]==1&&B[i][j]==1){
                C[i][j]=1;
            }else{
                C[i][j]=0;
            }
        }
    }
    imprimir_matriz1(C,n_filas);
}
void producto_de_matrices(int& i_inferior, int& i_superior, int& n_elementos, int& n_filas, int X[], int Y[], int A[][1000],int B[][1000]){
    calcular_intervalo_aleatorio(&i_inferior, &i_superior);
    cout<<"\nPara la primera matriz: \n";
    determinar_numero_de_elementos_de_la_relacion(&n_elementos, &n_filas, i_superior, i_inferior);
    generar_relacio_aleatoria(X, Y, n_elementos, i_superior, i_inferior);
    imprimir_relacion(X, Y, n_elementos);
    convertir_a_booleana(n_filas, i_superior, i_inferior, n_elementos, A, X, Y);
    imprimir_matriz(A,n_filas);
    cout<<"\nPara la segunda matriz: \n";
    determinar_numero_de_elementos_de_la_relacion(&n_elementos, &n_filas, i_superior, i_inferior);
    generar_relacio_aleatoria(X, Y, n_elementos, i_superior, i_inferior);
    imprimir_relacion(X, Y, n_elementos);
    convertir_a_booleana(n_filas, i_superior, i_inferior, n_elementos, B, X, Y);
    imprimir_matriz(B,n_filas);
    cout<<"\nProducto de matrices booleanas\n";
        for(int i=0;i<n_filas;i++){
            for(int j=0;j<n_filas;j++){
                bool contador=false;
                for(int z=0;z<n_filas;z++){
                    if(A[i][z]==1&&B[z][j]==1){
                        contador=true;
                        break;
                    }
                }
                if(contador){
                        C[i][j]=1;
                }else{
                        C[i][j]=0;
                 }
            }
        }
    imprimir_matriz1(C,n_filas);
}
void encontrar_matriz_reflexiva(int& i_inferior, int& i_superior, int& n_elementos, int& n_filas, int X[], int Y[], int A[][1000],int B[][1000]){
    calcular_intervalo_aleatorio(&i_inferior, &i_superior);
    cout<<"\n\n";
    bool Reflexiva=true;
    int iteraciones=0;
    while (Reflexiva)
    {   
        iteraciones++;
        int cont=0;
        cout<<"iteracion numero: "<<iteraciones;
        determinar_numero_de_elementos_de_la_relacion(&n_elementos, &n_filas, i_superior, i_inferior);
        generar_relacio_aleatoria(X, Y, n_elementos, i_superior, i_inferior);
        imprimir_relacion(X, Y, n_elementos);
        convertir_a_booleana(n_filas, i_superior, i_inferior, n_elementos, A, X, Y);
        imprimir_matriz(A,n_filas);
        for(int i=0;i<n_filas;i++){
             if(A[i][i]==1){
                cont++;
             }
        }
        if(cont==n_filas){
            Reflexiva=false;
        }
        cout<<endl;
    }
    cout<<"el numero de iteraciones necesarias4 fue: "<<iteraciones<<endl;
}
void encontrar_matriz_irreflexiva(int& i_inferior, int& i_superior, int& n_elementos, int& n_filas, int X[], int Y[], int A[][1000],int B[][1000]){
    calcular_intervalo_aleatorio(&i_inferior, &i_superior);
    cout<<"\n\n";
    bool Reflexiva=true;
    int iteraciones=0;
    while (Reflexiva)
    {   
        iteraciones++;
        int cont=0;
        cout<<"iteracion numero: "<<iteraciones;
        determinar_numero_de_elementos_de_la_relacion(&n_elementos, &n_filas, i_superior, i_inferior);
        generar_relacio_aleatoria(X, Y, n_elementos, i_superior, i_inferior);
        imprimir_relacion(X, Y, n_elementos);
        convertir_a_booleana(n_filas, i_superior, i_inferior, n_elementos, A, X, Y);
        imprimir_matriz(A,n_filas);
        for(int i=0;i<n_filas;i++){
             if(A[i][i]==0){
                cont++;
             }
        }
        if(cont==n_filas){
            Reflexiva=false;
        }
        cout<<endl;
    }
    cout<<"el numero de iteraciones necesarias4 fue: "<<iteraciones<<endl;
}