#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.c" //inclue a strutura do item e alguns auxiliares

//faz o calculo para gerar um chave para o espalhamento
int h (CHAVE chave){
    int i, soma;
    soma = 0;
    for(i = 0; i < N; i++){
        soma += chave[i];
    }
    return soma % M;
}

//cria um novo dicionário e inicia cada posição com uma lista vazia
int newDic(DICIONARIO d){
    int i;
    for(i = 0; i < M; i++){
        newList(&d[i]);
    }
    return 0;
}

//busca um item, caso ache retorna a posição e carrega os dados do item
int search(DICIONARIO d, ITEM *i){
    int key, temp;
    key = h(i->nome);
    temp = searchList(i, d[key]);
    if(temp){
        return -1;
    }
    return key;
}

//insere um item em uma determinada posição
int insert(DICIONARIO d, ITEM i){
    int key;
    key = h(i.nome);
    insertList(i, &d[key]);
    return key;
}

//Remove um item
int rem(DICIONARIO d, ITEM i){
    int key;
    key = h(i.nome);
    return removeList(&i, &d[key]);
}