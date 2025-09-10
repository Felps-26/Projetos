#include <stdio.h>
#include <math.h>

int main() {
    int opcao;
    char novamente;

    do {
        printf("  |--------------------------|\n");
        printf("  |       !Calculadora!      |\n");
        printf("  |--------------------------|\n\n\n");
        printf("  |--------------------------|\n");
        printf("  |   Escolha uma operacao   |\n");
        printf("  |--------------------------|\n");
        printf("  | 1. Soma/Subtracao        |\n");
        printf("  |--------------------------|\n");
        printf("  | 2. Multiplicacao         |\n");
        printf("  |--------------------------|\n");
        printf("  | 3. Divisao               |\n");
        printf("  |--------------------------|\n");
        printf("  | 4. Potencia              |\n");
        printf("  |--------------------------|\n");
        printf("  | 5. Raiz Quadrada         |\n");
        printf("  |--------------------------|\n");
        printf("  | 6. Fatorial              |\n");
        printf("  |--------------------------|\n");
        printf("  | 7. Equacao segundo grau  |\n");
        printf("  |--------------------------|\n");
        printf("  | 8. Logaritmo             |\n");
        printf("  |--------------------------|\n\n");

        printf("   Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int n;
                float numeros[100], resultado = 0.0;

                do {
                    printf("   Quantos numeros voce deseja somar/subtrair? ");
                    scanf("%d", &n);

                    if (n > 100) {
                        printf("   Erro: Maximo de 100 numeros permitido.\n\n");
                        continue;
                    }

                    for (int i = 0; i < n; i++) {
                        printf("   Digite o numero %d: ", i + 1);
                        scanf("%f", &numeros[i]);
                        resultado += numeros[i];
                    }
                } while (n > 100);

                printf("  |----------------------------------------------|\n");
                printf("  |O resultado da soma e: %.2f                   |\n", resultado);
                printf("  |----------------------------------------------|\n\n");
                break;
            }

            case 2: {
                int n;
                float numeros[100], resultado = 1.0;

                do {
                    printf("   Quantos numeros voce deseja multiplicar? ");
                    scanf("%d", &n);

                    if (n > 100) {
                        printf("   Erro: Maximo de 100 numeros permitido.\n\n");
                        continue;
                    }

                    for (int i = 0; i < n; i++) {
                        printf("   Digite o numero %d: ", i + 1);
                        scanf("%f", &numeros[i]);
                        resultado *= numeros[i];
                    }
                } while (n > 100);

                printf("  |----------------------------------------------|\n");
                printf("  |O resultado da multiplicacao e: %.2f          |\n", resultado);
                printf("  |----------------------------------------------|\n\n");
                break;
            }

            case 3: {
                float dividendo, divisor, resultado;

                do {
                    printf("   Digite o dividendo: ");
                    scanf("%f", &dividendo);

                    printf("   Digite o divisor: ");
                    scanf("%f", &divisor);

                    if (divisor == 0) {
                        printf("   Erro: Divisao por zero nao e permitida, tente novamente.\n\n");
                    }
                } while (divisor == 0);

                resultado = dividendo / divisor;
                printf("  |----------------------------------------------|\n");
                printf("  |O resultado da divisao e: %.2f                |\n", resultado);
                printf("  |----------------------------------------------|\n\n");
                break;
            }

            case 4: {
                float base, expoente;

                printf("   Digite a base: ");
                scanf("%f", &base);

                printf("   Digite o expoente: ");
                scanf("%f", &expoente);

                float resultado = pow(base, expoente);
                printf("  |----------------------------------------------|\n");
                printf("  |O resultado da potencia e: %.2f               |\n", resultado);
                printf("  |----------------------------------------------|\n\n");
                break;
            }

            case 5: {
                float numero;

                do {
                    printf("   Digite o numero para calcular a raiz quadrada: ");
                    scanf("%f", &numero);

                    if (numero < 0) {
                        printf("   Erro: Nao e possivel calcular a raiz quadrada de um numero negativo.\n\n");
                    }
                } while (numero < 0);

                float resultado = sqrt(numero);
                printf("  |----------------------------------------------|\n");
                printf("  |A raiz quadrada e: %.2f                       |\n", resultado);
                printf("  |----------------------------------------------|\n\n");
                break;
            }

            case 6: {
                float entrada;
                int numero;

                do {
                    printf("   Digite o numero para calcular o fatorial: ");
                    scanf("%f", &entrada);

                    if (entrada != (int)entrada) {
                        printf("   Erro: O fatorial e definido apenas para numeros inteiros.\n\n");
                        continue;
                    }

                    numero = (int)entrada;

                    if (numero < 0) {
                        printf("   Erro: Fatorial nao e definido para numeros negativos.\n\n");
                    }
                } while (entrada != (int)entrada || numero < 0);

                unsigned long long int fatorial = 1;
                for (int i = 1; i <= numero; i++) {
                    fatorial *= i;
                }

                printf("  |----------------------------------------------|\n");
                printf("  |O fatorial de %d e: %llu                      |\n", numero, fatorial);
                printf("  |----------------------------------------------|\n\n");
                break;
            }

            case 7: {
                float a, b, c, delta, x1, x2;

                do {
                    printf("   Digite os coeficientes a, b e c da equacao ax^2 + bx + c = 0:\n");
                    scanf("%f %f %f", &a, &b, &c);

                    if (a == 0) {
                        printf("   Digite o coeficiente 'a' (diferente de zero): ");
                        scanf("%f", &a);
                    }
                } while (a == 0);

                delta = b * b - 4 * a * c;

                if (delta < 0) {
                    printf("  |---------------------------------|\n");
                    printf("  |A equacao nao possui raizes reais|\n");
                    printf("  |---------------------------------|\n\n");
                } else if (delta == 0) {
                    x1 = -b / (2 * a);
                    printf("  |----------------------------------------------|\n");
                    printf("  |A equacao possui uma raiz real: x = %.2f      |\n", x1);
                    printf("  |----------------------------------------------|\n\n");
                } else {
                    x1 = (-b + sqrt(delta)) / (2 * a);
                    x2 = (-b - sqrt(delta)) / (2 * a);
                    printf("  |----------------------------------------------------|\n");
                    printf("  |As raizes da equacao sao: x1 = %.2f e x2 = %.2f     |\n", x1, x2);
                    printf("  |----------------------------------------------------|\n\n");
                }
                break;
            }

            case 8: {
                int n;

                printf("   Qual tipo de log deseja calcular\n   1. Log Base natural\n   2. Log Base 10\n   3. Log\n");
                printf("   Opcao: ");
                scanf("%d", &n);

                switch (n) {
                    case 1: {
                        int x;
                        float resultado;

                        printf("   Digite o Logaritmando: ");
                        scanf("%d", &x);

                        while (x < 0) {
                            printf("   Erro. O Log nao aceita numeros negativos.\n");
                            printf("   Digite o Logaritmando: ");
                            scanf("%d", &x);
                        }

                        resultado = log(x);
                        printf("  |----------------------------------------------------|\n");
                        printf("  |O resultado do Log de %d na base natural eh: %.2f   |\n", x, resultado);
                        printf("  |----------------------------------------------------|\n\n");
                        break;
                    }

                    case 2: {
                        int x;
                        float resultado;

                        printf("   Digite o Logaritmando: ");
                        scanf("%d", &x);

                        while (x < 0) {
                            printf("   Erro. O Log nao aceita numeros negativos.\n");
                            printf("   Digite o Logaritmando: ");
                            scanf("%d", &x);
                        }

                        resultado = log10(x);
                        printf("  |-------------------------------------------------|\n");
                        printf("  |O resultado do Log de %d na base 10 eh: %.2f     |\n", x, resultado);
                        printf("  |-------------------------------------------------|\n\n");
                        break;
                    }

                    case 3: {
                        int x, y;
                        float resultado;

                        printf("   Digite o Logaritmando: ");
                        scanf("%d", &x);

                        while (x < 0) {
                            printf("   Erro. O Log nao aceita numeros negativos.\n");
                            printf("   Digite o Logaritmando: ");
                            scanf("%d", &x);
                        }

                        printf("   Digite a Base: ");
                        scanf("%d", &y);

                        while (y <= 0) {
                            printf("   Erro. A base do Log deve ser maior que zero.\n");
                            printf("   Digite a Base: ");
                            scanf("%d", &y);
                        }

                        resultado = log10(x) / log10(y);
                        printf("  |-------------------------------------------------|\n");
                        printf("  |O resultado do Log de %d na base %d eh: %.2f     |\n", x, y, resultado);
                        printf("  |-------------------------------------------------|\n\n");
                        break;
                    }

                    default:
                        printf("   Erro. Opcao invalida para o tipo de logaritmo.\n");
                        break;
                }
                break;
            }

            default:
                printf("   Erro. Opcao invalida! Por favor, escolha uma opcao entre 1 e 8.\n");
                break;
        }

        char buffer[10];

        do {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            printf("   Deseja realizar outra operacao? (S/N): ");
            fgets(buffer, sizeof(buffer), stdin);

            novamente = buffer[0];
            if (novamente != 'S' && novamente != 's' && novamente != 'N' && novamente != 'n') {
                printf("   Opcao invalida. Por favor, escolha S ou N.\n\n");
            }
        } while (novamente != 'S' && novamente != 's' && novamente != 'N' && novamente != 'n');

    } while (novamente == 'S' || novamente == 's');

    printf("  |---------------------------------|\n");
    printf("  |Obrigado por usar a calculadora! |\n");
    printf("  |Ate logo!                        |\n");
    printf("  |---------------------------------|\n");

    return 0;
}