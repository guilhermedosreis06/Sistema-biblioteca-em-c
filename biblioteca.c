/*
 Sistema de Gerenciamento de Biblioteca
 Linguagem: C

 Funcionalidades:
 - Cadastro de livros (CRUD)
 - Consulta e atualização
 - Listagem de livros
 - Relatórios

 Projeto acadêmico para prática de programação estruturada
*/

#include <stdio.h>

struct livro {
    char titulo[200];
    char autor[100];
    int ano;
    int id;
};

struct livro livros[100];
int qntd = 0;

void menugerenciar();
void menurelatorios();
void cadastrar();
void consultar();
void atualizar();
void listarqntd();
void listarlivros();

int main() {
    int opc;
    int menu = 1;

    printf("=========================================\n");
    printf("  Sistema de Gerenciamento de Biblioteca\n");
    printf("=========================================\n");

    while (menu == 1) {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Gerenciar Livros\n");
        printf("2. Relatórios e Estatísticas\n");
        printf("0. Sair\n");
        printf("------------------------\n");
        printf("Digite sua escolha: ");
        scanf("%d", &opc);
        getchar();

        switch (opc) {
            case 1:
                menugerenciar();
                break;
            case 2:
                menurelatorios();
                break;
            case 0:
                printf("Você saiu.\n");
                menu = 0;
                break;
            default:
                printf("\nOpção inválida.\n");
                break;
        }
    }
    
    return 0;
}

void menugerenciar() {
    int opc = 9;
    int menu = 1;

    while (menu == 1) {
        printf("\n--- GERENCIAR LIVRO ---\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Consultar Livros\n");
        printf("3. Atualizar Livro\n");
        printf("0. Voltar\n");
        printf("------------------------\n");
        printf("Digite sua escolha: ");
        scanf("%d", &opc);
        getchar();

        switch (opc) {
            case 1:
                cadastrar();
                break;
            case 2:
                consultar();
                break;
            case 3:
                atualizar();
                break;
            case 0:
                printf("\nVocê voltou.\n");
                return;
                break;
            default:
                printf("\nOpção inválida.\n");
                break;
        }
    }
}

void menurelatorios() {
    int opc = 9;
    int menu = 1;

    while (menu == 1) {
        printf("\n--- RELATÓRIOS E ESTATÍSTICAS ---\n");
        printf("1. Número total de livros\n");
        printf("2. Listar todos os livros\n");
        printf("0. Voltar\n");
        printf("------------------------\n");
        printf("Digite sua escolha: ");
        scanf("%d", &opc);
        getchar();

        switch (opc) {
            case 1:
                listarqntd();
                break;
            case 2:
                listarlivros();
                break;
            case 0:
                printf("\nVocê voltou.\n");
                return;
                break;
            default:
                printf("\nOpção inválida.\n");
                break;
        }
    }
}

void cadastrar() {
    if (qntd < 100) {
        printf("\n--- CADASTRAR LIVRO ---\n");
        printf("Digite o titulo: ");
        fgets(livros[qntd].titulo, 200, stdin);

        printf("Digite o autor: ");
        fgets(livros[qntd].autor, 100, stdin);

        printf("Digite o ano de publicacao: ");
        scanf("%d", &livros[qntd].ano);
        getchar();

        livros[qntd].id = qntd + 1;

        printf("\nLivro %d cadastrado com sucesso.\n", livros[qntd].id);
        qntd++;
    } else {
        printf("\nLimite máximo de livros atingido.\n");
    }
}

void consultar() {
    int id;

    if (qntd > 0) {
        printf("\n--- CONSULTAR LIVROS ---\n");
        printf("Digite o ID do livro: ");
        scanf("%d", &id);
        getchar();

        if (id > 0 && id <= qntd) {
            printf("\nLivro %d\n", id);
            printf("Título: %s", livros[id - 1].titulo);
            printf("Autor: %s", livros[id - 1].autor);
            printf("Ano: %d\n", livros[id - 1].ano);
        } else {
            printf("\nID inválido.\n");
        }

    } else {
        printf("\nNenhum livro cadastrado.\n");
    }
}

void atualizar() {
    int id;

    if (qntd > 0) {
        printf("\n--- ATUALIZAR LIVRO ---\n");
        printf("Digite o ID do livro: ");
        scanf("%d", &id);
        getchar();

        if (id > 0 && id <= qntd) {
            printf("Digite o titulo: ");
            fgets(livros[id - 1].titulo, 200, stdin);

            printf("Digite o autor: ");
            fgets(livros[id - 1].autor, 100, stdin);

            printf("Digite o ano de publicacao: ");
            scanf("%d", &livros[id - 1].ano);
            getchar();

            printf("\nLivro %d atualizado com sucesso!\n", id);
        } else {
            printf("\nID inválido.\n");
        }

    } else {
        printf("\nNenhum livro cadastrado.\n");
    }
}

void listarqntd() {
    if (qntd == 0) {
        printf("\nNenhum livro cadastrado.\n");
    } else if (qntd == 1) {
        printf("\nApenas %d livro foi cadastrado no total.\n", qntd);
    } else {
        printf("\nLivros cadastrados no total: %d\n", qntd);
    }
}

void listarlivros() {
    if (qntd == 0) {
        printf("\nNenhum livro cadastrado.\n");
    } else {
        printf("\n--- LISTA DE LIVROS ---\n");
        for (int i = 0; i < qntd; i++) {
            printf("\nID: %d", livros[i].id);
            printf("\nTítulo: %s", livros[i].titulo);
            printf("Autor: %s", livros[i].autor);
            printf("Ano: %d\n", livros[i].ano);
        }
    }
}
