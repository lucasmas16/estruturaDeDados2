#if !defined(DATA_H)
#define DATA_H
#define MAXTAM  25  /* Altere de acordo com seus testes */

typedef int CHAVE;

typedef struct ITEM_TAG {
    CHAVE chave;
} ITEM;

typedef ITEM VETOR[MAXTAM];

#endif
