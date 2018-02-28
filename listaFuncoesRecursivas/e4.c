/*
 ============================================================================
 Name        : e4.c
 Author      : Lucas Santos
 Version     :
 Copyright   :
 Description : lista de exercícios de recursividade - Buscar maior
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

int maiorV1(int vetor[], int maior, int tam){
  int newMaior;
  if(tam <= 0) return maior;
  else{
    newMaior = maior > vetor[tam-1] ? maior : vetor[tam-1];
    maiorV1(vetor, newMaior, tam-1);
  }
}

int maiorV2(int* vetor, int tam){
  printf("\nComeço maiorV2");
  imprimirVetor(vetor, tam);
  int meio = tam / 2;
  
  int tamP1 = meio + 1;
  int tamP2 = tam - tamP1;
  
  int v1[tamP1];
  printf("\nVetor 1");
  imprimirVetor(v1, tamP1);
  newVetor(v1, vetor, 0, meio);
  int v2[tamP2];
  newVetor(v2, vetor, meio, tam);
  printf("\nVetor 2");
  imprimirVetor(v2, tamP2);
  
  int newMaior1 = maiorV1(v1, vetor[0], tamP1);
  int newMaior2 = maiorV1(v2, vetor[meio], tamP2);
  return newMaior1 > newMaior2 ? newMaior1 : newMaior2;
}

int main (void){
  int i[5] = {0,1,2,3,5};
  long n;
  int j ;
  j = sizeof(i)/4;
  printf("\nComeço main\n");
  n = maiorV1(i, i[0], j);
  printf("\nMaior número = %ld", n);

  fflush(stdin);
  return 0;
}