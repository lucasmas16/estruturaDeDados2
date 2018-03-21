#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


int main(void){
  int op, iAux;
  Item aux;
  Fila filaTeste;
  newFila(&filaTeste);
  do{
    printf("1 - Verificar se está vazia");
    printf("2 - Inserir número");
    printf("3 - Remover número");
    printf("Digite a opção desejada: ");
    scanf("%d", &op);
    switch (op){
      case 0:
        printf("Fim do programa!");
        break;
      case 1:
        if(empty(filaTeste)){
          printf("Lista vazia");
        }
        break;
      case 2:
        printf("Digite um número a ser inserido: ");
        scanf("%d", &iAux);
        aux.chave = iAux;
        insert(&filaTeste, aux);
        break;
      case 3:
        iAux = remove(&filaTeste, &aux);
        if(iAux == 0){
          printf("O elemento removido foi: %d", aux.chave);
        }else{
          printf("Lista vazia ou erro ao remover!");
        }
        break;
      default:
        printf("Digite um opção válida!");
        break;
    }
  }while(op != 0);
  return 0;
}
