#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void menu() {
    printf("===== Calculadora Cientifica =====\n");
    printf("[1] Soma\n");
    printf("[2] Subtracao\n");
    printf("[3] Multiplicacao\n");
    printf("[4] Divisao\n");
    printf("[5] Potencia (x^y)\n");
    printf("[6] Raiz quadrada\n");
    printf("[7] Seno\n");
    printf("[8] Cosseno\n");
    printf("[9] Tangente\n");
    printf("[10] Logaritmo\n");
    printf("[11] Exponencial (e^x)\n");
    printf("[0] Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    int op;
    double x, y;
    do {
        system("clear||cls");
        menu();
        scanf("%d", &op);
        switch(op) {
            case 1:
                printf("Digite dois numeros: "); scanf("%lf %lf", &x, &y);
                printf("Resultado: %.6lf\n", x + y); break;
            case 2:
                printf("Digite dois numeros: "); scanf("%lf %lf", &x, &y);
                printf("Resultado: %.6lf\n", x - y); break;
            case 3:
                printf("Digite dois numeros: "); scanf("%lf %lf", &x, &y);
                printf("Resultado: %.6lf\n", x * y); break;
            case 4:
                printf("Digite dois numeros: "); scanf("%lf %lf", &x, &y);
                if (y == 0) printf("Divisao por zero!\n");
                else printf("Resultado: %.6lf\n", x / y);
                break;
            case 5:
                printf("Digite a base e o expoente: "); scanf("%lf %lf", &x, &y);
                printf("Resultado: %.6lf\n", pow(x, y)); break;
            case 6:
                printf("Digite um numero: "); scanf("%lf", &x);
                if (x < 0) printf("Raiz de numero negativo nao existe (numero real).\n");
                else printf("Resultado: %.6lf\n", sqrt(x));
                break;
            case 7:
                printf("Digite o angulo em graus: "); scanf("%lf", &x);
                printf("Resultado: %.6lf\n", sin(x * M_PI / 180));
                break;
            case 8:
                printf("Digite o angulo em graus: "); scanf("%lf", &x);
                printf("Resultado: %.6lf\n", cos(x * M_PI / 180));
                break;
            case 9:
                printf("Digite o angulo em graus: "); scanf("%lf", &x);
                printf("Resultado: %.6lf\n", tan(x * M_PI / 180));
                break;
            case 10:
                printf("Digite um numero positivo: "); scanf("%lf", &x);
                if (x <= 0) printf("Logaritmo nao existe para zero ou negativos.\n");
                else printf("Resultado (log natural): %.6lf\n", log(x));
                break;
            case 11:
                printf("Digite um numero: "); scanf("%lf", &x);
                printf("Resultado: %.6lf\n", exp(x));
                break;
            case 0:
                printf("Encerrando calculadora.\n"); break;
            default:
                printf("Opcao invalida!\n");
        }
        if (op != 0) {
            printf("\nPressione ENTER para continuar...");
            getchar(); getchar();
        }
    } while(op != 0);
    return 0;
}
