#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void arranjos_rec(int *v, int func, int taref, int k){
    if(k < taref){
        for(int i = k; i < func; i++){
            if(k == 0){
                v[k] = i;
                arranjos_rec(v, func, taref, k+1);
            }
            else{
                if(i > v[k-1]){
                    v[k] = i;
                    if(k == taref - 1){
                        for(int i = 0; i < taref; i++){
                            printf("%d", v[i]);
                        }
                        printf(" ");
                    }
                    if(i != func-1){
                        arranjos_rec(v, func, taref, k+1);
                    }
                }
            }

        }
    }

}

int main() {
    int funcionario = 5, tarefa = 3;
    int *tarefas;

    tarefas = (int *)malloc(tarefa*sizeof(int));

    arranjos_rec(tarefas, funcionario, tarefa, 0);

    return 0;

}
