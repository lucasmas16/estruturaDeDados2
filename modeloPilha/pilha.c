#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>


int newPilha(Pilha *pilha){
	pilha->start = (PONT)malloc(sizeof(Celula));//aloca espaço para a célula cabeçalho e aponta o start para lá
	pilha->end = pilha->start;//aponta o fim para o cabeçalho
	pilha->start->next = NULL;//define como nulo a proxima depois com cabeçalho
	pilha->size = 0;//inicializa o tamanho com 0
  	return 0;
}

int empty(Pilha pilha){
  return pilha.start == pilha.end;//se o começo e o fim aprontarem para a mesma célula significa que a lista está vazia apenas com o cabeçalho
}

//insere elemento no começo da pilha
int push(Pilha *pilha, Item newItem){
  PONT nova = (PONT)malloc(sizeof(Celula));//inicia um novo ponteiro alocando o espaço para uma célula
  pilha->start->item = newItem;//o header assume um novo item
  nova->next = pilha->start;//linka a nova célula como header
  pilha->start = nova;//transfere o topo da pilha para o novo elemento
  pilha->size++;//incrementa o tamanho da pilha
  return 0;
}

//desempilha o primeiro elemento
int pop(Pilha *pilha, Item *item){
	if(empty(*pilha)) return -1;//verifica se a lista está vazia
	*item = pilha->start->next->item;//retorna o item para o parâmetro
	PONT aux = pilha->start;//cria um ponteiro auxiliar que aponta para o header
	pilha->start = aux->next;//o topo apronta para o segundo elemento da lista e ele passa a ser o cabeçalho
	free(aux);//limpa o endereço do antigo cabeçalho
	pilha->size--;//decrementa o tamanho da pilha
  	return 0;
}

//retorna o conteudo do primeiro elemento para efetuar comparações
int look(Pilha *pilha, Item *item){
	if(empty(*pilha)) return -1;
  	*item = pilha->start->next->item;
  	return 0;
}
