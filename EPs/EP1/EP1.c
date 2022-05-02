#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Vertice{
    double x;
    double y;
    struct Vertice *prox;
};
typedef struct Vertice* Poligono;

struct Vertice *InsereApos(struct Vertice *P, double x, double y){
    struct Vertice *A, *B;
    A = malloc(sizeof(struct Vertice));
    A->x = x;
    A->y = y;
    B = P;
    if (B == NULL) {
        A->prox = A;
        P = A;
    }
    else {
        A->prox = B->prox;
        B->prox = A;
    }
    return A;
}

int NumeroDeVertices(Poligono P){
    struct Vertice *A, *B;
    int i = 1;  //inicio do contador em 1 para usar incrementos apenas dentro do looping
    A = P->prox;  //A recebe P->prox para poder iniciar o looping
    while(A != P){  //ao retornar ao ponto inicial da lista o looping se encerra
        A = A->prox;
        i++;   //incremento do contador a cada endereco contabilizado
    }
    return i;
}

double Distancia(struct Vertice *A, struct Vertice *B){
    double dx, dy, d;
    dx = (A->x) - (B->x);
    dy = (A->y) - (B->y);
    d = sqrt(pow(dx, 2) + pow(dy, 2));   //calculo da distancia entre dois pontos por pitagoras
    return d;
}

double Perimetro(Poligono P){
    double per = 0, dist;
    Poligono A;
    A = P;
    do{
        dist = Distancia(A, A->prox);  //calculando o perimetro a partir das distancias entre os pontos
        A = A->prox;
        per += dist;
    } while (A != P);
    return per;
}

double Area(Poligono P){  //a area e calculada pelo metodo de determinante entre os pontos
    struct Vertice *A, *B, *fixo;
    double a = 0;
    A = P;
        a += (A->x * (A->prox)->y);
        a -= ((A->prox)->x * A->y);
    A = P->prox;
    while(A != P) {
        B = A->prox;
        a += (A->x * (A->prox)->y);
        a -= ((A->prox)->x * A->y);
        A = B;
    }
    a /= 2;
    return a;
}

void Libera(Poligono P){
    struct Vertice *N, *A;
    N = P;
    A = N->prox;
    free(N);
    N = A;
    while (N != P){
        A = N->prox;
        free(N);
        N = A;
    }
}

int main() {
    int NumVertices, vert;
    double dist, per, area, x, y;
    Poligono A = NULL;
    struct Vertice *B, *C;
    scanf ("%d", &NumVertices);
    for (int i = 0; i < NumVertices; i++) {
        scanf("%lf %lf", &x, &y);
        A = InsereApos(A, x, y);
    }
    per = Perimetro(A);
    printf ("Perimetro: %0.1lf\n", per);
    area = Area(A);
    printf ("Area: %0.1lf\n", area);
    Libera(A);
    vert = NumeroDeVertices(A);
return 0;
}
