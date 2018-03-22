#include "fila.h"
#include <stdlib.h>
#include <stdio.h>


int main(void){
  int op, iAux;
  Item aux;
  Fila filaTeste;
  newFila(&filaTeste);
  printf("\n1 - Verificar se está vazia\n");
  printf("2 - Inserir número\n");
  printf("3 - Remover número\n");
  printf("0 - Sair do programa!\n");
  printf("Digite a opção desejada: ");
  scanf("%d", &op);
  do{
    printf("\n1 - Verificar se está vazia\n");
    printf("2 - Inserir número\n");
    printf("3 - Remover número\n");
    printf("0 - Sair do programa!\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &op);
    switch (op){
      case 0:
        printf("Fim do programa!\n");
        break;
      case 1:
        if(empty(filaTeste)){
          printf("Lista vazia\n");
        }
        break;
      case 2:
        printf("\nDigite um número a ser inserido: ");
        scanf("%d", &iAux);
        aux.chave = iAux;
        printf("Elemento inserido %d\n", aux.chave);
        insert(&filaTeste, aux);
        break;
      case 3:
        iAux = remove_F(&filaTeste, &aux);
        if(iAux == 0){
          printf("\nO elemento removido foi: %d", aux.chave);
        }else{
          printf("\nLista vazia ou erro ao remover!");
        }
        break;
      default:
        printf("\nDigite um opção válida!");
        break;
    }
  }while(op != 0);
  return 0;
}
