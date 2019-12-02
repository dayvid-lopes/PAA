#include "cabecalhos.h"

FILE *saida;

int main(){
    saida = fopen("Lista 1/Outputs/Output 884", "w");
    
    fflush(saida);
    free(saida);
    return 0;
}