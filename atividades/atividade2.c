#include <stdio.h>

#define TAM 10 // define o tamanho do array

int main() {
  int numeros[TAM];
  int i;
  int soma_pares = 0;
  int produto_impares = 1;

  // lê os números do array
  for (i = 0; i < TAM; i++) {
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &numeros[i]);
  }

  // calcula a soma nos endereços pares e o produto nos endereços ímpares
  for (i = 0; i < TAM; i++) {
    if (i % 2 == 0) { // endereço par
      soma_pares += numeros[i];
    } else { // endereço ímpar
      produto_impares *= numeros[i];
    }
  }

  // imprime os resultados
  printf("Soma nos endereços pares: %d\n", soma_pares);
  printf("Produto nos endereços ímpares: %d\n", produto_impares);

  return 0;
}
