import java.util.Random;
import java.util.Scanner;

public class main {
    static class Jogador {
        String nome;
        int hp, max_hp;
        int ataque, defesa, nivel, xp;
        Jogador(String nome) {
            this.nome = nome;
            this.nivel = 1;
            this.xp = 0;
            this.max_hp = this.hp = 30;
            this.ataque = 8;
            this.defesa = 3;
        }
    }

    static class Inimigo {
        String nome;
        int hp, ataque, defesa, recompensa_xp, nivel, chance_fuga;
    }

    static Random rand = new Random();
    static Scanner sc = new Scanner(System.in);

    static void mostrarStatus(Jogador p) {
        System.out.println("-> " + p.nome +
        " | HP: " + p.hp + "/" + p.max_hp +
        " | Nivel: " + p.nivel + " | XP: " + p.xp);
    }

    static boolean tentarFugir(int chance) {
        int rolagem = rand.nextInt(100);
        if (rolagem < chance) {
            System.out.println("Voce conseguiu fugir!");
            return true;
        } else {
            System.out.println("Fuga falhou!");
            return false;
        }
    }

    static void menuAtaque() {
        System.out.println("\n--- Menu de Batalha ---");
        System.out.println("[1] Atacar");
        System.out.println("[2] Fugir");
        System.out.print("Escolha: ");
    }

    static void batalha(Jogador p, Inimigo inimigo) {
        System.out.println("=== Batalha contra " + inimigo.nome + " (Nivel " + inimigo.nivel + ") ===");
        while (p.hp > 0 && inimigo.hp > 0) {
            menuAtaque();
            String input = sc.nextLine();
            int op = 0;
            try { op = Integer.parseInt(input); } catch (Exception e) { continue; }
            if (op == 1) {
                int dado = rand.nextInt(6) + 1;
                int dano = (p.ataque + dado) - inimigo.defesa;
                dano = Math.max(1, dano);
                inimigo.hp -= dano;
                System.out.println(p.nome + " ataca e causa " + dano + " de dano! (Vida do inimigo: " + Math.max(inimigo.hp,0) + ")");
            } else if (op == 2) {
                if (tentarFugir(inimigo.chance_fuga)) return;
            } else {
                System.out.println("Opcao invalida!");
                continue;
            }
            if (inimigo.hp <= 0) break;
            int dado = rand.nextInt(6) + 1;
            int dano = (inimigo.ataque + dado) - p.defesa;
            dano = Math.max(1, dano);
            p.hp -= dano;
            System.out.println(inimigo.nome + " ataca e causa " + dano + " de dano! (Sua vida: " + Math.max(p.hp,0) + ")");
        }
        if (p.hp > 0 && inimigo.hp <= 0) {
            System.out.println("Voce derrotou " + inimigo.nome + "! Ganhou " + inimigo.recompensa_xp + " XP");
            p.xp += inimigo.recompensa_xp;
        } else if (p.hp <= 0) {
            System.out.println("Voce foi derrotado...");
        }
    }

    static void subirDeNivel(Jogador p) {
        while (p.xp >= (p.nivel * 20)) {
            p.nivel++;
            p.max_hp += 10;
            p.ataque += 2;
            p.defesa += 1;
            p.hp = p.max_hp;
            System.out.println("Parabens! Voce subiu para o nivel " + p.nivel + "!");
        }
    }

    static void gerarInimigo(Inimigo inimigo, int nivelJogador) {
        int tipo = rand.nextInt(3);
        if (tipo == 0) {
            inimigo.nome = "Dron de Ataque";
            inimigo.nivel = nivelJogador;
            inimigo.hp = 12 + nivelJogador * 3;
            inimigo.ataque = 5 + nivelJogador;
            inimigo.defesa = 2 + nivelJogador/2;
            inimigo.recompensa_xp = 8 + nivelJogador * 2;
            inimigo.chance_fuga = 70;
        } else if (tipo == 1) {
            inimigo.nome = "Android Rogue";
            inimigo.nivel = nivelJogador + 1;
            inimigo.hp = 20 + nivelJogador * 4;
            inimigo.ataque = 7 + nivelJogador;
            inimigo.defesa = 3 + nivelJogador/2;
            inimigo.recompensa_xp = 12 + nivelJogador * 3;
            inimigo.chance_fuga = 50;
        } else {
            inimigo.nome = "Mecha Assassino";
            inimigo.nivel = nivelJogador + 2;
            inimigo.hp = 30 + nivelJogador * 5;
            inimigo.ataque = 10 + nivelJogador * 2;
            inimigo.defesa = 5 + nivelJogador;
            inimigo.recompensa_xp = 20 + nivelJogador * 4;
            inimigo.chance_fuga = 30;
        }
    }

    static void explorar(Jogador p) {
        int evento = rand.nextInt(3);
        if (evento == 0) {
            Inimigo inimigo = new Inimigo();
            gerarInimigo(inimigo, p.nivel);
            batalha(p, inimigo);
        } else if (evento == 1) {
            int cura = rand.nextInt(10) + 5;
            p.hp += cura;
            if (p.hp > p.max_hp) p.hp = p.max_hp;
            System.out.println("Voce encontrou um kit medico futurista e recuperou " + cura + " de HP!");
        } else {
            System.out.println("Voce encontrou um upgrade de ataque (+2 ataque)!");
            p.ataque += 2;
        }
        subirDeNivel(p);
    }

    public static void main(String[] args) {
        System.out.println("=== RPG FUTURISTA TERMINAL ===");
        System.out.print("Nome do personagem (ENTER para NeoRunner): ");
        String nome = sc.nextLine();
        if (nome.isEmpty()) nome = "NeoRunner";
        Jogador p = new Jogador(nome);

        while (p.hp > 0) {
            System.out.println("\n----- MENU -----");
            System.out.println("[1] Explorar cidade");
            System.out.println("[2] Descansar");
            System.out.println("[3] Status");
            System.out.println("[0] Sair");
            System.out.print("Escolha: ");
            String input = sc.nextLine();
            int op = 9;
            try { op = Integer.parseInt(input); } catch (Exception e) { continue; }

            if (op == 1) {
                explorar(p);
            } else if (op == 2) {
                int cura = rand.nextInt(8) + 5;
                p.hp += cura;
                if (p.hp > p.max_hp) p.hp = p.max_hp;
                System.out.println("Voce descansou num pod tecnologico e recuperou " + cura + " de HP.");
            }
            else if (op == 3)
                mostrarStatus(p);
            else if (op == 0)
                break;
            else
                System.out.println("Opcao invalida!");
        }
        if (p.hp <= 0) System.out.println("\nGAME OVER!");
        else System.out.println("Saiu do jogo!");
    }
}
