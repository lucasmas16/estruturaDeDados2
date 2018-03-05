//define estrutura de Celula simple com um char
typedef struct{
  char item;
  Celula *next;
} Celula;

//define estrutura de Pilha
typedef struct{
  Celula topo;
} Pilha;

//insere elemento no começo da pilha
void push(Pilha *pilha, char newItem){
  Celula new = (Celula)malloc(sizeof(Celula));
  new->item = newItem;
  new->next = pilha->topo;
  pilha->topo = new;
}

//desempilha o primeiro elemento
void pop(Pilha *pilha, Celula *new){
  new = (Celula)malloc(sizeof(Celula));
  new = pilha->topo;
  pilha->topo = pilha->topo->next;
}

//retorna o conteudo do primeiro elemento para efetuar comparações
char watch(Pilha *pilha){
  return pilha->item;
}
