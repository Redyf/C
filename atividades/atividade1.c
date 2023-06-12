#include <math.h>
#include <stdio.h>

int main() {

  int i, op, x[1000], max;
  printf("Digite a quantidade desejada de Arrays: ");
  scanf("%d", &max);

  for (i = 1; i <= max; i++) {
    printf("Digite um valor: ");
    scanf("%d", &x[i]);
  }

  printf("Formas de descarregar:\n");
  printf("1 - Direta\n");
  printf("2 - Inversa\n");
  printf("Como quer descarregar: ");
  scanf("%d", &op);

  if (op == 1) {
    for (i = 1; i <= max; i++) {

      printf("%d\n", x[i]);
    }
  } else if (op == 2) {
    for (i = max; i >= 1; i--) {
      printf("%d\n", x[i]);
    }
  }
}
