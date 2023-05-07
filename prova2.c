#include <math.h>
#include <stdio.h>

#define erro 0.0001 // define a constante erro com o valor 0.0001

float f(float x) { return x * x * x + 2 * x * x + 3 * x - 4; }

int main() {
  float a = 0, b = 2, c,
        fc;  // As variáveis A e B representam o intervalo inicial de busca, c
             // representa o ponto médio do intervalo.
  int n = 0; // Número de iterações do algoritmo

  while (fabs(b - a) > erro) {
    c = (a + b) / 2;
    fc = f(c);

    printf("n = %d, a = %.6f, b = %.6f, c = %.6f, f(c) = %.6f\n", n, a, b, c,
           fc);

    // verifica se f(c) é igual a zero. Se sim, a raiz foi encontrada e o loop é
    // encerrado.
    if (fc == 0) {
      break;
    } else if (fc * f(a) > 0) {
      // Se f(c) e f(a) têm o mesmo sinal, a raiz está no intervalo [c, b],
      // então a variável a é atualizada para c.
      a = c;
    } else {
      // Caso contrário, a raiz está no intervalo [a, c], então a variável b é
      // atualizada para c.
      b = c;
    }

    n++;
  }

  printf("A raiz aproximada é %.6f com erro de %.6f\n", c, erro);

  return 0;
}
