#include <stdio.h>

void ordenarCrescente(int x[], int tamanho) {
  int i, j, aux;

  for (i = 0; i < tamanho - 1; i++) {
    for (j = 0; j < tamanho - 1 - i; j++) {
      if (x[j] > x[j + 1]) {
        aux = x[j];
        x[j] = x[j + 1];
        x[j + 1] = aux;
      }
    }
  }
}

void ordenarDecrescente(int x[], int tamanho) {
  int i, j, aux;

  for (i = 0; i < tamanho - 1; i++) {
    for (j = 0; j < tamanho - 1 - i; j++) {
      if (x[j] < x[j + 1]) {
        aux = x[j];
        x[j] = x[j + 1];
        x[j + 1] = aux;
      }
    }
  }
}

int main() {
  int tamanho;
  printf("Digite o tamanho do conjunto de numeros: ");
  scanf("%d", &tamanho);

  int numeros[tamanho];
  printf("Digite os numeros:\n");
  for (int i = 0; i < tamanho; i++) {
    scanf("%d", &numeros[i]);
  }

  char escolha;
  printf("Digite 'c' para ordem crescente ou 'd' para ordem decrescente: ");
  scanf(" %c", &escolha);

  if (escolha == 'c') {
    ordenarCrescente(numeros, tamanho);
  } else if (escolha == 'd') {
    ordenarDecrescente(numeros, tamanho);
  } else {
    printf("Escolha invalida.\n");
    return 0;
  }

  printf("Numeros ordenados: ");
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", numeros[i]);
  }
  printf("\n");

  return 0;
}
