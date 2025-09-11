#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 6
#define WORD_MAX 20

const char *words[] = {"programacao", "computador", "algoritmo", "ponteiro", "universidade", "felicidade"};
const int NUM_WORDS = sizeof(words) / sizeof(words[0]);

void show_hangman(int tries) {
    const char *stages[] = {
        "  -----\n  |   |\n      |\n      |\n      |\n      |\n=====|====",
        "  -----\n  |   |\n  O   |\n      |\n      |\n      |\n=====|====",
        "  -----\n  |   |\n  O   |\n  |   |\n      |\n      |\n=====|====",
        "  -----\n  |   |\n  O   |\n /|   |\n      |\n      |\n=====|====",
        "  -----\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=====|====",
        "  -----\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=====|====",
        "  -----\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=====|===="
    };
    printf("%s\n", stages[tries]);
}

int already_guessed(char letter, const char *used) {
    for (int i = 0; used[i] != 0; i++)
        if (used[i] == letter) return 1;
    return 0;
}

int main() {
    char display[WORD_MAX], guess, used[30] = "";
    int word_index = 0; // Troque para variar a palavra
    strcpy(display, words[word_index]);
    for (int i = 0; display[i]; i++)
        display[i] = (i == 0 || i == strlen(words[word_index])-1 || words[word_index][i] == '-') ? words[word_index][i] : '_';

    int tries = 0, won = 0, len = strlen(words[word_index]), correct = 0;
    printf("\nBem-vindo ao Jogo da Forca!\n");

    while (tries < MAX_TRIES && !won) {
        printf("\nPalavra: %s\n", display);
        printf("Letras usadas: %s\n", used);
        show_hangman(tries);

        printf("\nDigite uma letra: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        if (!isalpha(guess) || already_guessed(guess, used)) {
            printf("Letra inválida ou já usada. Tente outra.\n");
            continue;
        }

        strncat(used, &guess, 1);

        int found = 0;
        for (int i = 0; i < len; i++) {
            if (words[word_index][i] == guess && display[i] == '_') {
                display[i] = guess;
                found = 1;
                correct++;
            }
        }

        if (!found) tries++;

        if (strcmp(display, words[word_index]) == 0)
            won = 1;
    }

    if (won) {
        printf("\nParabéns! Você acertou: %s\n", words[word_index]);
    } else {
        show_hangman(MAX_TRIES);
        printf("\nVocê perdeu! A palavra era: %s\n", words[word_index]);
    }

    return 0;
}