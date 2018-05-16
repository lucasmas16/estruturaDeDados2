    #include <stdlib.h>
    #include <string.h>
    #include "list.h" //inclue a strutura do item e alguns auxiliares

    //Metodo para criação de uma nova lista onde alocasse o header
    void newList(LIST *list){
        list->first = (PONT) malloc(sizeof(Cel));
        list->last = list->first;
        list->first->next = NULL;
    }

    //Aloca espaço e insere um elemnto no fim da lista
    void insertList(ITEM item, LIST *list){
        list->last->next = (PONT) malloc(sizeof(Cel));
        list->last = list->last->next;
        list->last->item = item;
        list->last->next = NULL;
    }

    //percorre a lista e se achar o elemento o remove retorna 0. Retorna -1 caso não exista o elemento
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

    //procura na lista um item, caso o ache carrega o restante do conteudo e retorna 0
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

    //verifica se a lista está vazia
    int voidList(LIST list){
        if(list.first == list.last){
            return 0;
        }
        return -1;
    }