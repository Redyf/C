// Escreva um programa que peça um inteiro ao usuário, e com esse inteiro, ele
// imprima, linha-a-linha, a tabuada daquele número até o 10. Por exemplo, se
// ele escolher o número 2, o programa imprimirá: 2x1=2, 2x2=4, 2x3=6,...,
// 2x10=20.
#include <stdio.h>

int main() {
  int num;
  printf("Digite um número inteiro: ");
  scanf("%d", &num);

  for (int i = 1; i <= 10; i++) {
    printf("%dx%d=%d\n", num, i, num * i);
  }
  return 0;
}
