#ifndef CLIENTE_BANCO_H
#define CLIENTE_BANCO_H

struct Cliente {
    char nome[100];
    char cpf[12];
    int tipo;
    double saldo;
    char senha[20];
};
struct Extrato {
    char cpf[12];
    char data[20];
    double valor;
    double tarifa;
    double saldo;
};
