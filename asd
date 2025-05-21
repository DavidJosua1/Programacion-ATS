void convertir_a_booleana(int,int,int,int,int[][1000],int[],int[]);
convertir_a_booleana(n_filas,i_superior,i_inferior,n_elementos,A,X,Y);
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