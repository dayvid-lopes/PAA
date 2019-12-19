#include "cabecalhos.h"

FILE *saida;

//Saídas: Marcelo ou Carlos
//Marcelo sempre começa

int main(){
    saida = fopen("Lista 1/Outputs/Output 1088", "w");
    int n;
    scanf("%d", &n);
    while(n > 0){
        int p[n], i;
        for(i = 0; i < n; i++){
            scanf("%d", &p[i]);
        }
        
        scanf("%d", &n);
    }    
    fflush(saida);
    free(saida);
    return 0;
}