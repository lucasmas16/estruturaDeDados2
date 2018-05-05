#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXTAM  200

typedef long CHAVE;
typedef struct ITEM_TAG {
  CHAVE chave;
  /* Outros componentes */
} ITEM;
typedef int INDICE;
typedef ITEM VETOR[MAXTAM];

void heapSort(ITEM *a, int n) {
   int i, pai, filho, t;
   i = n/2;
   while(1 == 1) {
      if (i > 0) {
          i--;
          t = a[i].chave;
      } else {
          n--;
          if (n == 0) return;
          t = a[n].chave;
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1].chave > a[filho].chave))
              filho++;
          if (a[filho].chave > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai].chave = t;
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
  
  for(i=0; i<tam; i++) printf("%ld ", a[i].chave);
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
  
  heapSort(v,n);
  
  printf("Ordenado\n");
  imprime(v,n);
  
  system("PAUSE");	
  return 0;
}