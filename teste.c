#include <stdio.h>

// Testando conversão de tipis de variáveis (Casting)
// Ter cuidado com o casting quando converter variáveis grandes em pequenas,
// tipo de long (8 bytes) para int (4 bytes)

int main(int argc, char *argv[]) {

  int a = 3;
  int b = 2;
  double pontos = (double)a / (double)b;
  printf("%f\n", pontos);

  double pi = 3.1415;
  int piconvertido = (int)pi;

  printf("%f %d\n", pi, piconvertido);
  return 0;
}
