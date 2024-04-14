#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
void printvector(int *V,int N);

int main() {
    const int N = 10;
    int V[N];
    int a = 10, b = 50;
    srand(time(NULL));
    for (int i = 0; i < N; ++i) {
        V[i] = rand() % (b - a + 1) + a;
        //*(V+i)=rand()%(b-a+1)+a;
    }
    printvector(V, N);
    const int *ptr = V;
    const double *ptr_vet=NULL;
    for (int i = 0; i <N ; ++i) {
        printf("\ntest->%d\n",i);
        if(i%2!=0 && i%3!=0){
            printf("\n%d\t",*(ptr+i));
            //*(ptr+i)=rand()%((200-100)+1)+100;
        }
    }
}

void printvector(int *V,int N) {
    printf("\n_________Vector__________________\n");
    for (int i = 0; i < N; ++i)
        printf("numero->%d ",V[i]);
    printf("\n_________Vector__________________\n");

}

