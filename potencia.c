#include <stdio.h>

void potencia(int a, int b) {
  int resultado = 1;
  for (int i = 0; i < b; i++) {
    resultado = resultado * a;
  }

  printf("O resultado é %d\n", resultado);
}

int main() {
  potencia(2, 3);
  return 0;
}
