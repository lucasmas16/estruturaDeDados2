#include "openHash.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int newDictionary(DICTIONARY dict){
    int i;
    for(i = 0; i < MAX; i++){
        dict[i].nome = EMPTY;
        dict[i].price = 0;
    }
}

int h (CHAVE chave){
    int i, soma;
    soma = 0;

    for(i = 0; i < N; i++){
        soma += chave[i];
    }
    return (soma % MAX);
}

int insert(ITEM x, DICTIONARY d){
    int i, inicial;


}