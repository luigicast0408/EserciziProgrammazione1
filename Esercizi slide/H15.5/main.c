#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

char *random_letters(int len_str);
int count_vowels(char str[], int len_str);

int main() {
    char *str = random_letters(10);
    printf("The string is: %s\n", str);
    printf("The vowels are:  %d\n", count_vowels(str, 10));

    free(str);

    return 0;
}

char *random_letters(int len_str) {
    char *str = (char *)malloc(len_str * sizeof(char));
    srand(time(NULL));

    for (int i = 0; i < len_str - 1; ++i) {
        str[i] = rand() % ('z' - 'a' + 1) + 'a';
    }

    str[len_str - 1] = '\0';
    return str;
}

int count_vowels(char str[], int len_str) {
    int c_vowels = 0;
    for (int i = 0; i < len_str; ++i) {
        printf("%c\t\n",str[i]);
        switch (str[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                c_vowels++;
                break;
        }
    }
    return c_vowels;
}
