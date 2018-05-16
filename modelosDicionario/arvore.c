#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

int h (CHAVE chave){
    int i, soma;
    soma = 0;
    for(i = 0; i < N; i++){
        soma += chave[i];
    }
    return soma % M;
}

void newDic(DICIONARIO *d){
    *d = NULL;
}

int search(ITEM *i, PONT *p){
    if(*p == NULL){
        return -1;
    }
    if (h(i->nome) < h((*p)->item.nome)){
        return search(i, &(*p)->esq);
    }else if (h(i->nome) > h((*p)->item.nome)){
        return search(i, &(*p)->dir);
    }
    if(strncmp(i->nome, (*p)->item.nome, N)){
        return search(i, &(*p)->esq);
    }else{
        *i = (*p)->item;
        return 0;
    }
}
int insert(ITEM i, PONT *p){
    if(*p == NULL){
        *p = (PONT)malloc(sizeof(NO));
        (*p)->item = i;
        (*p)->dir = NULL;
        (*p)->esq = NULL;
        return 0;
    }
    if (h(i.nome) < h((*p)->item.nome)){
        return insert(i, &(*p)->esq);
    }else if (h(i.nome) > h((*p)->item.nome)){
        return insert(i, &(*p)->dir);
    }
    if(strncmp(i.nome, (*p)->item.nome, N)){
        return insert(i, &(*p)->esq);
    }
    return -1;
}

void antecessor (PONT q, PONT *r){
    if((*r)->dir != NULL){
        antecessor (q, &(*r)->dir);
        return;
    }
    q->item = (*r)->item;
    q = *r;
    *r = (*r)->esq;
    free(q);
}
int rem(ITEM i, PONT *p){
    PONT aux;
    if(*p == NULL){
        return -1;
    }
     if (h(i.nome) < h((*p)->item.nome)){
        return rem(i, &(*p)->esq);
    }else if (h(i.nome) > h((*p)->item.nome)){
        return rem(i, &(*p)->dir);
    }
    if(strncmp(i.nome, (*p)->item.nome, N)){
        return rem(i, &(*p)->esq);
    }
    if((*p)->dir == NULL){
        aux = *p;
        *p = (*p)->esq;
        free(aux);
        return 0;
    }
    if((*p)->esq == NULL){
        aux = *p;
        *p = (*p)->dir;
        free(aux);
        return 0;
    }
    antecessor(*p, &(*p)->esq);
    return 0;
}
