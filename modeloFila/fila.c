#include "fila.h"

//inicializa a fila
int newFila(Fila *fila){
  fila->start = (PONT)malloc(sizeof(Celula));//aloca espaço para a célula cabeçalho e aponta o start para lá
  fila->end = fila->start;//aponta o fim para o cabeçalho
  fila->size = 0;//inicializa o tamanho com 0
}

//verifica de a fila está vazia
int empty(Fila fila){
  return fila.start == fila.end;
}

//insere elemento no fim da fila
int insert(Fila *fila, Item newItem){
  PONT nova = (PONT)malloc(sizeof(Celula));//inicia um novo ponteiro alocando o espaço para uma célula
  nova->item = newItem;//item da nova célula recebe o item do parâmetro
  nova->next = NULL;//aponta o next do ultimo elemento para NULL
  fila->end->next = nova;//a nova célula é inserida após o último item
  fila->end = nova;//o fim passa a apontar para a nova célula
  fila->size++;//o tamanho é incrementado
  return 0;
}

//remove o primeiro elemento da fila seguindo o parametro de FIFO (first in, first out)
int remove(Fila *fila, Item *it){
  if(empty(*fila))return -1;//verifica se está vazia
  PONT aux = fila->start;//cria um ponteiro auxiliar apontando para o começo da lista
  *it = fila->start->next->item;//recolhe o item
  fila->star = aux->next;//aponta o começo para a segunda célula
  fila->size--;//decrementa o tamanho
  return 0;
}
