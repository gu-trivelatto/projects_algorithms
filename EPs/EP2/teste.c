#include <stdio.h>
#include <string.h>

int main(){
    char a[10] = "batata";
    char b[10] = "batata";
    int c;
    c = strcmp(a,b);
    printf("%d", c);
    return 0;

}
