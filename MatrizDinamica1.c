#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    int **p;
    scanf ("%d", &n);
    scanf ("%d", &m);
    p = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++) {
        p[i] = (int*)malloc(m*sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf ("%d", &p[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        printf ("\n");
        for (int j = 0; j < m; j++) {
            printf ("%d ", &(p[i][j]));
        }
    }
    for (int i = 0; i < n; i++) {
        printf ("\n");
        for (int j = 0; j < m; j++) {
            int a = (p[i][j]);
            printf ("%d ", a);
        }
    }
    for (int i = 0; i < n; i++) {
        printf ("\n");
        for (int j = 0; j < m; j++) {
            free(p[i] + j);
        }
    }
return 0;
}
