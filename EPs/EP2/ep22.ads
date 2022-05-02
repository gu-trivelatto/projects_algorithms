#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct _RegPilha{
 TipoDado dado;
 struct _RegPilha *prox;
} RegPilha;
typedef RegPilha* Pilha;
typedef enum boolean {false,true} bool;
RegPilha *AlocaRegPilha(){
 RegPilha* q;
 q = (RegPilha*)calloc(1, sizeof(RegPilha));
 if(q==NULL) exit(-1);
 return q;
}
Pilha CriaPilha(){
 Pilha p;
 p = AlocaRegPilha();
 p->prox = NULL;
 return p;
}
bool PilhaVazia(Pilha p){
 return (p->prox==NULL);
}
void Empilha(Pilha p, TipoDado x){
 RegPilha *q;
 q = AlocaRegPilha();
 q->dado = x;
 q->prox = p->prox;
 p->prox = q;
}
TipoDado Desempilha(Pilha p){
 RegPilha *q;
 TipoDado x;
 q = p->prox;
 if(q==NULL) exit(-1);
 x = q->dado;
 p->prox = q->prox;
 free(q);
 return x;
}
