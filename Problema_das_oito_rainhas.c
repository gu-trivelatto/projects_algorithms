/* Posicionar N rainhas em um tabuleiro NxN para que elas nao possam se atacar mutuamente*/

#include <stdio.h>
#include <stdlib.h>

#define NRAINHAS 4

void imprime(int L[]){
    int i;
    for(i=0; i < NRAINHAS; i++) printf("%d", L[i]);
    printf("\n");
}

void troca(int L[], int i, int j){
    int tmp;
    tmp = L[i];
    L[i] = L[j];
    L[j] = tmp;
}

int configuracaoValida(int L[]){
    int i, j;
    for(i=0; i < NRAINHAS; i++){
        for(j=0; j < NRAINHAS; j++){
            if(i != j){
                if(i+L[i] == j+L[j]) return 0;
                else if(i-L[i] == j-L[j]) return 0;
            }
        }
    }
    return 1;
}

void permutacoes_rec(int L[], int k){
    int i;
    if(k == NRAINHAS-1){
        if(configuracaoValida(L))
            imprime(L);
    }
    else{
        for(i = k; i < NRAINHAS; i++){
            troca(L, i, k);
            permutacoes_rec(L, k+1);
            troca(L, k, i);
        }
    }
}

void problema_das_rainhas(){
    int L[NRAINHAS];
    int i;
    for(i=0; i < NRAINHAS; i++) L[i] = i;
    permutacoes_rec(L, 0);
}

int main(){
    problema_das_rainhas();
    return 0;
}
