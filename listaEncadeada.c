#include <stdio.h>
#include <stdlib.h>

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
  Lista->Ultimo->Prox = NULL;
}
/*
void Retira(TipoLista *lista){
  Apontador p = lista.Primeiro;
  TipoItem *i = lista.Primeiro.Item;
  Apontador q;
  if(Vazia(*lista) || p == NULL || p->Prox == NULL){
    printf("Erro: Lista vazia ou nao existe \n");
    return;
  }
  q = p->Prox;
  i = q->Item;
  p->Prox = q->Prox;
  if(p->Prox == NULL){
    Lista->Ultimo = p;
  }
  free(q);
}*/

void Imprime(TipoLista Lista){
  Apontador Aux;
  Aux = Lista.Primeiro->Prox;
  while(Aux != NULL){
    printf("%d\n", Aux->Item.Chave);
    Aux = Aux->Prox;
  }
}

int main(void){
  setbuf(stdout, NULL);
  int choice;
  TipoItem item;
  TipoLista lista;
  TipoLista *plista = &lista;
  EsvaziarLista(plista);

  do{
    printf("Inserir item na lista          - 1\n");
    printf("Remover primeiro item da lista - 2\n");
    printf("Esvasiar a lista               - 3\n");
    printf("Imprimir a lista               - 4\n");
    printf("Sair do programa               - 0\n");
    printf("Digite a opcao desejada:");
    fflush(stdin);
  	scanf("%d", &choice);
    switch(choice){
      case 1:
        printf("Digite um numero para inserir na lista: ");
        fflush(stdin);
        scanf("%d", &item.Chave);
        Insere(item, plista);
        break;
      case 2:
        //Retira(plista);
        break;
      case 3:
        EsvaziarLista(plista);
        if(Vazia(lista))printf("Lista vazia\n");
        break;
      case 4:
        Imprime(lista);
        break;
    }
  }while(choice != 0);
  
}