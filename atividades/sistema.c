#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alunos
#define MAX_MATRICULA 6
#define MAX_NOME 31
#define MAX_NOTA 6

// Funcionarios
#define MAX_ID 4
// #define MAX_NOME 31
#define MAX_CARGO 21
#define MAX_DISCIPLINA 31
#define MAX_CARGA_HORARIA 21

// Disciplina
#define MAX_SEMESTRE 21
#define MAX_PROFESSOR 31  // Pensar sobre essa variável
#define MAX_DIADASEMANA 21

// Função para imprimir o registro TODO: criar função imprimirRegistroAluno (basicamente essa aqui) e imprimirRegistroFuncionario
void imprimirRegistroAluno(const char matricula[MAX_MATRICULA],
                           const char nome[MAX_NOME], const char nota1[MAX_NOTA],
                           const char nota2[MAX_NOTA], const char nota3[MAX_NOTA]) {
    printf("Matrícula: %s\n", matricula);
    printf("Nome: %s\n", nome);
    printf("Primeira Nota: %s\n", nota1);
    printf("Segunda Nota: %s\n", nota2);
    printf("Terceira Nota: %s\n", nota3);
    printf("\n");
}

void imprimirRegistroFuncionario(const char id[MAX_ID],
                                 const char nome[MAX_NOME], const char cargo[MAX_CARGO],
                                 const char disciplina[MAX_DISCIPLINA], const char carga_horaria[MAX_CARGA_HORARIA]) {
    printf("ID: %s\n", id);
    printf("Nome: %s\n", nome);
    printf("Cargo: %s\n", cargo);
    printf("Disciplina: %s\n", disciplina);
    printf("Carga horário: %s\n", carga_horaria);
    printf("\n");
}

void imprimirRegistroDisciplina(const char semestre[MAX_SEMESTRE],
                                const char professor[MAX_PROFESSOR],
                                const char diadasemana[MAX_DIADASEMANA]
                               ) {
    printf("Semestre: %s\n", semestre);
    printf("Nome: %s\n", professor);
    printf("Dia da semana: %s\n", diadasemana);
    printf("\n");
}

// Utilizando ponteiro para direcionar o arquivo que será criado na hora de
// execução, nessa função ele irá apenas imprimir o registro! Caso exista
void imprimirRegistrosArquivoAluno(const char *nomeArquivo) {
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

        imprimirRegistroAluno(matricula, nome, nota1, nota2, nota3);
    }

    fclose(arquivo);
}

void imprimirRegistrosArquivoFuncionario(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char id[MAX_ID];
    char nome[MAX_NOME];
    char cargo[MAX_CARGO];
    char disciplina[MAX_DISCIPLINA];
    char carga_horaria[MAX_CARGA_HORARIA];

    while (fread(id, sizeof(char), MAX_ID, arquivo) ==
            MAX_ID) {
        fread(nome, sizeof(char), MAX_NOME, arquivo);
        fread(cargo, sizeof(char), MAX_CARGO, arquivo);
        fread(disciplina, sizeof(char), MAX_DISCIPLINA, arquivo);
        fread(carga_horaria, sizeof(char), MAX_CARGA_HORARIA, arquivo);
        imprimirRegistroFuncionario(id, nome, cargo, disciplina, carga_horaria);
    }

    fclose(arquivo);
}

void imprimirRegistrosArquivoDisciplina(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char semestre[MAX_SEMESTRE];
    char professor[MAX_PROFESSOR];
    char diadasemana[MAX_DIADASEMANA];

    while (fread(semestre, sizeof(char), MAX_SEMESTRE, arquivo) ==
            MAX_ID) {
        fread(professor, sizeof(char), MAX_NOME, arquivo);
        fread(diadasemana, sizeof(char), MAX_CARGO, arquivo);
        imprimirRegistroDisciplina(semestre, professor, diadasemana);
    }

    fclose(arquivo);
}

