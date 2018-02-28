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

void imprimirVetor(int v[], int tam){
  int i;
  printf("\nTamanho: %d", tam);
  for(i = 0; i < tam; i++){
    printf("\n%d", v[i]);
  }
  printf("\nFim de impressão");
}

int* newVetor(int* result, int* vetor, int e, int d){
  if(e < d){
    result[e] = vetor[e];
    newVetor(result, vetor, e + 1, d);
  }
}

int buscaBin(int x, int* vetor, int e, int d){
  int meio = (d + e) / 2;
  if(vetor[meio] == x) return meio;
  if(e >= d) return -1;
  if(vetor[meio] > x){
    buscaBin(x, vetor, e, meio - 1);
  }else{
    buscaBin(x, vetor, meio + 1, d);
  }
}

int main (void){
  int i[5] = {0,1,2,3,5};
  long n;
  int j ;
  j = sizeof(i)/4;
  
  n = buscaBin(0, i, 0, j);
  
  printf("\nO elemento %d está na posição %ld\n", 0, n);

  fflush(stdin);
  return 0;
}