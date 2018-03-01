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

//funcao de conversão não de cauda que gera um inteiro
long binC(int n){
    if(n < 2){
        return n;
    }else{
        return 10 * binC(n / 2) + (n % 2);
    }
}

//funcao de conversão de cauda que gera um inteiro
long binC_tl(int n, int pot, int res){
    if(n == 0){
        return res;
    }else{
        binC_tl(n/2, 10 * pot, (n % 2)*pot + res);
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
    printf("\n");
    return 0;
}