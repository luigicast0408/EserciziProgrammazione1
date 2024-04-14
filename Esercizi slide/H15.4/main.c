#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
 // si possono usare le costanti perche' non devo modificare la sringa
int str_len(char str[]);

int check_total(char str1[], char str2[]);

bool check_equals_str(char str1[], char str2[]);

bool check_less_str(char str1[], char str2[]);

bool check_greater_str(char str1[], char str2[]);

int main() {
    char str1[20], str2[20];
    printf("\nInserisci una stringa: \n");
    fflush(stdin);
    scanf("%s", str1);

    printf("\nInserisci una stringa: \n");
    fflush(stdin);
    scanf("%s", str2);
    //printf("\nLa stringa %s ha %d caretteri\n",str, str_len(str));
    printf("%d", check_total(str1, str2));
}

int str_len(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int check_total(char str1[], char str2[]) {
    bool equals = check_equals_str(str1, str2);
    bool less = check_equals_str(str1, str2);
    bool greater = check_greater_str(str1, str2);
    printf("\nLe due stringhe sono : S1=%s   S2=%s\n", str1, str2);
    if (equals) { return 0; }
    else if (less) { return -1; }
    else if (greater) { return 1; }
    else return 0;

}

bool check_equals_str(char str1[], char str2[]) {
    int len_str1 = str_len(str1);
    int len_str2 = str_len(str2), cont = 0;
    if (len_str1 == len_str2) {
        for (int i = 0; i < len_str1; ++i) {
            for (int j = 0; j < len_str2; ++j) {
                if (str1[i] == str2[j])
                    cont++;
            }
        }
        if (cont == len_str1) {
            return true;
        } else
            return false;
    }
    return false;
}

bool check_less_str(char str1[], char str2[]) {
    int len_str1 = str_len(str1);
    int len_str2 = str_len(str2), cont = 0;
    for (int i = 0; i < len_str1; ++i) {
        for (int j = 0; j < len_str2; ++j) {
            if (str1[i] < str2[j])
                cont++;
        }
    }
    if (cont == len_str1)
        return true;
    else
        return false;
}

bool check_greater_str(char str1[], char str2[]) {
    int len_str1 = str_len(str1);
    int len_str2 = str_len(str2), cont = 0;
    for (int i = 0; i < len_str1; ++i) {
        for (int j = 0; j < len_str2; ++j) {
            if (str1[i] > str2[j])
                cont++;
        }
    }
    if (cont == len_str1)
        return true;
    else
        return false;
}