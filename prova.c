#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Função da questão
float f(float x) { return x * x * x + 2 * x * x + 3 * x - 4; }

// Função de cálculo da altura do triângulo
float altura_tri(float base, float x) {
  float h;
  h = sqrt(pow(base, 2) - pow((base / 2.0), 2));
  return h;
}

int main() {
  float a = 3.0, b = 8.0;
  int n;
  printf("Digite o número de intervalos (n): ");
  scanf("%d", &n);
  float dx = (b - a) / n;
  float x = a;
  float soma_area = 0.0;
  for (int i = 0; i < n; i++) {
    float base = dx;
    float h = altura_tri(base, x + dx / 2.0);
    float area_retangulo = base * f(x + dx / 2.0);
    float area_triangulo = base * h / 2.0;
    float area_total = area_retangulo + area_triangulo;
    soma_area += area_total;
    x += dx;
  }
  printf("Área sob a curva: %.2f\n", soma_area);
  return 0;
}
