#include "data.h"

#if !defined(OPENHASH_H)
#define OPENHASH_H

    #define EMPTY "                    "
    #define REMOVED "********************"
    #define MAX 199

    typedef ITEM DICTIONARY[MAX];

    int newDictionary(ITEM*);
    int h (CHAVE);
#endif

