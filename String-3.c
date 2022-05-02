#include <stdio.h>
#include <string.h>
#define LIM 500

int main(){
    char texto[LIM], trocado[LIM];
    int i = 0;
    fgets(texto, LIM-1, stdin);
    while(texto[i] != '\0'){
        if(texto[i] == 'r'){
            if(texto[i+1] != " ") trocado[i] = 'l';
            else trocado[i] = texto[i];
        }
        else trocado[i] = texto[i];
        i++;
    }
    trocado[i] = '\0';
    printf("%s", trocado);
    return 0;
}
