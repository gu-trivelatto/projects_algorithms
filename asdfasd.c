#include <stdio.h>
#include <string.h>
#define LIM 500

int main(){
    char texto[LIM], palavra[LIM] = "nada", letra;
    int NumPalavras = 0, i = 0, testend = 0;
    fgets(texto, LIM-1, stdin);
    while (palavra != "end"){

        palavra[LIM] = "nada";
    printf("%s", texto);
        while (texto[i] != " " && testend == 0){
            letra = texto[i];
            printf ("%c", texto[i]);
            strcat(palavra, letra);
            printf ("a");
            if(palavra == "end") testend = 1;

            i++;
        }
        NumPalavras++;
        i++;
    }
    printf("%d", NumPalavras);
    return 0;
}
