typedef struct Celula_str *Apontador;

typedef struct Celula_str {
  int Item;
  Apontador Prox;
} Celula;

typedef struct {
  Apontador Primeiro, Ultimo;
} TipoLista;