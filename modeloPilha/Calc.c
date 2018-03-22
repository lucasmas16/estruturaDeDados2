#include "Pilha.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define EOE '#'

int opera(char, Pilha*);

int main (int argc, char *argv[]){
	//Verifica se foi passado um elemento como parâmetro junto com a execução do programa
	if(argc < 2){
    	printf("\nExpressão não informada!\n");
    	return -1;
  	}

	//Cria um ponteiro que aponta para
  	char *expre = argv[1];

	//Criação de itens auxiliares
	Item operadorI;
	Item operandoI;

	//Criação de lista de operadores e operandos
  	Pilha operadorP, operandoP;
  	newPilha(&operadorP);
  	newPilha(&operandoP);

	//insere o elemento final da pilha do operandos
	operadorI.op = EOE;
	push(&operadorP, operadorI);

	while(*expre != '\0'){
		if(isspace(*expre)) continue;
		switch(*expre){
			case '+':
			case '-':
				if(look(&operadorP, &operadorI) == -1){
					printf("Expressão inválida1!");
					return -1;
				}
				if(operadorI.op == '+' || operadorI.op == '-' ||
				   operadorI.op == '/' || operadorI.op == '*' ||
				   operadorI.op == 'x'){
					pop(&operadorP, &operadorI);
					if(opera(operadorI.op, &operandoP) == -1){
						printf("Expressão inválida2!");
						return -1;
					}
				}
				operadorI.op = *expre;
				push(&operadorP, operadorI);
				break;
			case '*':
			case 'x':
			case '/':
				if(look(&operadorP, &operadorI) == -1){
					printf("Expressão inválida3!");
					return -1;
				}
				if(operadorI.op == '/' || operadorI.op == '*' ||
				   operadorI.op == 'x'){
					pop(&operadorP, &operadorI);
					if(opera(operadorI.op, &operandoP) == -1){
						printf("Expressão inválida4!");
						return -1;
					}
				}
				operadorI.op = *expre;
				push(&operadorP, operadorI);
				break;
			case '(':
				operadorI.op = *expre;
				push(&operadorP, operadorI);
				break;
			case ')':
				do{
					if(pop(&operadorP, &operadorI) == -1){
						printf("Expressão inválida!");
						return -1;
					}
					if(operadorI.op != '('){
						if(opera(operadorI.op, &operandoP) == -1){
							printf("Expressão inválida!");
							return -1;
						}
					}
				}while(operadorI.op != '(');
				break;
			default:
				if(!isdigit(*expre)){
					printf("Expressão inválida!");
					return -1;
				}
				operandoI.op = (int)(*expre - 48);
				push(&operandoP, operandoI);
		}
		printf("Elemento no laço: %c\n", *expre);
		expre++;
	}
	do{
		if(look(&operadorP, &operadorI) == -1){
			printf("Expressão inválida!");
			return -1;
		}
		if(operadorI.op != EOE){
			pop(&operadorP, &operadorI);
			if(opera(operadorI.op, &operandoP) == -1){
				printf("Expressão inválida!");
				return -1;
			}
		}
	}while(operadorI.op != EOE);
	printf("Tamanho da pilha %d\n", operandoP.size);
	if(operandoP.size != 1){
		printf("Expressão inválida!");
		return -1;
	}
	pop(&operandoP, &operandoI);
	return 0;
}

int opera(char op, Pilha *operando){
	int op1, op2;
	Item operandoI;
	if(pop(operando, &operandoI) == -1) return -1;
	op2 = operandoI.op;
	if(pop(operando, &operandoI) == -1) return -1;
	op1 = operandoI.op;
	switch (op) {
		case '+':
			operandoI.op = op1 + op2;
			break;
		case '-':
			operandoI.op = op1 - op2;
			break;
		case '*':
			operandoI.op = op1 * op2;
			break;
		case 'x':
			operandoI.op = op1 * op2;
			break;
		case '/':
			operandoI.op = op1 / op2;
			break;
		default:
			return -1;
	}
	push(operando, operandoI);
	return 0;
}
