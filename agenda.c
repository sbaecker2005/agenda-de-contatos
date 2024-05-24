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
