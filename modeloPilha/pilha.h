//define que o tipo de item
typedef struct {
  int chave;
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
  Apontador start, end;
  int size;
} Pilha;
