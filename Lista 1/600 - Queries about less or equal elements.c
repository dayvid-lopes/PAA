#include "cabecalhos.h"

FILE *saida;

typedef struct indice{
    int posicao;
    int valor;
}indice;

int comparador(const void *a, const void *b){
    return (*(int*)a) - (*(int*)b);
}

int comparadorValor(const void *a, const void *b){
    return (*(indice*)a).valor - (*(indice*)b).valor;
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

void merge(indice a[], int inicio, int meio, int fim){
    int inicio1 = inicio, inicio2 = meio + 1, inicio_aux = 0, tamanho = fim - inicio + 1;
    indice *vet_aux;
    vet_aux = MALLOC(indice, tamanho);
    while(inicio1 <= meio && inicio2 <= fim){
        if(a[inicio1].valor < a[inicio2].valor){
            vet_aux[inicio_aux] = a[inicio1];
            inicio1++;
        }
        else {
            vet_aux[inicio_aux] = a[inicio2];
            inicio2++;
        }
        inicio_aux++;
    }

    while(inicio1 <= meio){
        vet_aux[inicio_aux] = a[inicio1];
        inicio_aux++;
        inicio1++;
    }

    while(inicio2 <= fim){
        vet_aux[inicio_aux] = a[inicio2];
        inicio_aux++;
        inicio2++;
    }

    for(inicio_aux = inicio; inicio_aux <= fim; inicio_aux++){
        a[inicio_aux] = vet_aux[inicio_aux - inicio];
    }
    free(vet_aux);
}

void mergeSort(indice a[], int inicio, int fim){
    if(inicio < fim){
        int meio = (fim + inicio) / 2;
        mergeSort(a, inicio, meio);
        mergeSort(a, meio + 1, fim);
        merge(a, inicio, meio, fim);
    }
}

int main(){
    saida = fopen("Lista 1/Outputs/Output 600", "w");
    int n, m;
    scanf("%d %d", &n, &m);
    int i;
    indice a[n + m];

    for(i = 0; i < n; i++){
        a[m + i].posicao = -1;
        scanf("%d", &a[m + i].valor);
    }

    for(i = 0; i < m; i++){
        a[i].posicao = i;
        scanf("%d", &a[i].valor);
    }
    
    mergeSort(a, 0, n + m - 1);

    int j = 0, resultado[m], cont = 0;

    for(i = 0; i < m; i++){
        while(j < n + m && a[j].posicao == -1){
            j++;
            cont++;
        }
        if(j < n + m){
            resultado[a[j].posicao] = cont;
            j++;
        }
    }

    for(i = 0; i < m; i++){
        imprima1("%d", resultado[i]);

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