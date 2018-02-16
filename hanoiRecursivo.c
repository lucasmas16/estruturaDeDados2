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

void hanoi (int n, char o, char d, char a){
  if(n > 1)
    hanoi(n-1, o, a, d);
  printf("\nMover disco %d do pino %c para o pino %c.\n", n, o, d);
  if(n > 1)
    hanoi(n-1, a, d, o);
}

int main (void){
  int a;
  printf("\nDigite o numeros de disco para calcular os movimentos na torre de hanoi de 3 pinos: ");
  fflush(stdin);
  scanf("%d", &a);
  hanoi(a, 'a', 'b', 'c');
}