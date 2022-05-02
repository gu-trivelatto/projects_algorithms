#include <stdio.h>
#include <stdlib.h>

struct bloco{
    int num;
    struct bloco *prox;
};

void ImprimeLista(struct bloco *P) {
    struct bloco *T;
    T = P;
    while(T != NULL) {
        printf("%d ", T->num);
        T = T->prox;
    }
    printf ("\n");
}

void LiberaLista(struct bloco *P) {
    struct bloco *T, *X;
    T = P;
    while(T != NULL){
        X = T->prox;
        free(T);
        T = X;
    }
}

int main(){
    struct bloco *L = NULL; /* indica que a lista inicia vazia */
    struct bloco *N;
    for (int i = 0; i < 4; i++){
        N = (struct bloco *)malloc(sizeof(struct bloco));
        N->num = i;
        N->prox = L;     /* a cada nó adicionado a lista vai aumentando para trás, por isso deslocamos o L */
        L = N;           /* o L deve sempre referenciar o começo da lista para poder acessar os outros nós */
    }
    ImprimeLista(L);
    LiberaLista(L);
return 0;
}
