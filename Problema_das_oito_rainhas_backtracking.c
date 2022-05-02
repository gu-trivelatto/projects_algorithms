/* Posicionar N rainhas em um tabuleiro NxN para que elas nao possam se atacar mutuamente*/

#include <stdio.h>
#include <stdlib.h>

#define NRAINHAS 8

void imprime(int L[]){
    int i;
    for(i=0; i < NRAINHAS; i++) printf("%d", L[i]);
    printf("\n");
}

int sol_valida(int L[], int n){
    int i, j;
    i = n-1;
    for(j = 0; j < i; j++){
        if(L[i] == L[j])
            return 0;
        else if(i-L[i] == j-L[j])
            return 0;
        else if(i+L[i] == j+L[j])
            return 0;
    }
    return 1;
}

void probrainhas_rec(int L[], int *n){
    int l;
    if(*n == NRAINHAS)
        imprime(L);
    else{
        for(l = 0; l < NRAINHAS; l++){
            L[*n] = l;
            (*n)++;
            if(sol_valida(L, *n))
                probrainhas_rec(L, n);
            (*n)--;
        }
    }
}

void problema_das_rainhas(){
    int L[NRAINHAS];
    int n = 0;
    probrainhas_rec(L, &n);
}

int main(){
    problema_das_rainhas();
    return 0;
}

