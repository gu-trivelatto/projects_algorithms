#include <stdio.h>
#include <stdlib.h>

//existe um quicksort no stdlib

void troca(int V[], int i, int j){
    int tmp;
    tmp = V[i];
    V[i] = V[j];
    V[j] =tmp;
}

void quicksort(int V[], int inic, int fim){

}

void intercala(int V1[], int i1, int f1, int V2[], int i2, int f2, int T[]){
    int n1, n2, nT, t, k1, k2;
    k1 = i1;
    k2 = i2;
    n1 = f1 - i1 + 1;
    n2 = f2 - i2 + 1;
    nT = n1 + n2;
    for(t = 0; t < nT; t++){                                //esta incompleto aqui
        if(k1 <= f1 && k2 <= f2){
            T[t] = V1[k1];
            k1++;
        }
        else{
            T[t] = V2[k2];
            k2++;
        }
    }
}

void mergesort(int V[], int inic, int fim){
    int m, i;
    int *T;
    if(inic < fim){
        m = (inic+fim)/2;
        mergesort(V, inic, m);
        mergesort(V, m+1, fim);

        T = malloc(sizeof(int) * (fim - inic + 1));
        intercala(V, inic, m, V, m + 1, fim, T);

        for(i = 0; i < fim - inic + 1; i++){
            V[i + inic] = T[i];
        }
        free(T);
    }
}

int main(){
    int V[] = {8,5,9,2,0,3,1,7,2};
    int i, c = 9;

    mergesort(V, 0, c - 1);

    for(i = 0; i < c; i++){
        printf("%d ", V[i]);
    }
    printf("\n");

    return 0;
}
