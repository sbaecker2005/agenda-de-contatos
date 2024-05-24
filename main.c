#include <stdio.h>
#include "agenda.h"

int main() {
    Agenda agenda;
    agenda.quantidadePessoais = 0;
    agenda.quantidadeTrabalho = 0;

    int opcao, tipoContato;
    char telefone[MAX_TELEFONE];

    do {
        printf("\n===== Menu =====\n");
        printf("1. Adicionar Contato Pessoal\n");
        printf("2. Adicionar Contato de Trabalho\n");
        printf("3. Listar Contatos Pessoais\n");
        printf("4. Listar Contatos de Trabalho\n");
        printf("5. Deletar Contato Pessoal\n");
        printf("6. Deletar Contato de Trabalho\n");
        printf("7. Alterar Contato Pessoal\n");
        printf("8. Alterar Contato de Trabalho\n");
        printf("9. Salvar Agenda\n");
        printf("10. Carregar Agenda\n");
        printf("11. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                tipoContato = 1;
                adicionarContato(&agenda, tipoContato);
                break;
            case 2:
                tipoContato = 2;
                adicionarContato(&agenda, tipoContato);
                break;
            case 3:
                tipoContato = 1;
                listarContatos(&agenda, tipoContato);
                break;
            case 4:
                tipoContato = 2;
                listarContatos(&agenda, tipoContato);
                break;
            case 5:
                tipoContato = 1;
                printf("Digite o telefone do contato pessoal a ser deletado: ");
                scanf("%s", telefone);
                deletarContato(&agenda, telefone, tipoContato);
                break;
            case 6:
                tipoContato = 2;
                printf("Digite o telefone do contato de trabalho a ser deletado: ");
                scanf("%s", telefone);
                deletarContato(&agenda, telefone, tipoContato);
                break;
            case 7:
                tipoContato = 1;
                printf("Digite o telefone do contato pessoal a ser alterado: ");
                scanf("%s", telefone);
                alterarContato(&agenda, telefone, tipoContato);
                break;
            case 8:
                tipoContato = 2;
                printf("Digite o telefone do contato de trabalho a ser alterado: ");
                scanf("%s", telefone);
                alterarContato(&agenda, telefone, tipoContato);
                break;
            case 9:
                salvarAgenda(&agenda);
                break;
            case 10:
                carregarAgenda(&agenda);
                break;
            case 11:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Por favor, tente novamente.\n");
        }
    } while (opcao != 11);

    return 0;
}
