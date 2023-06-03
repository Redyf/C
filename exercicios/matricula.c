// Desenvolva um programa para inserir, apagar, alterar registros em um arquivo.
// O layout do arquivo (número de matrícula com até 5 caracteres, nome do aluno
// com até 30 caracteres, nota 1, nota 2 e nota 3 com até 5 caracteres
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATRICULA 6
#define MAX_NOME 31
#define MAX_NOTA 6

// Função para imprimir o registro
void imprimirRegistro(const char matricula[MAX_MATRICULA],
                      const char nome[MAX_NOME], const char nota1[MAX_NOTA],
                      const char nota2[MAX_NOTA], const char nota3[MAX_NOTA]) {
  printf("Matrícula: %s\n", matricula);
  printf("Nome: %s\n", nome);
  printf("Primeira Nota: %s\n", nota1);
  printf("Segunda Nota: %s\n", nota2);
  printf("Terceira Nota: %s\n", nota3);
  printf("\n");
}

// Utilizando ponteiro para direcionar o arquivo que será criado na hora de
// execução, nessa função ele irá apenas imprimir o registro! Caso exista
void imprimirRegistrosArquivo(const char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  char matricula[MAX_MATRICULA];
  char nome[MAX_NOME];
  char nota1[MAX_NOTA];
  char nota2[MAX_NOTA];
  char nota3[MAX_NOTA];

  // Passo as varíaveis para o loop, depois serão lidas individualmente. A
  // matrícula está separada pois ao mencionar o número da matrícula do aluno,
  // será imprimido na tela as informações abaixo. Então fechará o arquivo.
  while (fread(matricula, sizeof(char), MAX_MATRICULA, arquivo) ==
         MAX_MATRICULA) {
    fread(nome, sizeof(char), MAX_NOME, arquivo);
    fread(nota1, sizeof(char), MAX_NOTA, arquivo);
    fread(nota2, sizeof(char), MAX_NOTA, arquivo);
    fread(nota3, sizeof(char), MAX_NOTA, arquivo);

    imprimirRegistro(matricula, nome, nota1, nota2, nota3);
  }

  fclose(arquivo);
}

// Função para inserir um registro no arquivo
void inserirRegistro(FILE *arquivo) {
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  char matricula[MAX_MATRICULA];
  char nome[MAX_NOME];
  char nota1[MAX_NOTA];
  char nota2[MAX_NOTA];
  char nota3[MAX_NOTA];

  // Pede ao usuário para inserir as informações (matrícula, nome, nota1,2,3).
  printf("Digite a matrícula (até 5 caracteres): ");
  scanf("%s", matricula);

  printf("Digite seu nome (até 30 caracteres): ");
  scanf("%s", nome);

  printf("Digite sua primeira nota (até 5 caracteres): ");
  scanf("%5s", nota1);

  printf("Digite sua segunda nota (até 5 caracteres): ");
  scanf("%5s", nota2);

  printf("Digite sua terceira nota (até 5 caracteres): ");
  scanf("%5s", nota3);

  // Escreve os valores das varíaveis e confere a quantidade de caracteres
  // escritos e armazena no arquivo!
  fwrite(matricula, sizeof(char), MAX_MATRICULA, arquivo);
  fwrite(nome, sizeof(char), MAX_NOME, arquivo);
  fwrite(nota1, sizeof(char), MAX_NOTA, arquivo);
  fwrite(nota2, sizeof(char), MAX_NOTA, arquivo);
  fwrite(nota3, sizeof(char), MAX_NOTA, arquivo);

  printf("Registro inserido com sucesso");

  fclose(arquivo);
}

// Função para apagar um registro do arquivo
void apagarRegistro(FILE *arquivo, const char *matricula) {
  // Cria um arquivo temporário chamado temp para armazenar as informações,
  // seestiver vazio ele irá mostrar o texto abaixo!
  FILE *temp = fopen("temp.txt", "wb");
  if (temp == NULL) {
    printf("Erro ao criar o arquivo temporário.\n");
    fclose(arquivo);
    return;
  }

  char regMatricula[MAX_MATRICULA];
  char regNome[MAX_NOME];
  char regNota1[MAX_NOTA];
  char regNota2[MAX_NOTA];
  char regNota3[MAX_NOTA];

  // Mesmo loop usado na função inserirRegistro porém dessa vez ele lê e compara
  // as strings com o strcmp (stringcompare). Dessa forma ele pode ver as
  // matrículas já registradas e apaga-las se for pedido para executar tal ação.
  // É necessário citar o número da matrícula que deseja excluir!
  while (fread(regMatricula, sizeof(char), MAX_MATRICULA, arquivo) ==
         MAX_MATRICULA) {
    fread(regNome, sizeof(char), MAX_NOME, arquivo);
    fread(regNota1, sizeof(char), MAX_NOTA, arquivo);
    fread(regNota2, sizeof(char), MAX_NOTA, arquivo);
    fread(regNota3, sizeof(char), MAX_NOTA, arquivo);

    if (strcmp(regMatricula, matricula) != 0) {
      fwrite(regMatricula, sizeof(char), MAX_MATRICULA, temp);
      fwrite(regNome, sizeof(char), MAX_NOME, temp);
      fwrite(regNota1, sizeof(char), MAX_NOTA, temp);
      fwrite(regNota2, sizeof(char), MAX_NOTA, temp);
      fwrite(regNota3, sizeof(char), MAX_NOTA, temp);
    }
  }

  fclose(arquivo);
  fclose(temp);

  remove("dados.txt");
  rename("temp.txt", "dados.txt");

  printf("Registro apagado com sucesso!\n");
}

int main() {
  FILE *arquivo = fopen("dados.txt", "ab+");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo\n");
    return 1;
  }

  int opcao;
  char matricula[MAX_MATRICULA];

  // Oferece uma lista de opções para o usuário, a ação depende de sua escolha.

  printf("Selecione uma opção:\n");
  printf("1 - Imprimir registros\n");
  printf("2 - Inserir registro\n");
  printf("3 - Apagar registro\n");
  printf("4 - Sair\n");
  printf("Opção: ");
  scanf("%d", &opcao);

  if (opcao == 1) {
    imprimirRegistrosArquivo("dados.txt");
  } else if (opcao == 2) {
    inserirRegistro(arquivo);
  } else if (opcao == 3) {
    printf("Digite a matrícula do registro a ser apagado: ");
    scanf("%5s", matricula);
    apagarRegistro(arquivo, matricula);
  } else {
    printf("Opção inválida, encerrando processo...\n");
  }

  fclose(arquivo);
  return 0;
}
