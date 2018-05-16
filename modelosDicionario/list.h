#if !defined(LIST_H)
    #define LIST_H
    #include "item.h" //inclue a strutura do item e alguns auxiliares

    //ponteiro de celula
    typedef struct Celula_N *PONT;

    //estrutura da celula
    typedef struct Celula_N {
        ITEM item;
        PONT next;
    } Cel;

    //Estrutura inicial da lista
    typedef struct{
        PONT first, last;
    } LIST;

    typedef LIST DICIONARIO[M];

    void newList(LIST*);

    void insertList(ITEM, LIST*);

    int removeList(ITEM*, LIST*);

    int searchList(ITEM*, LIST);

    int voidList(LIST);
#endif