#include "Pilha.h"
#include <stdlib.h>
#include <stdio.h>
#define EOE '#'

int main (int argc, char *argv[]){
	//Verifica se foi passado um elemento como parâmetro junto com a execução do programa
	if(argc < 2){
    	printf("\nExpressão não informada!\n");
    	return -1;
  	}
	
	//Cria um ponteiro que aponta para 
  	char *expre = &argv[1];
	
	//Criação de itens auxiliares
	Item operadorI;
	Item operandoI;
	
	//Criação de lista de operadores e operandos
  	Pilha operadorP, operandoP;
  	newPilha(&operadorP);
  	newPilha(&operandoP);
	
	//insere o elemento final da pilha do operandos
	operadorI->op = EOE;
	push(&operadorP);
	
	while(*expre == '\0'){
		if(isspace(*expre)){
		}
	}
}
