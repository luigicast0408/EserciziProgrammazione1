#include <stdio.h>

int main(){
    
  printf("\n");
  for(unsigned char c=0; c<128; c++){
    printf("c: %hhd / %c", c, c);
    if(c%10==0)
      printf("\n");
  }

   

}
