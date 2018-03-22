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

	//executa até chegar no ultimo elemento do parâmetro
	while(*expre != '\0'){

		//se receber um espaço em branco ele passa para o proximo elemento sem executar tudo
		if(isspace(*expre)){
			expre++;
			continue;
		}

		//switch para verificar o operador ou operando que está no ponteiro
		switch(*expre){

			//no caso de adição ou subtração
			case '+':
			case '-':

				//verifica se a lista de operadores está vazia, como existe o EOE nunca deve entrar aqui
				if(look(&operadorP, &operadorI) == -1){
					printf("Expressão inválida1!");
					return -1;
				}

				//verifica de o resultado do look é um operador de maior ou igual prioridade
				if(operadorI.op == '+' || operadorI.op == '-' ||
				   operadorI.op == '/' || operadorI.op == '*' ||
				   operadorI.op == 'x'){
					pop(&operadorP, &operadorI);//caso seja mais prioritário ele popa o operador do topo

					//faz a operação com o operador popado
					if(opera(operadorI.op, &operandoP) == -1){
						printf("Expressão inválida2!");
						return -1;
					}
				}

				//depois de operar caso necessário, ele impilha o operador que está sendo recebido no ponteiro
				operadorI.op = *expre;
				push(&operadorP, operadorI);
				break;

			//no caso de multiplicação ou divisão
			case '*':
			case 'x':
			case '/':

				//puxa o operador do topo da lista
				if(look(&operadorP, &operadorI) == -1){
					printf("Expressão inválida3!");
					return -1;
				}

				//verifica se o puxado no look é de igual ou maior prioridade
				if(operadorI.op == '/' || operadorI.op == '*' ||
				   operadorI.op == 'x'){
					//caso seja ele popa e faz a operação com o operador do topo da lista
					pop(&operadorP, &operadorI);
					if(opera(operadorI.op, &operandoP) == -1){
						printf("Expressão inválida4!");
						return -1;
					}
				}
				//joga o operador do ponteiro para o topo da pilha
				operadorI.op = *expre;
				push(&operadorP, operadorI);
				break;

			//no caso de "(" só empilha
			case '(':
				operadorI.op = *expre;
				push(&operadorP, operadorI);
				break;

			//no caso de ")" roda um loop até achar o "("
			case ')':
				do{
					//popa o operador
					if(pop(&operadorP, &operadorI) == -1){
						printf("Expressão inválida!");
						return -1;
					}

					//executa a operação
					if(operadorI.op != '('){
						if(opera(operadorI.op, &operandoP) == -1){
							printf("Expressão inválida!");
							return -1;
						}
					}
				}while(operadorI.op != '(');
				break;

			//se não caiu em nenhuma das outras, provavelmente é um número
			default:
				//verifica se é um digito
				if(!isdigit(*expre)){
					printf("Expressão inválida!");
					return -1;
				}
				//converte o valor e empilha
				operandoI.op = (int)(*expre - 48);
				push(&operandoP, operandoI);
		}

		expre++;
	}

	//desempilha até acha o EOE
	do{
		//pega o operador do topo da pilha
		if(look(&operadorP, &operadorI) == -1){
			printf("Expressão inválida!");
			return -1;
		}
		//executa a operação
		if(operadorI.op != EOE){
			pop(&operadorP, &operadorI);
			if(opera(operadorI.op, &operandoP) == -1){
				printf("Expressão inválida!");
				return -1;
			}
		}
	}while(operadorI.op != EOE);

	//varifica de há apenas o resultado na pilha de operandos
	if(operandoP.size != 1){
		printf("Expressão inválida!");
		return -1;
	}
	
	//puxa o resultado e exibe
	pop(&operandoP, &operandoI);
	printf("Resultado: %d", operandoI.op);
	return 0;
}

//metodo que faz a operação
int opera(char op, Pilha *operando){
	//variáveis auxiliares 
	int op1, op2;
	Item operandoI;
	
	//puxa os operandos da pilha
	if(pop(operando, &operandoI) == -1) return -1;
	op2 = operandoI.op;
	if(pop(operando, &operandoI) == -1) return -1;
	op1 = operandoI.op;
	
	//executa a operação
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
	
	//retorno dos resultados
	push(operando, operandoI);
	return 0;
}
