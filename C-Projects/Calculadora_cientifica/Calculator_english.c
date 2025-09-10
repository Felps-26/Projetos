#include <stdio.h>
#include <math.h>

int main() {
    int option;
    char again;

    do {
        printf("  |--------------------------|\n");
        printf("  |       !Calculator!       |\n");
        printf("  |--------------------------|\n\n\n");
        printf("  |--------------------------|\n");
        printf("  |   Choose an operation    |\n");
        printf("  |--------------------------|\n");
        printf("  | 1. Addition/Subtraction  |\n");
        printf("  |--------------------------|\n");
        printf("  | 2. Multiplication        |\n");
        printf("  |--------------------------|\n");
        printf("  | 3. Division              |\n");
        printf("  |--------------------------|\n");
        printf("  | 4. Power                 |\n");
        printf("  |--------------------------|\n");
        printf("  | 5. Square Root           |\n");
        printf("  |--------------------------|\n");
        printf("  | 6. Factorial             |\n");
        printf("  |--------------------------|\n");
        printf("  | 7. Quadratic Equation    |\n");
        printf("  |--------------------------|\n");
        printf("  | 8. Logarithm             |\n");
        printf("  |--------------------------|\n\n");

        printf("   Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                int n;
                float numbers[100], result = 0.0;

                do {
                    printf("   How many numbers do you want to add/subtract? ");
                    scanf("%d", &n);

                    if (n > 100) {
                        printf("   Error: Maximum of 100 numbers allowed.\n\n");
                        continue;
                    }

                    for (int i = 0; i < n; i++) {
                        printf("   Enter number %d: ", i + 1);
                        scanf("%f", &numbers[i]);
                        result += numbers[i];
                    }
                } while (n > 100);

                printf("  |----------------------------------------------|\n");
                printf("  |The result of addition is: %.2f               |\n", result);
                printf("  |----------------------------------------------|\n\n");
                break;
            }

            case 2: {
                int n;
                float numbers[100], result = 1.0;

                do {
                    printf("   How many numbers do you want to multiply? ");
                    scanf("%d", &n);

                    if (n > 100) {
                        printf("   Error: Maximum of 100 numbers allowed.\n\n");
                        continue;
                    }

                    for (int i = 0; i < n; i++) {
                        printf("   Enter number %d: ", i + 1);
                        scanf("%f", &numbers[i]);
                        result *= numbers[i];
                    }
                } while (n > 100);

                printf("  |----------------------------------------------|\n");
                printf("  |The result of multiplication is: %.2f         |\n", result);
                printf("  |----------------------------------------------|\n\n");
                break;
            }

            case 3: {
                float dividend, divisor, result;

                do {
                    printf("   Enter the dividend: ");
                    scanf("%f", &dividend);

                    printf("   Enter the divisor: ");
                    scanf("%f", &divisor);

                    if (divisor == 0) {
                        printf("   Error: Division by zero is not allowed. Try again.\n\n");
                    }
                } while (divisor == 0);

                result = dividend / divisor;
                printf("  |----------------------------------------------|\n");
                printf("  |The result of division is: %.2f               |\n", result);
                printf("  |----------------------------------------------|\n\n");
                break;
            }

            case 4: {
                float base, exponent;

                printf("   Enter the base: ");
                scanf("%f", &base);

                printf("   Enter the exponent: ");
                scanf("%f", &exponent);

                float result = pow(base, exponent);
                printf("  |----------------------------------------------|\n");
                printf("  |The result of power is: %.2f                  |\n", result);
                printf("  |----------------------------------------------|\n\n");
                break;
            }

            case 5: {
                float number;

                do {
                    printf("   Enter the number to calculate the square root: ");
                    scanf("%f", &number);

                    if (number < 0) {
                        printf("   Error: Cannot calculate the square root of a negative number.\n\n");
                    }
                } while (number < 0);

                float result = sqrt(number);
                printf("  |----------------------------------------------|\n");
                printf("  |The square root is: %.2f                      |\n", result);
                printf("  |----------------------------------------------|\n\n");
                break;
            }

            case 6: {
                float input;
                int number;

                do {
                    printf("   Enter the number to calculate the factorial: ");
                    scanf("%f", &input);

                    if (input != (int)input) {
                        printf("   Error: Factorial is only defined for integers.\n\n");
                        continue;
                    }

                    number = (int)input;

                    if (number < 0) {
                        printf("   Error: Factorial is not defined for negative numbers.\n\n");
                    }
                } while (input != (int)input || number < 0);

                unsigned long long int factorial = 1;
                for (int i = 1; i <= number; i++) {
                    factorial *= i;
                }

                printf("  |----------------------------------------------|\n");
                printf("  |The factorial of %d is: %llu                  |\n", number, factorial);
                printf("  |----------------------------------------------|\n\n");
                break;
            }

            case 7: {
                float a, b, c, delta, x1, x2;

                do {
                    printf("   Enter the coefficients a, b, and c for the equation ax^2 + bx + c = 0:\n");
                    scanf("%f %f %f", &a, &b, &c);

                    if (a == 0) {
                        printf("   Enter coefficient 'a' (must not be zero): ");
                        scanf("%f", &a);
                    }
                } while (a == 0);

                delta = b * b - 4 * a * c;

                if (delta < 0) {
                    printf("  |---------------------------------|\n");
                    printf("  |The equation has no real roots   |\n");
                    printf("  |---------------------------------|\n\n");
                } else if (delta == 0) {
                    x1 = -b / (2 * a);
                    printf("  |----------------------------------------------|\n");
                    printf("  |The equation has one real root: x = %.2f      |\n", x1);
                    printf("  |----------------------------------------------|\n\n");
                } else {
                    x1 = (-b + sqrt(delta)) / (2 * a);
                    x2 = (-b - sqrt(delta)) / (2 * a);
                    printf("  |----------------------------------------------------|\n");
                    printf("  |The roots of the equation are: x1 = %.2f and x2 = %.2f |\n", x1, x2);
                    printf("  |----------------------------------------------------|\n\n");
                }
                break;
            }

            case 8: {
                int n;

                printf("   What type of logarithm do you want to calculate?\n   1. Natural Log\n   2. Base 10 Log\n   3. Custom Base Log\n");
                printf("   Option: ");
                scanf("%d", &n);

                switch (n) {
                    case 1: {
                        int x;
                        float result;

                        printf("   Enter the logarithm argument: ");
                        scanf("%d", &x);

                        while (x < 0) {
                            printf("   Error. Logarithm does not accept negative numbers.\n");
                            printf("   Enter the logarithm argument: ");
                            scanf("%d", &x);
                        }

                        result = log(x);
                        printf("  |----------------------------------------------------|\n");
                        printf("  |The result of the natural log of %d is: %.2f        |\n", x, result);
                        printf("  |----------------------------------------------------|\n\n");
                        break;
                    }

                    case 2: {
                        int x;
                        float result;

                        printf("   Enter the logarithm argument: ");
                        scanf("%d", &x);

                        while (x < 0) {
                            printf("   Error. Logarithm does not accept negative numbers.\n");
                            printf("   Enter the logarithm argument: ");
                            scanf("%d", &x);
                        }

                        result = log10(x);
                        printf("  |-------------------------------------------------|\n");
                        printf("  |The result of the base 10 log of %d is: %.2f     |\n", x, result);
                        printf("  |-------------------------------------------------|\n\n");
                        break;
                    }

                    case 3: {
                        int x, y;
                        float result;

                        printf("   Enter the logarithm argument: ");
                        scanf("%d", &x);

                        while (x < 0) {
                            printf("   Error. Logarithm does not accept negative numbers.\n");
                            printf("   Enter the logarithm argument: ");
                            scanf("%d", &x);
                        }

                        printf("   Enter the base: ");
                        scanf("%d", &y);

                        while (y <= 0) {
                            printf("   Error. The base of the logarithm must be greater than zero.\n");
                            printf("   Enter the base: ");
                            scanf("%d", &y);
                        }

                        result = log10(x) / log10(y);
                        printf("  |-------------------------------------------------|\n");
                        printf("  |The result of the log of %d with base %d is: %.2f |\n", x, y, result);
                        printf("  |-------------------------------------------------|\n\n");
                        break;
                    }

                    default:
                        printf("   Error. Invalid option for the type of logarithm.\n");
                        break;
                }
                break;
            }

            default:
                printf("   Error. Invalid option! Please choose an option between 1 and 8.\n");
                break;
        }

        char buffer[10];

        do {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            printf("   Do you want to perform another operation? (Y/N): ");
            fgets(buffer, sizeof(buffer), stdin);

            again = buffer[0];
            if (again != 'Y' && again != 'y' && again != 'N' && again != 'n') {
                printf("   Invalid option. Please choose Y or N.\n\n");
            }
        } while (again != 'Y' && again != 'y' && again != 'N' && again != 'n');

    } while (again == 'Y' || again == 'y');

    printf("  |---------------------------------|\n");
    printf("  |Thank you for using the calculator! |\n");
    printf("  |See you next time!                 |\n");
    printf("  |---------------------------------|\n");

    return 0;
}