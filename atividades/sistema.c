#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alunos
#define MAX_MATRICULA 6
#define MAX_NOME 31
#define MAX_NOTA 6

// Funcionarios
#define MAX_ID 6
#define MAX_NOME_FUNCIONARIO 31
#define MAX_CARGO 21
#define MAX_DISCIPLINA 31
#define MAX_CARGA_HORARIA 21

// Disciplina
#define MAX_SEMESTRE 6
#define MAX_PROFESSOR 31  // Pensar sobre essa variável
#define MAX_DIADASEMANA 31

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
                                 const char nome[MAX_NOME_FUNCIONARIO], const char cargo[MAX_CARGO],
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
void imprimirRegistrosArquivoAluno(const char *nomeArquivoAluno) {
    FILE *arquivoAluno = fopen(nomeArquivoAluno, "rb");
    if (arquivoAluno == NULL) {
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
    while (fread(matricula, sizeof(char), MAX_MATRICULA, arquivoAluno) ==
            MAX_MATRICULA) {
        fread(nome, sizeof(char), MAX_NOME, arquivoAluno);
        fread(nota1, sizeof(char), MAX_NOTA, arquivoAluno);
        fread(nota2, sizeof(char), MAX_NOTA, arquivoAluno);
        fread(nota3, sizeof(char), MAX_NOTA, arquivoAluno);

        imprimirRegistroAluno(matricula, nome, nota1, nota2, nota3);
    }

    fclose(arquivoAluno);
}

void imprimirRegistrosArquivoFuncionario(const char *nomeArquivoFuncionario) {
    FILE *arquivoFuncionario = fopen(nomeArquivoFuncionario, "rb");
    if (arquivoFuncionario == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char id[MAX_ID];
    char nome[MAX_NOME_FUNCIONARIO];
    char cargo[MAX_CARGO];
    char disciplina[MAX_DISCIPLINA];
    char carga_horaria[MAX_CARGA_HORARIA];

    while (fread(id, sizeof(char), MAX_ID, arquivoFuncionario) ==
            MAX_ID) {
        fread(nome, sizeof(char), MAX_NOME_FUNCIONARIO, arquivoFuncionario);
        fread(cargo, sizeof(char), MAX_CARGO, arquivoFuncionario);
        fread(disciplina, sizeof(char), MAX_DISCIPLINA, arquivoFuncionario);
        fread(carga_horaria, sizeof(char), MAX_CARGA_HORARIA, arquivoFuncionario);
        imprimirRegistroFuncionario(id, nome, cargo, disciplina, carga_horaria);
    }

    fclose(arquivoFuncionario);
}

void imprimirRegistrosArquivoDisciplina(const char *nomeArquivoDisciplina) {
    FILE *arquivoDisciplina = fopen(nomeArquivoDisciplina, "rb");
    if (arquivoDisciplina == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char semestre[MAX_SEMESTRE];
    char professor[MAX_PROFESSOR];
    char diadasemana[MAX_DIADASEMANA];

    while (fread(semestre, sizeof(char), MAX_SEMESTRE, arquivoDisciplina) ==
            MAX_SEMESTRE) {
        fread(professor, sizeof(char), MAX_PROFESSOR, arquivoDisciplina);
        fread(diadasemana, sizeof(char), MAX_DIADASEMANA, arquivoDisciplina);
        imprimirRegistroDisciplina(semestre, professor, diadasemana);
    }

    fclose(arquivoDisciplina);
}

void inserirRegistroAluno(FILE *arquivoAluno) {
    if (arquivoAluno == NULL) {
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
    fwrite(matricula, sizeof(char), MAX_MATRICULA, arquivoAluno);
    fwrite(nome, sizeof(char), MAX_NOME, arquivoAluno);
    fwrite(nota1, sizeof(char), MAX_NOTA, arquivoAluno);
    fwrite(nota2, sizeof(char), MAX_NOTA, arquivoAluno);
    fwrite(nota3, sizeof(char), MAX_NOTA, arquivoAluno);

    printf("Registro inserido com sucesso");

    fclose(arquivoAluno);
}

void inserirRegistroFuncionario(FILE *arquivoFuncionario) {
    if (arquivoFuncionario == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    char id[MAX_ID];
    char nome[MAX_NOME_FUNCIONARIO];
    char cargo[MAX_CARGO];
    char disciplina[MAX_DISCIPLINA];
    char carga_horaria[MAX_CARGA_HORARIA];

    // Pede ao usuário para inserir as informações (matrícula, nome, nota1,2,3).
    printf("Digite seu ID (até 3 caracteres): ");
    scanf("%s", id);

    printf("Digite seu nome (até 30 caracteres): ");
    scanf("%s", nome);

    printf("Digite seu cargo (até 21 caracteres): ");
    scanf("%s", cargo);

    printf("Digite sua disciplina (até 21 caracteres): ");
    scanf("%s", disciplina);

    printf("Digite sua carga horária (até 5 caracteres): ");
    scanf("%s", carga_horaria);

    fwrite(id, sizeof(char), MAX_ID, arquivoFuncionario);
    fwrite(nome, sizeof(char), MAX_NOME_FUNCIONARIO, arquivoFuncionario);
    fwrite(cargo, sizeof(char), MAX_CARGO, arquivoFuncionario);
    fwrite(disciplina, sizeof(char), MAX_DISCIPLINA, arquivoFuncionario);
    fwrite(carga_horaria, sizeof(char), MAX_CARGA_HORARIA, arquivoFuncionario);

    printf("Registro inserido com sucesso");

    fclose(arquivoFuncionario);
}

void inserirRegistroDisciplina(FILE *arquivoDisciplina) {
    if (arquivoDisciplina == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    char semestre[MAX_SEMESTRE];
    char professor[MAX_PROFESSOR];
    char diadasemana[MAX_DIADASEMANA];

    printf("Digite o semestre (até 3 caracteres): ");
    scanf("%s", semestre);

    printf("Digite o nome do professor (até 30 caracteres): ");
    scanf("%s", professor);

    printf("Digite os dias da semana (até 31 caracteres): ");
    scanf("%s", diadasemana);

    fwrite(semestre, sizeof(char), MAX_SEMESTRE, arquivoDisciplina);
    fwrite(professor, sizeof(char), MAX_PROFESSOR, arquivoDisciplina);
    fwrite(diadasemana, sizeof(char), MAX_DIADASEMANA, arquivoDisciplina);

    printf("Registro inserido com sucesso");

    fclose(arquivoDisciplina);
}

void apagarRegistroAluno(FILE *arquivoAluno, const char *matricula) {
    // Cria um arquivo temporário chamado temp para armazenar as informações,
    // se estiver vazio ele irá mostrar o texto abaixo!
    FILE *temp = fopen("temp.txt", "wb");
    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivoAluno);
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
    while (fread(regMatricula, sizeof(char), MAX_MATRICULA, arquivoAluno) ==
            MAX_MATRICULA) {
        fread(regNome, sizeof(char), MAX_NOME, arquivoAluno);
        fread(regNota1, sizeof(char), MAX_NOTA, arquivoAluno);
        fread(regNota2, sizeof(char), MAX_NOTA, arquivoAluno);
        fread(regNota3, sizeof(char), MAX_NOTA, arquivoAluno);

        if (strcmp(regMatricula, matricula) != 0) {
            fwrite(regMatricula, sizeof(char), MAX_MATRICULA, temp);
            fwrite(regNome, sizeof(char), MAX_NOME, temp);
            fwrite(regNota1, sizeof(char), MAX_NOTA, temp);
            fwrite(regNota2, sizeof(char), MAX_NOTA, temp);
            fwrite(regNota3, sizeof(char), MAX_NOTA, temp);
        }
    }

    fclose(arquivoAluno);
    fclose(temp);

    remove("dadosAluno.txt");
    rename("temp.txt", "dadosAluno.txt");

    printf("Registro apagado com sucesso!\n");
}

void apagarRegistroFuncionario(FILE *arquivoFuncionario, const char *id) {
    // Cria um arquivo temporário chamado temp para armazenar as informações,
    // se estiver vazio ele irá mostrar o texto abaixo!
    FILE *temp = fopen("temp.txt", "wb");
    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivoFuncionario);
        return;
    }

    char regID[MAX_ID];
    char regNome[MAX_NOME_FUNCIONARIO];
    char regCargo[MAX_CARGO];
    char regDisciplina[MAX_DISCIPLINA];
    char regCargaHoraria[MAX_CARGA_HORARIA];

    while (fread(regID, sizeof(char), MAX_ID, arquivoFuncionario) ==
            MAX_ID) {
        fread(regNome, sizeof(char), MAX_NOME_FUNCIONARIO, arquivoFuncionario);
        fread(regCargo, sizeof(char), MAX_CARGO, arquivoFuncionario);
        fread(regDisciplina, sizeof(char), MAX_DISCIPLINA, arquivoFuncionario);
        fread(regCargaHoraria, sizeof(char), MAX_CARGA_HORARIA, arquivoFuncionario);

        if (strcmp(regID, id) != 0) {
            fwrite(regID, sizeof(char), MAX_ID, temp);
            fwrite(regNome, sizeof(char), MAX_NOME_FUNCIONARIO, temp);
            fwrite(regCargo, sizeof(char), MAX_CARGO, temp);
            fwrite(regDisciplina, sizeof(char), MAX_DISCIPLINA, temp);
            fwrite(regCargaHoraria, sizeof(char), MAX_CARGA_HORARIA, temp);
        }
    }

    fclose(arquivoFuncionario);
    fclose(temp);

    remove("dadosFuncionario.txt");
    rename("temp.txt", "dadosFuncionario.txt");

    printf("Registro apagado com sucesso!\n");
}

void apagarRegistroDisciplina(FILE *arquivoDisciplina, const char *semestre) {
    // Cria um arquivo temporário chamado temp para armazenar as informações,
    // se estiver vazio ele irá mostrar o texto abaixo!
    FILE *temp = fopen("temp.txt", "wb");
    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivoDisciplina);
        return;
    }

    char regSemestre[MAX_SEMESTRE];
    char regProfessor[MAX_PROFESSOR];
    char regDiaDaSemana[MAX_DIADASEMANA];

    while (fread(regSemestre, sizeof(char), MAX_SEMESTRE, arquivoDisciplina) ==
            MAX_SEMESTRE) {
        fread(regProfessor, sizeof(char), MAX_PROFESSOR, arquivoDisciplina);
        fread(regDiaDaSemana, sizeof(char), MAX_DIADASEMANA, arquivoDisciplina);

        if (strcmp(regSemestre, semestre) != 0) {
            fwrite(regSemestre, sizeof(char), MAX_SEMESTRE, temp);
            fwrite(regProfessor, sizeof(char), MAX_PROFESSOR, temp);
            fwrite(regDiaDaSemana, sizeof(char), MAX_DIADASEMANA, temp);
        }
    }

    fclose(arquivoDisciplina);
    fclose(temp);

    remove("dadosDisciplina.txt");
    rename("temp.txt", "dadosDisciplina.txt");

    printf("Registro apagado com sucesso!\n");
}

int main() {
    FILE *arquivoAluno = fopen("dadosAluno.txt", "ab+");
    if (arquivoAluno == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    FILE *arquivoFuncionario = fopen("dadosFuncionario.txt", "ab+");
    if (arquivoFuncionario == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    FILE *arquivoDisciplina = fopen("dadosDisciplina.txt", "ab+");
    if (arquivoDisciplina == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    int opcao;
    char id[MAX_ID];
    char matricula[MAX_MATRICULA];
    char semestre[MAX_SEMESTRE];

    // Escolha a opção
    printf("Selecione uma opção:\n");
    // Imprimir
    printf("1 - Imprimir registros do aluno\n");
    printf("2 - Imprimir registros do funcionário\n");
    printf("3 - Imprimir registros da disciplina\n");
    // Inserir
    printf("4 - Inserir registro do aluno\n");
    printf("5 - Inserir registro do funcionário\n");
    printf("6 - Inserir registro da disciplina\n");
    // Apagar
    printf("7 - Apagar registro do aluno\n");
    printf("8 - Apagar registro do funcionário\n");
    printf("9 - Apagar registro da disciplina\n");
    // Sair
    printf("10 - Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    // Imprimir
    if (opcao == 1) {
        imprimirRegistrosArquivoAluno("dadosAluno.txt");
    } else if (opcao == 2) {
        imprimirRegistrosArquivoFuncionario("dadosFuncionario.txt");
    } else if (opcao == 3) {
        imprimirRegistrosArquivoDisciplina("dadosDisciplina.txt");
    }

    // Inserir
    else if (opcao == 4) {
        inserirRegistroAluno(arquivoAluno);
    }
    else if (opcao == 5) {
        inserirRegistroFuncionario(arquivoFuncionario);
    }
    else if (opcao == 6) {
        inserirRegistroDisciplina(arquivoDisciplina);
    }

    // Apagar
    else if (opcao == 7) {
        printf("Digite a matrícula do registro a ser apagado: ");
        scanf("%5s", matricula);
        apagarRegistroAluno(arquivoAluno, matricula);
    }
    else if (opcao == 8) {
        printf("Digite o ID a ser apagado: ");
        scanf("%5s", id);
        apagarRegistroFuncionario(arquivoFuncionario, id);
    }
    else if (opcao == 9) {
        printf("Digite o semestre a ser apagado: ");
        scanf("%5s", semestre);
        apagarRegistroDisciplina(arquivoDisciplina, semestre);
    } else {
        printf("Opção inválida, encerrando processo...\n");
    }

    fclose(arquivoAluno);
    fclose(arquivoFuncionario);
    fclose(arquivoDisciplina);
    return 0;
}
