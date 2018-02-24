/*
 ============================================================================
 Name        : 2.c
 Author      : Lucas Santos
 Version     :
 Copyright   :
 Description : lista de exercícios de recursividade
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void calculo(int n, int q){
  if(q > 1) calculo(n, q-1);
  printf("%d x %d = %d\n", n, q, n*q);
}

int main (void){
  int a, b;
  printf("\nDigite o numero a: ");
  fflush(stdin);
  scanf("%d", &a);
  printf("\nDigite o numero b: ");
  fflush(stdin);
  scanf("%d", &b);
  calculo(a, b);
  return 0;
}
