#include <stdio.h>
#include <stdlib.h>

//define que o tipo de item da pilha será Char
typedef struct {
  char chave;
}Item;

//Define um ponteiro para poder referênciar dentro da estrutura da célula
typedef struct Cel *Apontador;

//Estrutura de Célula
typedef struct Cel{
  Item item;//item da célula | pode ser alterado para qualquer outro tipo de estrutura
  Apontador next;//ponteiro para a proxima célula
} Celula;


//Estrutura de Pilha usando apenas variável do topo
typedef struct Pilha{
  Apontador topo;
} Pilha;

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
