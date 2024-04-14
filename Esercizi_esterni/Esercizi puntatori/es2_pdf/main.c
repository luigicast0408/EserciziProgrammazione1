#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
void split_time ( long int tot_sec, int *h, int *m, int *s );

int main()
{
 long int tot_sec=60;
 int h,m,s;
 split_time(tot_sec,&h,&m,&s);
 printf("\nOrariorio\nOre:%d\nMinuti:%d\nSecondi:%d\n",h,m,s);

}
void split_time ( long int tot_sec, int *h, int *m, int *s ){
    *h=(int)tot_sec/360;
    *m=(int)(tot_sec % 3600);
    *s=tot_sec % 60;

}