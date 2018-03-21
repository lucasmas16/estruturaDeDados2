//define que o tipo de item da fila
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


//Estrutura de fila usando variável topo, fim e tamanho
typedef struct Fila{
  PONT start, end;
  int size;
} Pilha;
