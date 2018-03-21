include "pilha.h"

int 

//insere elemento no começo da pilha
void push(Pilha *pilha, Item newItem){
  Apontador nova = (Apontador)malloc(sizeof(Celula));//inicia um novo ponteiro alocando o espaço para uma célula
  nova->item = newItem;//item da nova célula recebe o item do parâmetro
  nova->next = pilha->topo;//linka o próximo do novo elemento com o topo da pilha
  pilha->topo = nova;//transfere o topo da pilha para o novo elemento
}

//desempilha o primeiro elemento
void pop(Pilha *pilha, Apontador new){
  new = (Apontador)malloc(sizeof(Celula));//inicializa o novo elemento
  new = pilha->topo;//o novo elemento recebe o topo
  if(pilha->topo != NULL){//verifica se a pilha não está vazia
    pilha->topo = pilha->topo->next;//o topo passa a ser o segundo elemento
  }
}

//retorna o conteudo do primeiro elemento para efetuar comparações
char look(Pilha *pilha){
  return pilha->topo->item.chave;
}
