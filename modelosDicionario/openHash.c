#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h" //inclue a strutura do item e alguns auxiliares

typedef ITEM DICIONARIO[M]; // define o dicionario como um vetor de item de tamanho M

//faz o calculo para gerar um chave para o espalhamento
int h (CHAVE chave){
    int i, soma;
    soma = 0;
    for(i = 0; i < N; i++){
        soma += chave[i];
    }
    return soma % M;
}

//inicia todas as posicoes do dicionario com o valor EMPTY
int newDic(DICIONARIO d){
    int i;
    for(i = 0; i < M; i++){
        strncpy(d[i].nome, EMPTY, N);
    }
    return 0;
}

int search (DICIONARIO d, ITEM *i){
    int key, n = 0;
    key = h(i->nome);
    //verifica de encontrou uma posicao vazia, o elemento ou de percorreu todo o vetor
    while(strncmp(d[(key + n) % M].nome, EMPTY, N)&&
         strncmp(d[(key + n) % M].nome, i->nome, N)&&
         n < M) n++;
    //se percorreu e achou o elemento retornando a posicao
    if(n < M && !strncmp(d[(key + n) % M].nome, i->nome, N)){
        i->preco = d[(key + n) % M].preco;
        return (key + n) % M;
    }else{//se percorreu tudo e ele está cheio retorna erro
        return -1;
    }
}

//incere um novo elemento no dicionario
int insert (DICIONARIO d, ITEM i){
    int key, n = 0;
    key = h(i.nome);
    //verifica de encontrou uma posicao vazia, removida ou de percorreu todo o vetor
    while(strncmp(d[(key + n) % M].nome, EMPTY, N)&&
         strncmp(d[(key + n) % M].nome, REMOVED, N)&&
         n < M) n++;
    //se percorreu e achou uma posicao vaga inser o elemento
    if(n < M){
        d[(key + n) % M] = i;
        return (key + n) % M;
    }else{//se percorreu tudo e ele está cheio retorna erro
        return -1;
    }
}

//usa o metodo de busca acha a posicao e remove o elemento
int rem(DICIONARIO d, ITEM i){
    int posi;
    posi = search(d, &i);
    if(strncpy(d[posi].nome, REMOVED, N))
        return 0;
    return -1;
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
                    printf("\nErro ao remover o item!");
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