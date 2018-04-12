#include <stdio.h>
#include <stdlib.h>

void imprime(int* vet, int tam){
    int i = 0;
    for(i = 0; i < tam; i++){
        printf("%d", vet[i]);
    }
    printf("\n");
}

void particao(int *v, int esq, int dir, int *i, int *j){
    int pivo, temp;
    *i = esq;
    *j = dir;
    pivo = v[(*i+*j/2)];

    do{
        while(pivo > v[*i]) (*i)++;
        while(pivo <= v[*j]) (*j)--;
        if(*i <= *j){
            temp = v[*i];
            v[*i] = v[*j];
            v[*j] = temp;
        }
    }while(*i <= *j);
}

void ordena(int *v, int esq, int dir){
    int i, j;

    particao(v, esq, dir, &i, &j);
    if (esq < j){
        ordena(v, esq, j);
    }
    if(i < dir){
        ordena(v, i, dir);
    }
}

void quickShot(int *v, int size){
    ordena(v, 0, size -1);
}

int main (void){
    int vet[] = {112,45,663,23,5,78,3,4,-32,-56,-32,234,62,-2,0};
    int size;
    size = sizeof(vet) / sizeof(int);
}