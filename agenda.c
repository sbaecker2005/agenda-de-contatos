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
