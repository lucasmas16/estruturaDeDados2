#include "data.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


void insertionSort(ITEM *vetor, int length) {
	int i, j, aux;


	for (i = 1; i < length; i++) {
		aux = vetor[i].chave;
		

		for (j = i - 1; (j >= 0) && (aux < vetor[j].chave); j--) {
            vetor[j+1].chave = vetor[j].chave;
        }

		vetor[j+1].chave = aux;
	}

}

double rand0a1()
{
  double res = (double)rand() / INT_MAX;
  if(res > 1.0) res = 1.0;
  return res;
}

void permuta(VETOR a, int tam)
{
  ITEM b;
  int i,j;
  
  for(i=tam-1; i>=0; i--){
    j = (i * rand0a1()) + 1;
    b = a[i];
    a[i] = a[j];
    a[j] = b;
  }
}

void imprime(VETOR a, int tam)
{
  int i;
  
  for(i=0; i<tam; i++) printf("%d ", a[i].chave);
  printf("\n");
}

int main(int argc, char *argv[])
{
  VETOR v;
  int n = sizeof(v)/sizeof(ITEM);
  int i;
  
  for(i=0; i<n; i++) v[i].chave = i;
  
  permuta(v,n);
  
  printf("Original\n");
  imprime(v,n);
  
  insertionSort(v, n);
  
  printf("Ordenado\n");
  imprime(v,n);
  
  system("PAUSE");	
  return 0;
}
