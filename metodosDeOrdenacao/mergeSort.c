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

void merge(ITEM *vetor, int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    ITEM *vetAux;
    vetAux = malloc(tam * sizeof(ITEM));

    while(com1 <= meio && com2 <= fim){//percorre as metades do vetor
        if(vetor[com1].chave < vetor[com2].chave) {
            vetAux[comAux].chave = vetor[com1].chave;
            com1++;
        } else {
            vetAux[comAux].chave = vetor[com2].chave;
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Verifica a primeira metade
        vetAux[comAux].chave = vetor[com1].chave;
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Verifica a segunda metade
        vetAux[comAux].chave = vetor[com2].chave;
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Volta com os elementos para o outro vetor
        vetor[comAux].chave = vetAux[comAux-comeco].chave;
    }
    
    free(vetAux);
}

void mergeSort(ITEM *vetor, int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
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
  
  mergeSort(v,0, 199);
  
  printf("Ordenado\n");
  imprime(v,n);
  
  system("PAUSE");	
  return 0;
}