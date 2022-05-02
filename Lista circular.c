#include <stdio.h>
#include <stdlib.h>

void InsereAposCircular(struct Reg **p, int x){
    struct Reg *q;
    struct Reg *t;

    q = AlocaNoLista();
    q->dado = x;
    t = *p;
    if(t == NULL) {    /* para tratar lista vazia */
        q->prox = q;
        *p = q;
    }
    else {
        q->prox = t->prox;
        t->prox = q;
    }
}

void RemoveAposCircular(struct Reg **p) {
    struct Reg *q;
    struct Reg *t;
    if (t == NULL) return;
    q = t->prox;
    if (q == t) *p = NULL;
    else t->prox = q->prox;
    free(t);
}

void ImprimeCircular(struct Reg *p) {
    struct Reg *q;

    if (p == NULL) {
        printf ("Lista Vazia\n");
        return;
    }
    q = p;
    do{
        printf(" %2d", q->dado);
        q = q->prox;
    } while (q != p);
    printf("\n");
}

struct Reg * BuscaCircular(struct Reg *p, int x) {
    struct Reg *q;

    if (p == NULL) return NULL;

    q = p;
    do{
        if(q->dado == x) return q;
        q = q->prox;
    } while (q != p);

    return NULL;
}
