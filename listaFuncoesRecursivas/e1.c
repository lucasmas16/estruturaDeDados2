/*
 ============================================================================
 Name        : 3.c
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
  if(t > strlen(c)) invt(c, t - 2);
  char aux;
  aux = c[strlen(c) - t];
  c[strlen(c) - t] = c[t-1];
  c[t-1] = aux;
  printf("%s\n", c);
}

int main (void){
  char a[10];
  printf("\nDigite o nome: ");
  fflush(stdin);
  gets(a);
  invt(a, strlen(a));
  printf("\nO resultado desejado é: %s", a);
  return 0;
}
