#include <stdio.h>
#include <stdlib.h>

void InsereLista(struct Reg **p; int x) {
    struct Reg *q;
    struct Reg *t;

    t = *p;
    q = AlocaNaLista();
    q->dado = x;
    q->prox = t;
    *p = q;
}

void RemoveLista(struct Reg **p) {
    struct Reg *p;

    t = *p;
    if (t != NULL) {
        *p = t->prox;
        free(t);
    }
}
