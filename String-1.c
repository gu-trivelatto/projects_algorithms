#include <stdio.h>
#define LIM 500

int main(){
    int i = 0;
    char texto[LIM];
    fgets(texto, LIM-1, stdin);
    while(texto[i] != '\0'){
        if(texto[i] == ' '){
            printf("\n");
        }
        else printf("%c", texto[i]);
        i++;
    }
return 0;
}
