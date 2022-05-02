#include <stdio.h>
#include <stdlib.h>

typedef int TipoDado;

typedef struct _RegDupla{
    struct _RegDupla *esq;
    TipoDado          dado;
    struct _RegDupla *dir;
} RegDupla;

typedef RegDupla* ListaDupla

/* ListaDupla é um tipo abstrato que está sendo implementado */

RegDupla* AlocaRegDupla(){
    RegDupla* q;
    q = (RegDupla*)calloc(1, sizeof(RegDupla));
    if(q==NULL) exit(-1);
    return q;
}

ListaDupla CriaNoCabecaDupla(){   /* O apontador que referencia a lista inteira deve apontar para o nó cabeça */
    RegDupla* p;
    p = AlocaRegDupla();
    p->dado = -1;
    p->esq = p;
    p->dir = p;
    return p;
}

void ImprimeListaDuplaCircular(ListaDupla p){ /*está imprimindo o nó cabeça também*/
    RegDupla *q;
    q = p;
    do{
        ImprimeElemento(q->dado);
        q = q->dir;
    }while(q != p);
    printf("\n");
}

void ImprimeListaDuplaCircularReversa(ListaDupla p){
    RegDupla *q;
    q = p;
    do{
        ImprimeElemento(q->dado);
        q = q->esq;
    }while(q != p);
    printf("\n");
}

/*insere após o nó apontado por p */
void InsereDuplaCircular(ListaDupla p, TipoDado x){
    RegDupla *q;
    q = AlocaRegDupla();
    q->dado = x;
    q->dir = p->dir;
    q->esq = p;
    (p->dir)->esq = q;
    p->dir = q;
}

/*listas duplamente ligadas premitem a remoção do proóprio nó passado como argumento. Cuidado para não remover o nó-cabeça*/
void RemoveDuplaCircular(ListaDupla p){
    (p->esq)->dir = p->dir;
    (p->dir)->esq = p->esq;
    free(p);
}

