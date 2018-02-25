/*
 ============================================================================
 Name        : e2.c
 Author      : Lucas Santos
 Version     :
 Copyright   :
 Description : lista de exercícios de recursividade - Conversor de Binário
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string *Apontador;


typedef struct string{
    char s;
    Apontador next;
}Letra;

typedef struct{
    Apontador Primeiro, Ultimo;
}Palavra;

void newPalavra(Palavra *palavra){
    palavra->Primeiro = (Apontador)malloc(sizeof(Letra));
    palavra->Ultimo = palavra->Primeiro;
    palavra->Primeiro->next = NULL;
}

void insertEnd(char letra, Palavra *palavra){
    palavra->Ultimo->next = (Apontador)malloc(sizeof(Letra));
    palavra->Ultimo = palavra->Ultimo->next;
    palavra->Ultimo->s = letra;
    palavra->Ultimo->next = NULL;
}

void insertStart(char letra, Palavra *palavra){
    Apontador novo = (Apontador)malloc(sizeof(Letra));
    novo->s = letra;
    novo->next = palavra->Primeiro;
    palavra->Primeiro = novo;
}

void printLetra(Letra *letra){
    printf("%c", letra->s);
    if(letra->next != NULL){
        printLetra(letra->next);
    }
}

void printPalavra(Palavra *palavra){
    printLetra(palavra->Primeiro);
}

void binInt(int n, Palavra *resp){
    if(n >= 2){
        if(n % 2 == 0){
            insertStart(48, resp);
        }else{
            insertStart(49, resp);
        }
        binInt(n/2, resp);
    }else{
        insertStart(49, resp);
    }
}

int main (void){
    Palavra *resp;
    newPalavra(resp);

    int x;

    printf("\nDigite o número: ");
    fflush(stdin);
    scanf("%d", &x);
    binInt(x, resp);
    printPalavra(resp);
    return 0;
}