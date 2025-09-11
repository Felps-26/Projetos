#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_MAX 50

typedef struct {
    char nome[NAME_MAX];
    char senha[20];
    double saldo;
} Usuario;

int carregarUsuarios(Usuario usuarios[], int *total) {
    FILE *f = fopen("usuarios.bin", "rb");
    if (!f) return 0;
    *total = fread(usuarios, sizeof(Usuario), MAX_USERS, f);
    fclose(f);
    return 1;
}

int salvarUsuarios(Usuario usuarios[], int total) {
    FILE *f = fopen("usuarios.bin", "wb");
    if (!f) return 0;
    fwrite(usuarios, sizeof(Usuario), total, f);
    fclose(f);
    return 1;
}

int autenticar(Usuario usuarios[], int total, char nome[], char senha[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(usuarios[i].nome, nome) == 0 && strcmp(usuarios[i].senha, senha) == 0)
            return i;
    }
    return -1;
}

int cadastrarUsuario(Usuario usuarios[], int *total) {
    if (*total >= MAX_USERS) return 0;
    printf("Novo usuario - Nome: ");
    scanf("%s", usuarios[*total].nome);
    printf("Senha: ");
    scanf("%s", usuarios[*total].senha);
    usuarios[*total].saldo = 0.0;
    (*total)++;
    salvarUsuarios(usuarios, *total);
    printf("Usuario cadastrado!\n");
    return 1;
}

void menuConta(Usuario *usuario) {
    int op;
    double valor;
    do {
        printf("\n*** Menu Caixa Eletronico ***\n");
        printf("[1] Consultar saldo\n");
        printf("[2] Depositar\n");
        printf("[3] Sacar\n");
        printf("[0] Sair\nEscolha: ");
        scanf("%d", &op);
        switch(op) {
            case 1:
                printf("Saldo: R$ %.2lf\n", usuario->saldo);
                break;
            case 2:
                printf("Valor do deposito: ");
                scanf("%lf", &valor);
                if (valor > 0) {
                    usuario->saldo += valor;
                    printf("Deposito realizado!\n");
                } else printf("Valor invalido!\n");
                break;
            case 3:
                printf("Valor do saque: ");
                scanf("%lf", &valor);
                if (valor > 0 && valor <= usuario->saldo) {
                    usuario->saldo -= valor;
                    printf("Saque realizado!\n");
                } else printf("Saldo insuficiente!\n");
                break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while(op != 0);
}

int main() {
    Usuario usuarios[MAX_USERS];
    int total = 0;
    carregarUsuarios(usuarios, &total);

    int op, idx;
    char nome[NAME_MAX], senha[20];

    while(1) {
        printf("\n---- Bem-vindo ao Caixa Eletronico ----\n");
        printf("[1] Login\n[2] Cadastrar novo usuario\n[0] Sair\nEscolha: ");
        scanf("%d", &op);

        if (op == 1) {
            printf("Nome: ");
            scanf("%s", nome);
            printf("Senha: ");
            scanf("%s", senha);
            idx = autenticar(usuarios, total, nome, senha);
            if (idx >= 0) {
                printf("Login bem-sucedido, ola %s!\n", usuarios[idx].nome);
                menuConta(&usuarios[idx]);
                salvarUsuarios(usuarios, total);
            } else {
                printf("Usuario ou senha incorretos.\n");
            }
        } else if (op == 2) {
            cadastrarUsuario(usuarios, &total);
        } else if (op == 0) {
            salvarUsuarios(usuarios, total);
            printf("Sistema encerrado!\n");
            break;
        } else {
            printf("Opcao invalida!\n");
        }
    }
    return 0;
}
