include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

void adicionarContato(Agenda *agenda, int tipoContato) {
    Contato *contatoArray;
    int *quantidade;

    if (tipoContato == 1) {
        contatoArray = agenda->contatosPessoais;
        quantidade = &agenda->quantidadePessoais;
    } else {
        contatoArray = agenda->contatosTrabalho;
        quantidade = &agenda->quantidadeTrabalho;
    }

    if (*quantidade >= MAX_CONTATOS) {
        printf("A lista de contatos esta cheia!\n");
        return;
    }

    Contato novoContato;
    printf("\nAdicionando Contato:\n");
    printf("Nome: ");
    scanf("%s", novoContato.nome);
    printf("Telefone: ");
    scanf("%s", novoContato.telefone);
    printf("Email: ");
    scanf("%s", novoContato.email);

    if (strstr(novoContato.email, "@") == NULL) {
        printf("Email invalido! O email deve conter '@'.\n");
        return;
    }

    for (int i = 0; i < agenda->quantidadePessoais; i++) {
        if (strcmp(agenda->contatosPessoais[i].telefone, novoContato.telefone) == 0) {
            printf("Ja existe um contato com esse telefone!\n");
            return;
        }
    }

    for (int i = 0; i < agenda->quantidadeTrabalho; i++) {
        if (strcmp(agenda->contatosTrabalho[i].telefone, novoContato.telefone) == 0) {
            printf("Ja existe um contato com esse telefone!\n");
            return;
        }
    }

    contatoArray[*quantidade] = novoContato;
    (*quantidade)++;
    printf("Contato adicionado com sucesso!\n");
}
void listarContatos(const Agenda *agenda, int tipoContato) {
    const Contato *contatoArray;
    int quantidade;

    if (tipoContato == 1) {
        contatoArray = agenda->contatosPessoais;
        quantidade = agenda->quantidadePessoais;
    } else {
        contatoArray = agenda->contatosTrabalho;
        quantidade = agenda->quantidadeTrabalho;
    }

    printf("\nLista de Contatos:\n");
    if (quantidade == 0) {
        printf("Nenhum contato na lista.\n");
    } else {
        for (int i = 0; i < quantidade; i++) {
            printf("%s - %s - %s\n", contatoArray[i].nome, contatoArray[i].telefone, contatoArray[i].email);
        }
    }
}
void deletarContato(Agenda *agenda, const char *telefone, int tipoContato) {
    Contato *contatoArray;
    int *quantidade;

    if (tipoContato == 1) {
        contatoArray = agenda->contatosPessoais;
        quantidade = &agenda->quantidadePessoais;
    } else {
        contatoArray = agenda->contatosTrabalho;
        quantidade = &agenda->quantidadeTrabalho;
    }

    int i, encontrado = 0;
    for (i = 0; i < *quantidade; i++) {
        if (strcmp(contatoArray[i].telefone, telefone) == 0) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        for (int j = i; j < *quantidade - 1; j++) {
            strcpy(contatoArray[j].nome, contatoArray[j + 1].nome);
            strcpy(contatoArray[j].telefone, contatoArray[j + 1].telefone);
            strcpy(contatoArray[j].email, contatoArray[j + 1].email);
        }
        (*quantidade)--;
        printf("Contato deletado com sucesso!\n");
    } else {
        printf("Contato nao encontrado.\n");
    }
}
void alterarContato(Agenda *agenda, const char *telefone, int tipoContato) {
    Contato *contatoArray;
    int *quantidade;

    if (tipoContato == 1) {
        contatoArray = agenda->contatosPessoais;
        quantidade = &agenda->quantidadePessoais;
    } else {
        contatoArray = agenda->contatosTrabalho;
        quantidade = &agenda->quantidadeTrabalho;
    }

    int i, encontrado = 0;
    for (i = 0; i < *quantidade; i++) {
        if (strcmp(contatoArray[i].telefone, telefone) == 0) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        Contato novoContato;
        printf("\nAlterando Contato:\n");
        printf("Novo Nome: ");
        scanf("%s", novoContato.nome);
        printf("Novo Telefone: ");
        scanf("%s", novoContato.telefone);
        printf("Novo Email: ");
        scanf("%s", novoContato.email);

        if (strstr(novoContato.email, "@") == NULL) {
            printf("Email invalido! O email deve conter '@'.\n");
            return;
        }

        for (int j = 0; j < agenda->quantidadePessoais; j++) {
            if (strcmp(agenda->contatosPessoais[j].telefone, novoContato.telefone) == 0 && j != i) {
                printf("Ja existe um contato com esse telefone!\n");
                return;
            }
        }

        for (int j = 0; j < agenda->quantidadeTrabalho; j++) {
            if (strcmp(agenda->contatosTrabalho[j].telefone, novoContato.telefone) == 0 && j != i) {
                printf("Ja existe um contato com esse telefone!\n");
                return;
            }
        }

        contatoArray[i] = novoContato;
        printf("Contato alterado com sucesso!\n");
    } else {
        printf("Contato nao encontrado.\n");
    }
}
void salvarAgenda(const Agenda *agenda) {
    FILE *arquivo = fopen("agenda.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fwrite(agenda, sizeof(Agenda), 1, arquivo);
    fclose(arquivo);
    printf("Agenda salva com sucesso!\n");
}
