/*
 ============================================================================
 Name        : e1.c
 Author      : Lucas Santos
 Version     :
 Copyright   :
 Description : lista de exercícios de recursividade
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int invt(char* c, int t){
  char aux;
  aux = c[strlen(c) - t];
  c[strlen(c) - t] = c[t-1];
  c[t-1] = aux;
  printf("\n%s", c);
  if(t>(strlen(c)/2)+1) invt(c, t - 1);
}

int invtC(char *s, int tam){
  char c;
  if(tam > 1){
    c = s[0];
    s[0] = s[tam - 1];
    s[tam - 1] = c;
    invtC(s + 1, tam - 2);
  }
}

void inv(char* c){
  invtC(c, strlen(c));
}

int main (void){
  char a[10];
  printf("\nDigite o nome: ");
  fflush(stdin);
  gets(a);
  inv(a);
  printf("\nO resultado desejado é: %s", a);
  return 0;
}
