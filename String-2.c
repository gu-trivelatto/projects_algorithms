#include <stdio.h>
#include <string.h>
#define LIM 500

int main(){
    char texto[LIM], l;
    int alf[125], i = 0, letra;
    for (int j = 1; j < 125; j++){
        alf[j] =0;
    }
    fgets(texto, LIM-1, stdin);
    while(texto[i] != '\0'){
        if(texto[i] != " "){
            letra = (int)texto[i];
            alf[letra]++;
        }
        i++;
    }
    for(int j = 'A'; j <= 'Z'; j++){
        alf[j] += alf[j+32];
    }
    for(int j = 'A'; j <= 'Z'; j++){
        l = j;
        printf("%c, %d vezes\n", l, alf[j]);
    }
    return 0;
}
