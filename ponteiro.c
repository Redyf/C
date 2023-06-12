#include <stdio.h>
void soma(int a, int b, int *num) {
  *num = (a + b) * 2;
  printf("A soma de %d + %d é igual a %d", a, b, *num);
}

int main() {
  int *num;
  soma(2, 3, num);
}
