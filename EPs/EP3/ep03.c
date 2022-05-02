#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Troca(int *v, int i, int j) {
  int tmp;
  tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}

void calculo_custo(int *v, int **custo_matriz, int *menor_custo, int taref){
    int custo_total = 0;
    for(int i = 0; i < taref; i++){
        custo_total += custo_matriz[v[i]][i];
    }
    if(menor_custo[taref] == 0){
        for(int i = 0; i < taref; i++){
            menor_custo[i] = v[i];
        }
        menor_custo[taref] = custo_total;
    }
    else{
        if(custo_total < menor_custo[taref]){
            menor_custo[taref] = custo_total;
            for(int i = 0; i < taref; i++){
                menor_custo[i] = v[i];
            }
        }
    }
}

void teste_restricao(int *v, int taref, int **restri, int **custo_matriz, int *menor_custo){
    int teste = TRUE;
    for(int i = 0; i < taref; i++){
        for(int j = i+1; j < taref; j++){
            if(restri[v[i]][v[j]] == 1) teste = FALSE;
        }
    }
    if(teste == TRUE) calculo_custo(v, custo_matriz, menor_custo, taref);

}

void permutacao(int *v, int taref, int **restri, int **custo_matriz, int *menor_custo, int k) {
    if(k == taref) {
        teste_restricao(v, taref, restri, custo_matriz, menor_custo);
    }
    else{
        for(int i = k; i < taref; i++) {
            Troca(v, k, i);
            permutacao(v, taref, restri, custo_matriz, menor_custo, k+1);
            Troca(v, i, k);
        }
    }
}

void arranjos_rec(int *v, int func, int taref, int k, int **restri, int **custo_matriz, int *menor_custo){
    if(k < taref){
        for(int i = k; i < func; i++){
            if(k == 0){
                v[k] = i;
                arranjos_rec(v, func, taref, k+1, restri, custo_matriz, menor_custo);
            }
            else{
                if(i > v[k-1]){
                    v[k] = i;
                    if(k == taref - 1){
                        permutacao(v, taref, restri, custo_matriz, menor_custo, 0);
                    }
                    if(i != func-1){
                        arranjos_rec(v, func, taref, k+1, restri, custo_matriz, menor_custo);
                    }
                }
            }
        }
    }
}
int main(){
    char nome[30], caractere_atual;
    int funcionario, tarefa, fim_matriz = FALSE;
    int **custo, **restricoes, *tarefas, *menor_custo;
    FILE *texto;

    scanf("%s", nome);
    texto = fopen(nome, "r");

    fscanf(texto, "%d", &funcionario);
    fscanf(texto, "%c", &caractere_atual);
    fscanf(texto, "%d", &tarefa);

    custo = (int **)malloc(funcionario*sizeof(int *));
    for(int i = 0; i < funcionario; i++){
        custo[i] = (int *)malloc(tarefa*sizeof(int));}

    fscanf(texto, "%c", &caractere_atual);
    fscanf(texto, "%c", &caractere_atual);
    fscanf(texto, "%c", &caractere_atual);

    int linha = 0, coluna = 0;

    do{
        if(caractere_atual == '\n') {
            linha++;
            coluna = 0;
            fscanf(texto, "%c", &caractere_atual);

            if(caractere_atual == '\n') fim_matriz = TRUE;
        }
        else if(caractere_atual == ' ') {
                coluna++;
                fscanf(texto, "%c", &caractere_atual);

            }
        else {
            custo[linha][coluna] = ((int)caractere_atual - 48);
            fscanf(texto, "%c", &caractere_atual);
            if ((int)caractere_atual >= 48 && (int)caractere_atual <= 57){
                custo[linha][coluna] = (custo[linha][coluna] * 10) + ((int)caractere_atual - 48);
                fscanf(texto, "%c", &caractere_atual);
            }
        }
    }while (fim_matriz == FALSE);
    fim_matriz = FALSE;

    restricoes = (int **)malloc(funcionario*sizeof(int *));
    for(int i = 0; i < funcionario; i++)
        restricoes[i] = (int *)malloc(funcionario*sizeof(int));

    fscanf(texto, "%c", &caractere_atual);
    if (caractere_atual == '\n') fscanf(texto, "%c", &caractere_atual);
    linha = 0; coluna = 0;

    do{
        if(caractere_atual == '\n') {
            linha++;
            coluna = 0;
            fscanf(texto, "%c", &caractere_atual);
            if(caractere_atual == '\n') fim_matriz = TRUE;
        }
        else if(caractere_atual == ' ') {
               coluna++;
            fscanf(texto, "%c", &caractere_atual);
        }
        else {
            restricoes[linha][coluna] = ((int)caractere_atual - 48);
            fscanf(texto, "%c", &caractere_atual);
        }
    }while (fim_matriz == FALSE);

    tarefas = (int *)malloc(tarefa*sizeof(int));
    menor_custo = (int *)malloc((tarefa+1)*sizeof(int));
    menor_custo[tarefa] = 0;

    arranjos_rec(tarefas, funcionario, tarefa, 0, (int *)restricoes, (int *)custo, menor_custo);

    for(int i = 0; i < tarefa; i++){
        printf("(T:%d F:%d) ", i, menor_custo[i]);
    }
    printf("= %d", menor_custo[tarefa]);



    for(int i = 0; i < funcionario; i++){
        free(custo[i]);
    }
    free(custo);

    for(int i = 0; i < funcionario; i++){
        free(restricoes[i]);
    }
    free(restricoes);

    free(tarefas);

    free(menor_custo);

    return 0;
}
