#include <stdio.h>
#include <stdlib.h>

void troca(char S[], int i, int j){
    char tmp;
    tmp = S[i];
    S[i] = S[j];
    S[j] = tmp;
}

void permutacoes_rec(char S[], int k, int n){
    int i;
    if(k == n-1){
        printf("%s\n", S);
    }
    else{
        for(i = k; i < n; i++){
            troca(S, i, k);
            permutacoes_rec(S, k+1, n);
            troca(S, k, i);
        }
    }
}

void permutacoes(char S[]){
    int n;
    n = strlen(S);
    permutacoes_rec(S, 0, n);
}

int main(){
    char S[] = "ABC";

    permutacoes(S);

    return 0;
}
