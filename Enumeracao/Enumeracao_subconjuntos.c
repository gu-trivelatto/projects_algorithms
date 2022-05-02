#include <stdio.h>
#include <stdlib.h>

void imprime(int s[], int k){
    int i;
    for(i = 1; i <= k; i++){
        printf("%d", s[i]);
    }
    printf("\n");
}

void SubConjuntos(int n){
    int *s;
    int k;
    s = malloc(sizeof(int)*(n+1));
    s[0] = 0;
    k = 0;
    while(1){
        if(s[k] < n){
            s[k+1] = s[k] + 1;
            k++;
        }
        else{
            s[k-1] += 1;
            k--;
        }
        if(k == 0) break;
        imprime(s, k);
    }


    free(s);
}

int main() {
    int n;

    printf("Digite n: ");
    scanf("%d", &n);

    SubConjuntos(n);

    return 0;
}
