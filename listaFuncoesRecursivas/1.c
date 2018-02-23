/*
 ============================================================================
 Name        : fibonacciRecursivo.c
 Author      : Lucas Santos
 Version     :
 Copyright   :
 Description : Metodo de fibonacci Recursivo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int calculo(int n){
  if(n == 1) return 3;
  return 3 * calculo (n - 1) - 2;
}

int main (void){
  int a;
  printf("\nDigite o numero: ");
  fflush(stdin);
  scanf("%d", &a);
  printf("\nO resultado desejado é: %d", calculo(a));
  return 0;
}
