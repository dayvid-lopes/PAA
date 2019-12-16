#include "cabecalhos.h"

FILE *saida;

typedef struct indice{
    int posicao;
    long int valor;
    int resultado;
}indice;

int comparador(const void *a, const void *b){
    return (*(int*)a) - (*(int*)b);
}

int comparadorValor(const void *a, const void *b){
    return (*(indice*)a).valor - (*(indice*)b).valor;
}

int comparadorIndice(const void *a, const void *b){
    return (*(indice*)a).posicao - (*(indice*)b).posicao;
}

int buscaBinaria(int a[], int inicio, int fim, int valor){
    int i = (fim + inicio) / 2;
    if(inicio == fim){
        return inicio;
    }
    if(inicio == i){
        return i;
    }
    if(a[i] == valor){
        return i;
    }
    if(a[i] < valor){
        return buscaBinaria(a, i + 1, fim, valor);
    }
    return buscaBinaria(a, inicio, i - 1, valor);
}

int main(){
    saida = fopen("Lista 1/Outputs/Output 600", "w");
    int n, m;
    scanf("%d %d", &n, &m);
    int i, a[n], b[m];
 
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < m; i++){
        scanf("%d", &b[i]);
    }
    
    qsort(a, n, sizeof(int), comparador);
 
    int j, resultado = 0;
 
    for(i = 0; i < m; i++){
        resultado = buscaBinaria(a, 0, n, b[i]);
        while(resultado < n && a[resultado] <= b[i]){
            resultado++;
        }
 
        printf("%d", resultado);
 
        if(i == m - 1){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
    
    fflush(saida);
    free(saida);
    return 0;
}