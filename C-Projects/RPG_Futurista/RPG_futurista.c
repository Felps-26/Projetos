#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[50];
    int hp, max_hp;
    int ataque;
    int defesa;
    int nivel;
    int xp;
} Jogador;

typedef struct {
    char nome[30];
    int hp;
    int ataque;
    int defesa;
    int recompensa_xp;
    int nivel;
    int chance_fuga; // porcentagem de chance de fuga
} Inimigo;

void mostrar_status(Jogador* p) {
    printf("-> %s | HP: %d/%d | Nivel: %d | XP: %d\n", p->nome, p->hp, p->max_hp, p->nivel, p->xp);
}

int tentar_fugir(int chance) {
    int rolagem = rand() % 100;
    if (rolagem < chance) {
        printf("Voce conseguiu fugir!\n");
        return 1;
    } else {
        printf("Fuga falhou!\n");
        return 0;
    }
}

void menu_ataque() {
    printf("\n--- Menu de Batalha ---\n");
    printf("[1] Atacar\n");
    printf("[2] Fugir\n");
    printf("Escolha: ");
}

void batalha(Jogador* p, Inimigo* inimigo) {
    printf("=== Batalha contra %s (Nivel %d) ===\n", inimigo->nome, inimigo->nivel);
    while (p->hp > 0 && inimigo->hp > 0) {
        int op;
        menu_ataque();
        if (scanf("%d", &op) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n'); // Limpa buffer

        if (op == 1) {
            int dado = rand()%6 + 1;
            int dano = (p->ataque + dado) - inimigo->defesa;
            dano = (dano < 1) ? 1 : dano;
            inimigo->hp -= dano;
            printf("%s ataca e causa %d de dano! (Vida do inimigo: %d)\n", p->nome, dano, (inimigo->hp > 0 ? inimigo->hp : 0));
        } else if (op == 2) {
            if (tentar_fugir(inimigo->chance_fuga)) {
                return;
            }
        } else {
            printf("Opcao invalida!\n");
            continue;
        }

        if (inimigo->hp <= 0) break;

        int dado = rand()%6 + 1;
        int dano = (inimigo->ataque + dado) - p->defesa;
        dano = (dano < 1) ? 1 : dano;
        p->hp -= dano;
        printf("%s ataca e causa %d de dano! (Sua vida: %d)\n", inimigo->nome, dano, (p->hp > 0 ? p->hp : 0));
    }
    if (p->hp > 0 && inimigo->hp <= 0) {
        printf("Voce derrotou %s! Ganhou %d XP\n", inimigo->nome, inimigo->recompensa_xp);
        p->xp += inimigo->recompensa_xp;
    } else if (p->hp <= 0) {
        printf("Voce foi derrotado...\n");
    }
}

void subir_de_nivel(Jogador* p) {
    while (p->xp >= (p->nivel * 20)) {
        p->nivel++;
        p->max_hp += 10;
        p->ataque += 2;
        p->defesa += 1;
        p->hp = p->max_hp;
        printf("Parabens! Voce subiu para o nivel %d!\n", p->nivel);
    }
}

void gerar_inimigo(Inimigo* inimigo, int nivel_jogador) {
    int tipo = rand()%3;
    if (tipo == 0) {
        strcpy(inimigo->nome, "Dron de Ataque");
        inimigo->nivel = nivel_jogador;
        inimigo->hp = 12 + nivel_jogador * 3;
        inimigo->ataque = 5 + nivel_jogador;
        inimigo->defesa = 2 + nivel_jogador/2;
        inimigo->recompensa_xp = 8 + nivel_jogador * 2;
        inimigo->chance_fuga = 70; // facil de fugir
    } else if (tipo == 1) {
        strcpy(inimigo->nome, "Android Rogue");
        inimigo->nivel = nivel_jogador + 1;
        inimigo->hp = 20 + nivel_jogador * 4;
        inimigo->ataque = 7 + nivel_jogador;
        inimigo->defesa = 3 + nivel_jogador/2;
        inimigo->recompensa_xp = 12 + nivel_jogador * 3;
        inimigo->chance_fuga = 50; // medio de fugir
    } else {
        strcpy(inimigo->nome, "Mecha Assassino");
        inimigo->nivel = nivel_jogador + 2;
        inimigo->hp = 30 + nivel_jogador * 5;
        inimigo->ataque = 10 + nivel_jogador * 2;
        inimigo->defesa = 5 + nivel_jogador;
        inimigo->recompensa_xp = 20 + nivel_jogador * 4;
        inimigo->chance_fuga = 30; // dificil de fugir
    }
}

void explorar(Jogador* p) {
    int evento = rand()%3;
    if (evento == 0) {
        Inimigo inimigo;
        gerar_inimigo(&inimigo, p->nivel);
        batalha(p, &inimigo);
    } else if (evento == 1) {
        int cura = rand()%10 + 5;
        p->hp += cura;
        if (p->hp > p->max_hp) p->hp = p->max_hp;
        printf("Voce encontrou um kit medico futurista e recuperou %d de HP!\n", cura);
    } else {
        printf("Voce encontrou um upgrade de ataque (+2 ataque)!\n");
        p->ataque += 2;
    }
    subir_de_nivel(p);
}

int main() {
    srand((unsigned)time(NULL));
    Jogador p = {"NeoRunner", 30, 30, 8, 3, 1, 0};
    int op;
    printf("=== RPG FUTURISTA TERMINAL ===\nNome do personagem (ou ENTER para NeoRunner): ");
    char nome[50];
    if (fgets(nome, sizeof(nome), stdin)) {
        if (nome[0] != '\n') {
            nome[strcspn(nome, "\n")] = 0;
            strcpy(p.nome, nome);
        }
    }

    while (p.hp > 0) {
        printf("\n----- MENU -----\n");
        printf("[1] Explorar cidade\n[2] Descansar\n[3] Status\n[0] Sair\nEscolha: ");
        if (scanf("%d", &op) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n'); // Limpa buffer

        if (op == 1)
            explorar(&p);
        else if (op == 2) {
            int cura = rand()%8 + 5;
            p.hp += cura;
            if (p.hp > p.max_hp) p.hp = p.max_hp;
            printf("Voce descansou num pod tecnologico e recuperou %d de HP.\n", cura);
        }
        else if (op == 3)
            mostrar_status(&p);
        else if (op == 0)
            break;
        else
            printf("Opcao invalida!\n");
    }
    if (p.hp <= 0) printf("\nGAME OVER!\n");
    else printf("Saiu do jogo!\n");
    return 0;
}
