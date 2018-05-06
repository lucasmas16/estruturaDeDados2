#if !defined(LIST_H)
    #define LIST_H
    #include <stdlib.h>
    #include <string.h>
    #include "item.h" //inclue a strutura do item e alguns auxiliares

    typedef struct Celula_N *PONT;

    typedef struct Celula_N {
        ITEM item;
        PONT next;
    } Cel;

    typedef struct{
        PONT first, last;
    } LIST;

    void newList(LIST *list){
        list->first = (PONT) malloc(sizeof(Cel));
        list->last = list->first;
        list->first->next = NULL;
    }

    void insertList(ITEM item, LIST *list){
        list->last->next = (PONT) malloc(sizeof(Cel));
        list->last = list->last->next;
        list->last->item = item;
        list->last->next = NULL;
    }

    int removeList(ITEM *item, LIST *list){
        PONT run, aux;
        run = list->first;
        while(run->next != NULL){
            if(strncmp(run->next->item.nome, item->nome, N)){
                run = run->next;
            }else{
                *item = run->next->item;
                aux = run->next;
                run->next = run->next->next;
                free(aux);
                return 0;
            }
        }
        return -1;
    }

    int searchList(ITEM *item, LIST list){
        PONT run, aux;
        run = list.first;
        while(run->next != NULL){
            if(strncmp(run->next->item.nome, item->nome, N)){
                run = run->next;
            }else{
                return 0;
            }
        }
        return -1;
    }

    int voidList(LIST list){
        if(list.first == list.last){
            return 0;
        }
        return -1;
    }


#endif