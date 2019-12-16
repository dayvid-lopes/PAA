#include "cabecalhos.h"

FILE *saida;

int main(){
    saida = fopen("Lista 1/Outputs/Output 884", "w");
    int n, x;
    scanf("%d %d", &n, &x);
    int i;
    for(i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        x -= a;
        x--;
    }
    if(x == -1 || n == 0){
        imprima("YES");
    }
    else{
        imprima("NO");
    }
    fflush(saida);
    free(saida);
    return 0;
}