void inserirRegistroAluno(FILE *arquivo) {
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
    printf("Digite a matrícula (até 3 caracteres): ");
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

void inserirRegistroFuncionario(FILE *arquivo) {
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    char id[MAX_ID];
    char nome[MAX_NOME];
    char cargo[MAX_CARGO];
    char disciplina[MAX_DISCIPLINA];
    char carga_horaria[MAX_CARGA_HORARIA];

    // Pede ao usuário para inserir as informações (matrícula, nome, nota1,2,3).
    printf("Digite a matrícula (até 3 caracteres): ");
    scanf("%s", id);

    printf("Digite seu nome (até 30 caracteres): ");
    scanf("%s", nome);

    printf("Digite sua primeira nota (até 5 caracteres): ");
    scanf("%5s", cargo);

    printf("Digite sua segunda nota (até 5 caracteres): ");
    scanf("%5s", disciplina);

    printf("Digite sua terceira nota (até 5 caracteres): ");
    scanf("%5s", carga_horaria);

    fwrite(id, sizeof(char), MAX_ID, arquivo);
    fwrite(nome, sizeof(char), MAX_NOME, arquivo);
    fwrite(cargo, sizeof(char), MAX_CARGO, arquivo);
    fwrite(disciplina, sizeof(char), MAX_DISCIPLINA, arquivo);
    fwrite(carga_horaria, sizeof(char), MAX_CARGA_HORARIA, arquivo);

    printf("Registro inserido com sucesso");

    fclose(arquivo);
}

void inserirRegistroDisciplina(FILE *arquivo) {
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    char semestre[MAX_SEMESTRE];
    char professor[MAX_PROFESSOR];
    char diadasemana[MAX_DIADASEMANA];

    printf("Digite o seu semestre (até 3 caracteres): ");
    scanf("%s", semestre);

    printf("Digite o nome do professor (até 30 caracteres): ");
    scanf("%s", professor);

    printf("Digite o dia da semana (até 5 caracteres): ");
    scanf("%5s", diadasemana);

    fwrite(semestre, sizeof(char), MAX_SEMESTRE, arquivo);
    fwrite(professor, sizeof(char), MAX_PROFESSOR, arquivo);
    fwrite(diadasemana, sizeof(char), MAX_DIADASEMANA, arquivo);

    printf("Registro inserido com sucesso");

    fclose(arquivo);
}

void apagarRegistroAluno(FILE *arquivo, const char *matricula) {
    // Cria um arquivo temporário chamado temp para armazenar as informações,
    // se estiver vazio ele irá mostrar o texto abaixo!
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

void apagarRegistroFuncionario(FILE *arquivo, const char *id) {
    // Cria um arquivo temporário chamado temp para armazenar as informações,
    // se estiver vazio ele irá mostrar o texto abaixo!
    FILE *temp = fopen("temp.txt", "wb");
    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    char regID[MAX_ID];
    char regNome[MAX_NOME];
    char regCargo[MAX_CARGO];
    char regDisciplina[MAX_DISCIPLINA];
    char regCargaHoraria[MAX_CARGA_HORARIA];

    while (fread(regID, sizeof(char), MAX_ID, arquivo) ==
            MAX_ID) {
        fread(regNome, sizeof(char), MAX_NOME, arquivo);
        fread(regCargo, sizeof(char), MAX_CARGO, arquivo);
        fread(regDisciplina, sizeof(char), MAX_DISCIPLINA, arquivo);
        fread(regCargaHoraria, sizeof(char), MAX_CARGA_HORARIA, arquivo);

        if (strcmp(regID, id) != 0) {
            fwrite(regID, sizeof(char), MAX_ID, temp);
            fwrite(regNome, sizeof(char), MAX_NOME, temp);
            fwrite(regCargo, sizeof(char), MAX_CARGO, temp);
            fwrite(regDisciplina, sizeof(char), MAX_DISCIPLINA, temp);
            fwrite(regCargaHoraria, sizeof(char), MAX_CARGA_HORARIA, temp);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("dados.txt");
    rename("temp.txt", "dados.txt");

    printf("Registro apagado com sucesso!\n");
}

void apagarRegistroDisciplina(FILE *arquivo, const char *semestre) {
    // Cria um arquivo temporário chamado temp para armazenar as informações,
    // se estiver vazio ele irá mostrar o texto abaixo!
    FILE *temp = fopen("temp.txt", "wb");
    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    char regSemestre[MAX_SEMESTRE];
    char regProfessor[MAX_PROFESSOR];
    char regDiaDaSemana[MAX_DIADASEMANA];

    while (fread(regSemestre, sizeof(char), MAX_SEMESTRE, arquivo) ==
            MAX_SEMESTRE) {
        fread(regProfessor, sizeof(char), MAX_PROFESSOR, arquivo);
        fread(regDiaDaSemana, sizeof(char), MAX_DIADASEMANA, arquivo);

        if (strcmp(regSemestre, semestre) != 0) {
            fwrite(regSemestre, sizeof(char), MAX_SEMESTRE, temp);
            fwrite(regProfessor, sizeof(char), MAX_PROFESSOR, temp);
            fwrite(regDiaDaSemana, sizeof(char), MAX_DIADASEMANA, temp);
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
    char id[MAX_ID];
    char matricula[MAX_MATRICULA];

    printf("Selecione uma opção:\n");
    printf("1 - Imprimir registros\n");  // Perguntar se é para imprimir o registro do funcionário ou aluno.
    printf("2 - Inserir registro\n"); // Perguntar se o usuário é um aluno ou professor, caso seja funcionário peça seu ID e cargo, caso aluno peça sua matrícula.
    printf("3 - Apagar registro\n");
    printf("4 - Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        imprimirRegistrosArquivoAluno("dados.txt");
    } else if (opcao == 2) {
        inserirRegistroAluno(arquivo);
    } else if (opcao == 3) {
        printf("Digite a matrícula do registro a ser apagado: ");
        scanf("%5s", matricula);
        apagarRegistroAluno(arquivo, matricula);
    } else {
        printf("Opção inválida, encerrando processo...\n");
    }

    fclose(arquivo);
    return 0;
}
