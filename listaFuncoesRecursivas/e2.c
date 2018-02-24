/*
 ============================================================================
 Name        : e2.c
 Author      : Lucas Santos
 Version     :
 Copyright   :
 Description : lista de exercícios de recursividade - Palindromo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromo(char* c, int t){
    if(t < (strlen(c)/2)+1){
        printf("É um palindromo!\n");
    }
    if(c[strlen(c) - t] == c[t-1] && t>(strlen(c)/2)){
        palindromo(c, t-1);
    }else if(c[strlen(c) - t] != c[t-1]){
        printf("Não um palindromo!\n");
    }
}
void pali (char* c){
    palindromo(c, strlen(c));
}

int main (void){
  char a[10];
  printf("\nDigite o nome: ");
  fflush(stdin);
  gets(a);
  pali(a);
  return 0;
}