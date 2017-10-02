#include <stdio.h>
#include <math.h>

int factorial (int n);
float e();

int main() {
  printf("\nValor aproximado do numero de Euler :: e = %f\n", e());
  
  return 0; 
}

int factorial (int n) {
  int i;
  int sum = 1;
  
  for (i = 1; i <= n; i++) {
    sum *= i;
  }
  
  return sum;
}

float e() {
  float e = 1, aux = 0;
  int i = 1;
  
  do {
    aux = (1.0 / factorial(i));
    e += aux;
    i++;
  } while (aux >= pow(10,-6));
  
  return e;
}
