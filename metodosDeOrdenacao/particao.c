#include <stdio.h>
#include <stdlib.h>

void imprime(int* vet, int tam){
    int i = 0;
    for(i = 0; i < tam; i++){
        printf("%d", vet[i]);
    }
    printf("\n");
}

int main(void){
    int vet[] = {0,1,2,0,2,1,1,0,0,0,1,1,0,1,2};

    int i, j, size, temp, pivo;
    pivo = 1;
    size = sizeof(vet) / sizeof(int);
    imprime(vet, size);
    i = 0;
    j = size-1;
    do{
        while(vet[i] < pivo) i++;
        while(vet[j] >= pivo) j--;

        if(i <= j){
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
        }
    }while(i <= j);
    imprime(vet, size);

    j = size-1;
    pivo = 2;

    do{
        while(vet[i] < pivo) i++;
        while(vet[j] >= pivo) j--;

        if(i <= j){
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
        }
    }while(i <= j);
    imprime(vet, size);
}