#include <stdio.h>
#include <stdlib.h>

void imprime(int s[], int k){
    int i;
    for(i = 1; i <= k; i++){
        printf("%d", s[i]);
    }
    printf("\n");
}

void SubConjuntos_rec(int s[], int k, int m, int n){
    if(m <= n){
        s[k+1] = m;
        imprime(s, k+1);
        SubConjuntos_rec(s, k+1, m+1, n);
        SubConjuntos_rec(s, k, m+1, n);
    }
}

void SubConjuntos(int n){
    int *s;
    s = malloc(sizeof(int)*(n+1));
    SubConjuntos_rec(s, 0, 1, n);
    free(s);
}

int main() {
    int n;

    printf("Digite n: ");
    scanf("%d", &n);

    SubConjuntos(n);

    return 0;
}

