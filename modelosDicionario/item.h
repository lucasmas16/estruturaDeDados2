#if !defined(ITEM_H)
    #define ITEM_H
    #define N 21
    #define M 199
    #define REMOVED "********************"
    #define EMPTY "                    "
    typedef char CHAVE [21];
    typedef struct {
        CHAVE nome;
        double preco;
    } ITEM;
#endif
