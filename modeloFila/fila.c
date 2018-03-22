#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

//inicializa a fila
int newFila(Fila *fila){
  fila->start = (PONT)malloc(sizeof(Celula));//aloca espaço para a célula cabeçalho e aponta o start para lá
  fila->end = fila->start;//aponta o fim para o cabeçalho
  fila->size = 0;//inicializa o tamanho com 0
  return 0;
}

//verifica de a fila está vazia
int empty(Fila fila){
  return fila.start == fila.end;
}

//insere elemento no fim da fila
int insert(Fila *fila, Item newItem){
  fila->end->next = (PONT) malloc (sizeof (Celula));//a nova célula é inserida após o último item
  fila->end = fila->end->next;//o fim passa a apontar para a nova célula
  fila->end->item = newItem;//aponta o next do ultimo elemento para NULL
  fila->end->next = NULL;
  fila->size++;//o tamanho é incrementado
  return 0;
}

//remove o primeiro elemento da fila seguindo o parametro de FIFO (first in, first out)
int remove_F(Fila *fila, Item *it){
  if(empty(*fila))return -1;//verifica se está vazia
  PONT aux = fila->start;//cria um ponteiro auxiliar apontando para o começo da lista
  fila->start = aux->next;//aponta o começo para a segunda célula
  *it = aux->next->item;//recolhe o item
  fila->size--;//decrementa o tamanho
  free(aux);
  return 0;
}
