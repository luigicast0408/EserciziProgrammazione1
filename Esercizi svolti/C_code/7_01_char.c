#include <stdio.h>

int main()
{

  char a = 'x';
  int start;

  //Quanto vale a? Intero con segno o senza segno?  
  printf("Il carattere a: %c\n", a);
  printf("a= %c\n\n", a);

  for( start=(int) 'A'; start<(int) 'z'; start++)
  {
      printf("%c ", (char) start);
      printf("%d\n",start);
  }

  printf("\n\n");

  //quanto vale il carattere '~'? 
  printf("'~' == %d \n",(int) '~');
  
} // end main()
