typedef struct{
  char item;
  Celula *next;
} Celula;

typedef struct{
  Celula topo;
} Pilha;

void push(Pilha *pilha, char newItem){
  Celula new = (Celula)malloc(sizeof(Celula));
  new->item = newItem;
  new->next = pilha->topo;
  pilha->topo = new;
}

Celula pop(Pilha *pilha){
  Celula new = (Celula)malloc(sizeof(Celula));
  new = pilha->topo;
  pilha->topo = pilha->topo->next;
  return new;
}

char watch(Pilha *pilha){
  return pilha->item;
}
