#include <stdio.h>
#include <stdlib.h>

struct bloco{
    int num;
    float x;
};

int main(){
    struct bloco A;
    struct bloco *T;
    A.num = 5;
    A.x = 1.7;
    T = &A;
    T->num = 7; /* (*T).num = 7; */
    T->x = 2.5; /* (*T).x = 2.5; */
    printf("%d %f\n", A.num, A.x);
return 0;
}
