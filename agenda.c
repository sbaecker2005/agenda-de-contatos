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
