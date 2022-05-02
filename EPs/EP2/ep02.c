//Estou deixando esse comentário aqui pois tive problemas com o avaliador do PACA, testei todos os exemplos e em todos a
//saída parece OK, porém por algum motivo o avaliador do site não recebe as saídas, dessa forma não testando corretamente

#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum boolean {false, true} bool;

struct tag{
    char tag_string[20];
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

void empilha(tag_pointer p, char tag_s[20], int linha){
    tag_pointer q;
    q = (tag_pointer)malloc(sizeof(struct tag));
    strcpy(q->tag_string, tag_s);
    q->linha = linha;
    q->prox = p->prox;
    p->prox = q;
}

char *desempilha(tag_pointer p, int *linha_compara){
    tag_pointer q;
    char *tag;
    q = p->prox;
    strcpy(tag, q->tag_string);
    *linha_compara = q->linha;
    p->prox = q->prox;
    free(q);
    return tag;
}

void LiberaPilha(tag_pointer p){
    struct tag *q, *t;
    q = p;
    while(q != NULL){
        t = q;
        q = q->prox;
        free(t);
    }
    free(p);
}

bool pilha_vazia(tag_pointer p){
    return (p->prox == NULL);
}

int main(){
    char nome[30], tag[20], tag_compara[20], letra_atual;
    int erro = 0, i, c, vazio = FALSE, linha = 1, linha_compara = -1;
    FILE *texto;
    tag_pointer f;

    f = cria_pilha();
    scanf("%[^\n]", nome);
    texto = fopen(nome, "r");

    fscanf(texto, "%c", &letra_atual);
    while(erro == 0 && vazio == FALSE){       //executa comparações enquanto não houverem erros (erro = 0) e enquanto a lista não for vazia (fim do arquivo)
        while(letra_atual == ' '){      //ignora espaços que estiverem antes das tags
            fscanf(texto, "%c", &letra_atual);
        }
        if(letra_atual == '<'){         //inicia a comparação de tags
            fscanf(texto, "%c", &letra_atual);        //determina o proximo caractere apos o inicio da tag
            if(letra_atual == '?'){         //a ? determina se é a tag padrão do xml, ignorando-a em seguida
                do {
                    fscanf(texto, "%c", &letra_atual);
                }while(letra_atual != '\n');
                fscanf(texto, "%c", &letra_atual);
            }
            else{        //inicia a leitura das tags
                i = 0;   //inicializa o contador da string em cada leitura de tag
                if(letra_atual != '/'){    //inicia a leitura de uma tag de abertura
                    linha++;
                    for(int k = 0; k <= 19; k++){
                        tag[k] = '\0';
                    }
                    do{  //insere a tag na string
                        tag[i] = letra_atual;
                        i++;
                        fscanf(texto, "%c", &letra_atual);
                    }while(letra_atual != '>' && letra_atual != ' ');
                    tag[i] = '\0';
                    empilha(f, tag, linha);    //empilha a tag lida
                    do{  //le as informações entre duas tags e as ignora
                        fscanf(texto, "%c", &letra_atual);
                    }while(letra_atual != '<');
                }

                else{    //inicia a leitura de uma tag de fechamento
                    fscanf(texto, "%c", &letra_atual);  //le o primeiro caractere da tag
                    for(int k = 0; k <= 19; k++){
                        tag[k] = '\0';
                    }
                    do{    //insere a tag na string
                        tag[i] = letra_atual;
                        i++;
                        fscanf(texto, "%c", &letra_atual);
                    }while(letra_atual != '>');
                    fscanf(texto, "%c", &letra_atual);
                    fscanf(texto, "%c", &letra_atual);

                    strcpy(tag_compara, desempilha(f, &linha_compara));  //pega a ultima tag empilhada e coloca ela na string de comparação

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
                    linha++;
                    linha++;
                    i = 0;
                    for(int k = 0; k <= 19; k++){
                        tag[k] = '\0';
                    }
                    fscanf(texto, "%c", &letra_atual);
                    do{  //insere a tag na string
                        tag[i] = letra_atual;
                        i++;
                        fscanf(texto, "%c", &letra_atual);
                    }while(letra_atual != '>' && letra_atual != ' ');
                    tag[i] = '\0';
                }
            }
        }
    }
    if(letra_atual == '\n' && (erro == 2 || erro == 1))linha++;
    if(erro == 0) printf("Tags balanceadas");
    if(erro == 1) printf("Violacao da regra #1:\nTags incompativeis (abertura '%s' na linha %d e fechamento '%s' na linha %d)", tag_compara, linha_compara, tag, linha);
    if(erro == 2) printf("Violacao da regra #2:\nTags incompativeis (abertura '%s' na linha %d e fechamento '%s' na linha %d)", tag_compara, linha_compara, tag, linha);
    if(erro == 3) printf("Violacao da regra #3:\nRaiz adicional ('%s' na linha %d)", tag, linha);

    fclose(texto);
    LiberaPilha(f);

return 0;
}
