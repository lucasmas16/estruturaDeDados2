#include <stdlib.h>
#include <stdio.h>
#include "arvore.c"

int main(){
    FILE *entrada;
    entrada = fopen("data.txt", "r");
    if(entrada == NULL){
        printf("Erro de leitura!");
        return -1;
    }
    DICIONARIO dic;
    newDic(&dic);
    ITEM temp;
    int op, pos;
    do{
        printf("\n1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Buscar elemento\n");
        printf("Digite a opcao desejada ou 0 para sair: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                fscanf(entrada, "%s %lf", temp.nome, &temp.preco);
                if(insert(temp, &dic) != -1){
                    printf("\nItem inserido com sucesso!\n");
                }else{
                    printf("\nErro ao inserir o produto!\n");
                }
                op = -1;
                break;
            case 2:
                printf("Digite o elemento a ser removido: ");
                scanf("%s", temp.nome);
                if(rem(temp, &dic)){
                    printf("\nItem não encontrado!");
                }else{
                    printf("\nProduto removido com sucesso!");
                }
                op = -1;
                break;
            case 3:
                printf("Digite o elemento a ser buscado: ");
                scanf("%s", temp.nome);
                pos = search(&temp, &dic);
                if(pos == -1){
                    printf("\nItem não encotrado!");
                }else{
                    printf("\nO item %s com preco %lf.", temp.nome, temp.preco);
                }
                op = -1;
                break;
            case 0:
                printf("\nFim de programa!\n");
                break;
            default:
                printf("\nDigite uma opção valida!");
                break;
        }
    }while(op != 0);
}