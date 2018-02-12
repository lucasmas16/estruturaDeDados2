typedef struct Celula_str *Apontador;

typedef struct {
  int Chave;
} TipoItem;

typedef struct Celula_str {
  TipoItem Item;
  Apontador Prox;
} Celula;

typedef struct {
  Apontador Primeiro, Ultimo;
} TipoLista;

void EsvaziarLista(TipoLista *Lista){
  Lista->Primeiro = (Apontador) malloc(sizeof(Celula));
  Lista->Ultimo = Lista->Primeiro;
  Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista){
  return(Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista){
  Lista->Ultimo->Prox = (Apontador) malloc(sizeof(Celula));
  Lista->Ultimo = Lista->Ultimo->Prox;
  Lista->Ultimo->Item = x;
  Lista->Ultimo-Prox = NULL;
}

void Retira(Apontador p, TipoLista *Lista, TipoItem *Item){
  if(Vazia(*Lista) || p == NULL || p->Prox == NULL){
    printf("Erro: Lista vazia ou nao existe \n");
    return;
  }q = p->Prox;
  *Item = q->Item;
  p->Prox = q->Prox;
  if(p->Prox == NULL){
    Lista->Ultimo = p;
  }
  free(q);
}

void Imprime(TipoLista Lista){
  Apontador Aux;
  Aux = Lista.Primeiro->Prox;
  while(Aux != NULL){
    printf("%12ld\n", Aux->Item.Chave);
    Aux = Aux->Prox;
  }
  
}