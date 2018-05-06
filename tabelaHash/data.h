#if !defined(DATA_H)
    #define DATA_H
    #define N 21
    #define REMOVED "********************"
    #define EMPTY "                    "
    typedef char CHAVE [N];
    typedef struct {
    CHAVE name;
    double price;
    } ITEM;
#endif