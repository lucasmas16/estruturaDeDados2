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
