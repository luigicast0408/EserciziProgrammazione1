#include <stdio.h>
#include <stdbool.h>

bool ispalindrome(char *s, int len);
int len_string(char *s);

int main() {
    char s[] = "anna";
    int len = len_string(s);
    bool palindrome = ispalindrome(s, len);

    return 0;
}

bool ispalindrome(char *s, int len) {
    int i = 0;
    int j = len - 1;

    while (i < j) {
        if (*(s + i) != *(s + j)) {
            printf("La stringa %s non e' palindroma\n", s);
            return false;
        }

        i++;
        j--;
    }

    printf("La stringa %s e' palindroma\n", s);
    return true;
}

int len_string(char *s) {
    int i = 0;
    while (*(s + i) != '\0') {
        i++;
    }
    return i;
}
