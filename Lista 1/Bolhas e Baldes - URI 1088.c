#include "cabecalhos.h"

FILE *saida;

//Saídas: Marcelo ou Carlos
//Marcelo sempre começa

int merge(int a[], int inicio, int meio, int fim){
    int inicio1 = inicio, inicio2 = meio + 1, inicio_aux = 0, tamanho = fim - inicio + 1, contador = 0;
    int *vet_aux;
    vet_aux = MALLOC(int, tamanho);
    while(inicio1 <= meio && inicio2 <= fim){
        if(a[inicio1] < a[inicio2]){
            vet_aux[inicio_aux] = a[inicio1];
            inicio1++;
        }
        else {
            vet_aux[inicio_aux] = a[inicio2];
            inicio2++;
            contador += meio + 1 - inicio1;
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
    return contador % 2;
}

int mergeSort(int a[], int inicio, int fim){
    int contador = 0;
    if(inicio < fim){
        int meio = (fim + inicio) / 2;
        contador += mergeSort(a, inicio, meio);
        contador += mergeSort(a, meio + 1, fim);
        contador += merge(a, inicio, meio, fim);
    }
    return contador % 2;
}

int main(){
    saida = fopen("Lista 1/Outputs/Output 1088", "w");
    int n;
    scanf("%d", &n);
    while(n > 0){
        int p[n], i, trocas = 0;
        for(i = 0; i < n; i++){
            scanf("%d", &p[i]);
        }
        // int verificador, aux;
        // do{
        //     verificador = 0;
        //     for(i = 0; i < n - 1; i++){
        //         if(p[i] > p[ i + 1]){
        //             aux = p[i];
        //             p[i] = p[i + 1];
        //             p[i + 1] = aux;
        //             trocas++;
        //             verificador = 1;
        //         }
        //     }
        // }while(verificador == 1);
        trocas = mergeSort(p, 0, n - 1);
        printf("trocas: %d\n", trocas);
        if(trocas % 2 == 1){
            imprima("Marcelo\n");
        }
        else{
            imprima("Carlos\n");
        }
        scanf("%d", &n);
        fflush(saida); 
    }    
    free(saida);
    return 0;
}