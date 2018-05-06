#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h" //inclue a strutura do item e alguns auxiliares

typedef LIST DICIONARIO[M];

//faz o calculo para gerar um chave para o espalhamento
int h (CHAVE chave){
    int i, soma;
    soma = 0;
    for(i = 0; i < N; i++){
        soma += chave[i];
    }
    return soma % M;
}

int newDic(DICIONARIO d){
    int i;
    for(i = 0; i < M; i++){
        newList(&d[i]);
    }
    return 0;
}

int search(DICIONARIO d, ITEM *i){
    int key, temp;
    key = h(i->nome);
    temp = searchList(i, d[key]);
    if(temp){
        return -1;
    }
    return key;
}

int insert(DICIONARIO d, ITEM i){
    int key;
    key = h(i.nome);
    insertList(i, &d[key]);
    return key;
}

int rem(DICIONARIO d, ITEM i){
    int key;
    key = h(i.nome);
    return removeList(&i, &d[key]);
}

int main(){
    DICIONARIO dic;
    newDic(dic);
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
                printf("\nDigite o elemento a ser inserido: ");
                scanf("%s", temp.nome);
                printf("Digite o preco do elemento:");
                scanf("%lf", &temp.preco);
                if(insert(dic, temp) != -1){
                    printf("\nItem inserido com sucesso!");
                }else{
                    printf("\nErro ao inserir o produto!\n");
                }
                op = -1;
                break;
            case 2:
                printf("Digite o elemento a ser removido: ");
                scanf("%s", temp.nome);
                if(rem(dic, temp)){
                    printf("\nItem não encontrado!");
                }else{
                    printf("\nProduto removido com sucesso!");
                }
                op = -1;
                break;
            case 3:
                printf("Digite o elemento a ser buscado: ");
                scanf("%s", temp.nome);
                pos = search(dic, &temp);
                if(pos == -1){
                    printf("\nItem não encotrado!");
                }else{
                    printf("\nO item %s com preco %lf está na posicao %d", temp.nome, temp.preco, pos);
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