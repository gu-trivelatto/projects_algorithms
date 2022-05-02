#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int *coisas[5];
    for (i = 0; i <= 9; i++) printf("%d\n", coisas[-i]);
    free(coisas);
    return 0;
}
