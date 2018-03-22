#if !defined(PILHA_H)
#define PILHA_H

//define que o tipo de item
typedef struct {
  char op;
}Item;

//Define um ponteiro para poder referênciar dentro da estrutura da célula
typedef struct Cel *PONT;

//Estrutura de Célula
typedef struct Cel{
  Item item;//item da célula | pode ser alterado para qualquer outro tipo de estrutura
  PONT next;//ponteiro para a proxima célula
} Celula;


//Estrutura de Pilha usando um apontador no começo e um no fim
typedef struct Pilha{
	PONT start, end;
	int size;
} Pilha;

int newPilha(Pilha*);
int empty(Pilha);
void push(Pilha*, Item);
void pop(Pilha*, Item*);
int look(Pilha*, Item*);

#endif
