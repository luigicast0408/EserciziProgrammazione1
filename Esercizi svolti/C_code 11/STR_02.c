#include <stdio.h>
#include <string.h> //strlen(), strcpy(), etc 

int main(){
  
  char str1[] = "pippo";
  char str2[] = "moda";
 
  /* STRLEN */ 
  printf("\n len(\"%s\"): %zd",str1, strlen(str1)); 
  printf("\n len(\"%s\"): %zd",str2, strlen(str2)); 

  printf("\n len(\"pippo1\"): %zd", strlen("pippo1")); 

  /* STRCMP */
  int r = 0;
  const char* tmp = "Pippo";
  if((r=strcmp(str1, tmp)) < 0)
    printf("\nString %s is less than %s", str1 , tmp); 
  else if(r>0)    
    printf("\n String %s is greater than %s", str1, tmp); 
  else    
    printf("\n String %s is equal to %s", str1, tmp); 

  const char* tmp1 = "zzzz";
  if((r=strcmp(str1, tmp1)) < 0)
    printf("\n String %s is less than %s", str1, tmp1); 
  else if(r>0)    
    printf("\n String %s is greter than %s", str1, tmp1); 
  else    
    printf("\n String %s is equal to %s", str1, tmp1);

  /* STRCPY */
  printf("\n Copying %s into %s", str2, str1);
  strcpy(str1, str2); //str1 <--str2;
  
  printf("\n str1: %s, str2: %s",  str1, str2); 

  /* STRSTR */
  char s[15] = "Abracadabra";
  char *found = strstr(s,"dab");
    printf("\n s: %s, string to find: %s", s, "dab");
  if(found!=NULL){
    printf("\n Found: %s \n", found);
    found[0] = 'X';   
    printf("%s\n", found); 
    }
    

  /* ESERCIZIO: usare la versione ``length-bounded'', ovvero strncmp() e strncpy() */
}
