#include <stdio.h>

int main() {
    printf("\nHello word! (stdout)\n");
    fprintf(stderr,"\nHello word! (sterr)\n");
    fprintf(stdout,"Hello word!(stdout)");
}
