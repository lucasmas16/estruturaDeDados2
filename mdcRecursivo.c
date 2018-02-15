/*
 ============================================================================
 Name        : mdcRecursivo.c
 Author      : Lucas Santos
 Version     :
 Copyright   : 
 Description : Metodo de verificar o mdc de forma recursiva
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b){
  if(b == 0)
    return a;
  return mdc(b, a % b);
}

int main (void){
  int a, b;
  printf("\nDigite a: ");
  fflush(stdin);
  scanf("%d", &a);
  
  printf("Digite b: ");
  fflush(stdin);
  scanf("%d", &b);
  
  printf("\nO mdc de %d e %d é :%d\n\n", a, b, mdc(a, b));
}