#ifndef AGENDA_H
#define AGENDA_H

#define MAX_CONTATOS 255
#define MAX_NOME 50
#define MAX_TELEFONE 15
#define MAX_EMAIL 50

typedef struct {
    char nome[MAX_NOME];
    char telefone[MAX_TELEFONE];
    char email[MAX_EMAIL];
} Contato;

typedef struct {
    Contato contatosPessoais[MAX_CONTATOS];
    Contato contatosTrabalho[MAX_CONTATOS];
    int quantidadePessoais;
    int quantidadeTrabalho;
} Agenda;
