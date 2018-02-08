#include <stdio.h>
#include <math.h>
int fatorialIterativo(int n){
  int resp = 1;
  int i;
  for(i = 1; i <= n; i++ ){
    resp *= i;
  }
  return resp;
}
int fatorialRecursivo(int n){
  if(n <= 1) return 1;
  return n * fatorialRecursivo(n - 1);
}
int main(void) {
	setbuf(stdout, NULL);
  
  int n;
	printf("\nDigite número para digitar o fatorial: ");
	fflush(stdin);
	scanf("%d", &n);
  printf("O fatorial iterativo é: %d\nO fatorial recursivo é: %d", fatorialIterativo(n), fatorialRecursivo(n));
  printf("\nSucesso\n");
  return 0;
}