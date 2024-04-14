#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int N_lanci;
    printf("\nQuanti lanci vuoi compiere? \n");
    scanf("%d",&N_lanci);
    srand(time(NULL));

    for (int i = 0; i < N_lanci; ++i)
        printf("%d   %d \n",(rand()%6+1),(rand()%6+1));

}