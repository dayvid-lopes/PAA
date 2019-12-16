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
    if(a[i] == valor){
        while(a[i + 1] == valor){
            i++;
        }
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
    int i;
    long int a[n];

    for(i = 0; i < n; i++){
        scanf("%ld", &a[i]);
    }

    indice b[m];

    for(i = 0; i < m; i++){
        b[i].posicao = i;
        scanf("%ld", &b[i].valor);
    }
    
    qsort(a, n, sizeof(int), comparador);
    qsort(b, m, sizeof(indice), comparadorValor);

    int j = 0;

    for(i = 0; i < m; i++){
        while(a[j] <= b[i].valor){
            j++;
        }
        b[i].resultado = j;
    }

    qsort(b, m, sizeof(indice), comparadorIndice);

    for(i = 0; i < m; i++){
        imprima1("%d", b[i].resultado);

        if(i == m - 1){
            imprima("\n");
        }
        else{
            imprima(" ");
        }
    }    
    
    fflush(saida);
    free(saida);
    return 0;
}