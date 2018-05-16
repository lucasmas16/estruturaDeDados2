#if !defined(ARVORE_H)
    #define ARVORE_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "item.h" //inclue a strutura do item e alguns auxiliares
    
    //
    typedef struct NO_TAG *PONT;

    typedef struct NO_TAG {
        ITEM item;
        PONT esq, dir;
    }NO;

    typedef PONT ARVORE;

    typedef ARVORE DICIONARIO;

    int h (CHAVE);

    void newDic(DICIONARIO*);

    int search(ITEM*, PONT*);

    int insert(ITEM, PONT*);

    void antecessor (PONT, PONT*);

    int rem(ITEM, PONT*);

#endif