#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *p;
    scanf("%d", &n);
    printf("\n");
    p = (int *)malloc(n*(sizeof(int)));
    for (int i = 0; i < n; i++) {
        scanf ("%d", &p[i]);
    }
    for (int i = 0; i < n; i++) {
        printf ("%d  ", &p[i]);
    }
    printf ("\n");
    for (int i = 0; i < n; i++) {
        printf ("%d  ", p[i]);
    }
    free(p);
return 0;
}
