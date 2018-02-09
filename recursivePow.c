#include <stdio.h>
#include <math.h>

double recursivePow(double x, int n){
  if(n == 0) return 1;
  else if(n < 0)return 1/recursivePow(x, -n);
  else if(n % 2 == 0){
    double temp = recursivePow(x, n/2);
    return temp * temp;
  }
  return x*recursivePow(x, n-1);
}
int main(void) {
	setbuf(stdout, NULL);
  double x;
  int n;
	printf("\nDigite número para calcular o potencia: ");
	fflush(stdin);
	scanf("%lf", &x);
 	printf("\nDigite n para calcular o potencia: ");
	fflush(stdin);
	scanf("%d", &n);
  printf("A potencia de %lf^%d = %lf", x, n, recursivePow(x, n));
  printf("\nSucesso\n");
  return 0;
}