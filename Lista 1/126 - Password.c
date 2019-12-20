#include "cabecalhos.h"

FILE *saida;

int main(){
    saida = fopen("Lista 1/Outputs/Output 126", "w");
    char s[1000001];
    scanf("%s", s);
    imprima1("%s\n", s);
    fflush(saida);
    free(saida);
    return 0;
}