#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum boolean {false, true} bool;

struct tag{
    char tag_string[10];
    int linha;
    struct tag *prox;
};

typedef struct tag* tag_pointer;

tag_pointer cria_pilha(){
    tag_pointer p;
    p = (tag_pointer)malloc(sizeof(struct tag));
    p->prox = NULL;
    return p;
}

void empilha(tag_pointer p, char tag_s[10], int linha){
    tag_pointer q;
    q = (tag_pointer)malloc(sizeof(struct tag));
    strcpy(q->tag_string , tag_s);//CORRECTION
    q->linha = linha;
    q->prox = p->prox;
    p->prox = q;
}
//CORRECTION
char *desempilha(tag_pointer p, int* linha_compara){
    tag_pointer q;
    char *tag;//CORRECTION
    q = p->prox;
    strcpy(tag, q->tag_string);//CORRECTION
    linha_compara = p->linha;
    p->prox = q->prox;
    free(q);
    return tag;
}

bool pilha_vazia(tag_pointer p){
    return (p->prox == NULL);
}

int main(){
  char nome[30], tag[10], tag_compara[10], letra_atual;
    int erro = 0, i, c, teste3 = 0, vazio = FALSE, linha = 1, linha_compara;
    FILE *texto;
    tag_pointer f;

    f = cria_pilha();
    scanf("%[^\n]", nome);
    texto = fopen(nome, "r");

    fscanf(texto, "%c", &letra_atual);
    while(erro == 0 && vazio == FALSE){       //executa comparações enquanto não houverem erros (erro = 0) e enquanto a lista não for vazia (fim do arquivo)
        //printf("teste");
        while(letra_atual == ' '){      //ignora espaços que estiverem antes das tags
            fscanf(texto, "%c", &letra_atual);
        }

        if(letra_atual == '<'){         //inicia a comparação de tags
            fscanf(texto, "%c", &letra_atual);        //determina o proximo caractere apos o inicio da tag
            if(letra_atual == '?'){         //a ? determina se é a tag padrão do xml, ignorando-a em seguida
                do {
                    fscanf(texto, "%c", &letra_atual);
                }while(letra_atual != '\n');
                fscanf(texto, "%c", &letra_atual);//Correction: Lêr proximo carater para comparar
            }

            else{        //inicia a leitura das tags
                i = 0;   //inicializa o contador da string em cada leitura de tag
                if(letra_atual != '/'){    //inicia a leitura de uma tag de abertura
                    linha++;
                    do{  //insere a tag na string
                        tag[i] = letra_atual;
                        i++;
                        fscanf(texto, "%c", &letra_atual);
                    }while(letra_atual != '>' && letra_atual != ' ');//correction: troquei or => and
                    tag[i] = '\0';
                    empilha(f, tag, linha);    //empilha a tag lida
                    do{  //le as informações entre duas tags e as ignora
                        fscanf(texto, "%c", &letra_atual);
                    }while(letra_atual != '<');
		    fscanf(texto, "%c", &letra_atual);//Correction: Lêr proximo carater para comparar
                }
                else{    //inicia a leitura de uma tag de fechamento
                    fscanf(texto, "%c", &letra_atual);  //le o primeiro caractere da tag
                    do{    //insere a tag na string
                        tag[i] = letra_atual;
                        i++;
                        fscanf(texto, "%c", &letra_atual);
                    }while(letra_atual != '>');
                    tag[i] = '\0';
                    fscanf(texto, "%c", &letra_atual);

                    strcpy(tag_compara, desempilha(f, &linha_compara));//pega a ultima tag empilhada e coloca ela na string de comparação

                    printf("%s, %s.", tag, tag_compara);
                    if(strcmp(tag, tag_compara) != 0){   //decide se as tags são diferentes

                        erro = 2;             //deixa pré decidido que cai na 2ª regra
                        for(c = 0; c <= i; c++){    //testa se as tags são iguais com maiusculas e minisculas diferentes
                            if(tag_compara[c] == tag[c] - 32 || tag_compara[c] == tag[c] + 32){
                                erro = 1;     //define como 1ª regra se a condição acima for satisfeita
                            }
                        }
                    }

                }
                vazio = pilha_vazia(f);
                if(vazio == TRUE && letra_atual == '<'){  //se o teste for verdadeiro, então caimos na 3ª regra
                    erro = 3;
                }
            }
        }
    }
    if(erro == 0) printf("Tags balanceadas");
    if(erro == 1) printf("Violacao da regra #1:\nTags incompativeis (abertura '%s' na linha %d e fechamento '%s' na linha %d)", tag_compara, linha_compara, tag, linha);
    if(erro == 2) printf("Violacao da regra #2:\nTags incompativeis (abertura '%s' na linha %d e fechamento '%s' na linha %d)", tag_compara, linha_compara, tag, linha);
    if(erro == 3) printf("Violacao da regra #3\nRaiz adicional ('%s' na linha %d)", tag, linha);

    fclose(texto);


return 0;
}
