#include "cabecalhos.h"

FILE *saida;

int verificarPalavraChave(char s[], int i, int tamanho_minimo){
    int final = strlen(s) - 1, retorno;
    if(i > final - 1){
        imprima1("i = %d\n", i);
        return -1;
    }
    if(s[i] == s[final] && tamanho_minimo <= i){
        int j;
        for(j = 0; j < i; j++){
            if(s[j] != s[final - i + j]){
                retorno = verificarPalavraChave(s, i + 1, tamanho_minimo);
                return retorno;
            }
        }
        return i + 1;
    }
    retorno = verificarPalavraChave(s, i + 1, tamanho_minimo);
    return retorno;
}

void calcularNext(char p[], int tamanho_p, int next[]){
    int i, j;
    next[0] = -1;
    next[1] = 0;
    for(i = 2; i < tamanho_p; i++){
        j = next[i - 1] + 1;
        while(j > 0 && p[i - 1] != p[j - 1]){
            j = next[j - 1] + 1;
        }
        next[i] = j;
    }
}

int KMP(char t[], int tamanho_t, char p[], int tamanho_p){
    int next[tamanho_p];
    calcularNext(p, tamanho_p, next);
    int j = 0, i = 0, index = -1;
    for(i = 0; i < tamanho_p; i++){
        // printf("%d\t", next[i]);
    }
    printf("\n");
    i = 0;
    while(index == -1 && i < tamanho_t){
        if(p[j] == t[i]){
            j++;
            i++;
        }
        else{
            j = next[j];
            if(j == -1){
                j++;
                i++;
            }
        }
        if(j == tamanho_p){
            index = i - tamanho_p;
        }
    }
    return index;
}

int main(){
    saida = fopen("Lista 1/Outputs/Output 126", "w");
    char s[1000002];
    scanf("%s", s);
    int tamanho_s;
    tamanho_s = strlen(s);
    int tamanho_palavra_chave[tamanho_s], tamanho_min, indice_tamanho_palavra_chave = -1;
    // tamanho_palavra_chave[0] = -1;
    tamanho_min = -1;
    do{
        tamanho_min++;
        indice_tamanho_palavra_chave++;
        tamanho_palavra_chave[indice_tamanho_palavra_chave] = verificarPalavraChave(s, 0, tamanho_min);
        printf("indice: %d\ttamanho: %d\n", indice_tamanho_palavra_chave, tamanho_palavra_chave[indice_tamanho_palavra_chave]);
    }while(indice_tamanho_palavra_chave < tamanho_s - 1 && tamanho_palavra_chave[indice_tamanho_palavra_chave] > 0);
    printf("tamanho inicial: %d\n", tamanho_palavra_chave[0]);
    if(tamanho_palavra_chave[0] != -1){
        indice_tamanho_palavra_chave--;
        printf("indice final: %d\n", indice_tamanho_palavra_chave);
        int i, tamanho_aux = tamanho_s - 2, resultado;
        char t[tamanho_palavra_chave[indice_tamanho_palavra_chave]], aux[tamanho_aux + 1];

        for(i = 1; i < tamanho_s - 1; i++){
            aux[i - 1] = s[i];
            aux[i] = '\0';
        }

        do{
            for(i = 0; i < tamanho_palavra_chave[indice_tamanho_palavra_chave]; i++){
                t[i] = s[i];
                t[i + 1] = '\0';
                printf("i = %d\n", i);
            }
            resultado = KMP(aux, tamanho_aux, t, tamanho_palavra_chave[indice_tamanho_palavra_chave]);
            while(indice_tamanho_palavra_chave > 0 && tamanho_palavra_chave[indice_tamanho_palavra_chave] == tamanho_palavra_chave[indice_tamanho_palavra_chave - 1]){
                indice_tamanho_palavra_chave--;
            }
            indice_tamanho_palavra_chave--;
        }while(resultado == -1 && indice_tamanho_palavra_chave >= 0);
        printf("%s = %d\n%s = %d\n", aux, tamanho_aux, t, tamanho_palavra_chave[0]);
        imprima1("%s\n", KMP(aux, tamanho_aux, t, tamanho_palavra_chave[0]) == -1 ? "Just a legend" : t);
        imprima1("%d\n", KMP(aux, tamanho_aux, t, tamanho_palavra_chave[0]));
        imprima1("%d\n", tamanho_palavra_chave[0]);
    }
    else{
        imprima("Just a legend\n");
        printf("saiu\n");
    }
    
    fflush(saida);
    free(saida);
    return 0;
}