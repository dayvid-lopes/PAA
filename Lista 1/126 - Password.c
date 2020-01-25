#include "cabecalhos.h"

FILE *saida;

int verificarPalavraChave(char s[], int i, int tamanho_minimo){
    int final = strlen(s) - 1, retorno;
    if(i > final - 2){
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

int verificarPalavraChaveMaxima(char s[], int i, int final){
    int retorno;
    if(i < 0){
        return -1;
    }
    if(s[i] == s[final] && 0 <= i){
        int j;
        for(j = 0; j < i; j++){
            if(s[j] != s[final - i + j]){
                retorno = verificarPalavraChaveMaxima(s, i - 1, final);
                return retorno;
            }
        }
        return i + 1;
    }
    retorno = verificarPalavraChaveMaxima(s, i - 1, final);
    return retorno;
}

void calcularNext(char p[], int tamanho_p, int next[]){
    int i, j;
    next[0] = -1;
    next[1] = 0;
    imprima("-1, 0");
    for(i = 2; i < tamanho_p; i++){
        j = next[i - 1] + 1;
        while(j > 0 && p[i - 1] != p[j - 1]){
            j = next[j - 1] + 1;
        }
        next[i] = j;
        imprima1(", %d", j);
    }
    imprima("\n");
}
 
int KMP(char t[], int tamanho_t, char p[], int tamanho_p){
    int next[tamanho_p];
    calcularNext(p, tamanho_p, next);
    int j = 0, i = 0, index = -1;
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
    printf("%s\n", s);
    tamanho_s = strlen(s);
    int tamanho_palavra_chave[tamanho_s], tamanho_maximo, indice_tamanho_palavra_chave = 0;
    tamanho_maximo = tamanho_s - 2;

    tamanho_palavra_chave[indice_tamanho_palavra_chave] = verificarPalavraChaveMaxima(s, tamanho_maximo, tamanho_s - 1);
    printf("tamanho palavra chave: %d\ntamanho string: %d\n", tamanho_palavra_chave[0], tamanho_s);
    if(tamanho_palavra_chave[0] > 0){
        int i, tamanho_aux = tamanho_s - 2, resultado = -1, indice_maximo = indice_tamanho_palavra_chave;
        char t[tamanho_palavra_chave[0]], aux[tamanho_aux + 1];

        for(i = 1; i < tamanho_s - 1; i++){
            aux[i - 1] = s[i];
        }
        aux[i - 1] = '\0';
        do{
            for(i = 0; i < tamanho_palavra_chave[indice_tamanho_palavra_chave]; i++){
                t[i] = s[i];
            }
            t[i] = '\0';
            resultado = KMP(aux, tamanho_aux, t, tamanho_palavra_chave[indice_tamanho_palavra_chave]);
            if(tamanho_maximo == tamanho_palavra_chave[indice_tamanho_palavra_chave]){
                tamanho_maximo--;
            }
            else{
                tamanho_maximo = tamanho_palavra_chave[indice_tamanho_palavra_chave] - 2;
            }
            indice_tamanho_palavra_chave++;
            tamanho_palavra_chave[indice_tamanho_palavra_chave] = verificarPalavraChaveMaxima(s, tamanho_maximo, tamanho_s - 1);
        }while(resultado == -1 && tamanho_palavra_chave[indice_tamanho_palavra_chave] > 0);
        printf("%s\n", (resultado == -1) ? "Just a legend" : t);
    }
    else{
        printf("Just a legend\n");
    }
    for(int i = 0; i < 100000; i++){
        imprima("j");
    }
    imprima("\n");
    // for(int i = 0; i < 1000000; i++){
    //     imprima("a");
    // }
    
    fflush(saida);
    free(saida);
    return 0;
}