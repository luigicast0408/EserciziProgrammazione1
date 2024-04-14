#include <stdio.h>

#define MIN(a,b) (a<b ? a : b)

int main()
{

    int a, b, c, min;

    a = 10;
    b = 20;
    c = 15;

    //1) min(a,b)  -- if/else
    if (a < b)
	printf("min(a,b)=%d", a);
    else
	printf("min(a,b)=%d", b);

    // min(a,b)
    //2) operatore condizionale 
    min = (a < b ? a : b);
    printf("min(a,b)=%d", min);
    printf("min(a,b)=%d", (a < b ? a : b));

    //min(a,b,c) 
    // if--else--if
    if (a < b)
	if (a < c)
	    printf("Min(a,b,c)=%d", a);
	else
	    printf("Min(a,b,c)=%d", c);
    else if (b < c)
	printf("Min(a,b,c)=%d", b);
    else
	printf("Min(a,b,c)=%d", c);

    //min(a,b,c)
    // if--else-if
    min = (a < b ? (a < c ? a : c) : (b < c ? b : c));
    printf("\nmin(a,b,c)=%d", min);

    // Definire una "pseudo-funzione" min(a,b) con una direttiva del preprocessore? 
    printf("\nMIN(10,20)=%d", MIN(10,20)); 

    //esercizio. Definire una macro MIN(a,b,c) ? 

    return 0;
}
