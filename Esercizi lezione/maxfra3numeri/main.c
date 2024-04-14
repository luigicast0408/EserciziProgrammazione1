#include <stdio.h>
int main() {
    int num1, num2, num3;
    printf("\ninserisci il primo numero\n");
    scanf("%d", &num1);
    printf("\ninserisci il secondo numero\n");
    scanf("%d", &num2);
    printf("\ninserisci il terzo numero\n");
    scanf("%d", &num3);

    if (num1 == num2) {
        if (num2 == num3) {
            printf("\n i numei sono uguali\n");
        }
    }
    else if (num1 > num2) {
        if (num1 > num3) {
            printf("il primo numeo è il max (%d)", num1);
        }
    }
    else if (num2 > num3) {
        if (num1 > num3) {
            printf("il maggiore è il secondo numero (%d)", num2);
        }
    }
    else
        printf("il terzo numero è  il max maggiore (%d)", num3);
}

