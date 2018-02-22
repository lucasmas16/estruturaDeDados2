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

//exemplo ruim de recursao
long fibonacciRecursivo (long n){
  if(n <= 1) return n;
  return fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2);
}



int main (void){
  long a, resp;
  printf("\nDigite o numero elementos da sequencia de fibonacci desejados: ");
  fflush(stdin);
  scanf("%ld", &a);
  resp = fibonacciRecursivo(a);
  printf("\nO fibonacci desejado é: %ld", resp);
}
