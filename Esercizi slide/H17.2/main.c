#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
char *insert_string();
void print_string(char *string);
bool check_equal_string(char *string1,char *string2, char *string3);
void  check_string(char *string1,char *string2, char *string3);

int main()
{

 char *string1= insert_string();
 char *string2= insert_string();
 char *string3= insert_string();
 print_string(string1);
 print_string(string2);
 print_string(string3);
 check_string(string1,string2,string3);
    free(string1);
    free(string2);
    free(string3);

}

char *insert_string(){
    int start_n=10,end_n=20;
    char star_l='a',end_l='z';
    char start_n_char='0',end_n_char='9';
    srand(time(0));
    int size=rand()%(end_n-start_n+1)+start_n;
    printf("\nSize:%d\n",size);
    char *string= malloc(sizeof(char)*(size-1));
    for (int i = 0; i < size; i++) {
        if (i%2==0){
            string[i]=rand()/(char)((end_l-star_l+1)+star_l);
        }
        else{
            string[i]=rand()/(char)((end_n_char-start_n_char+1)+start_n_char);
        }
    }
    string[size]='\0';
    return string;
}

void print_string(char *string){
    printf("\n___________String_____________\n");
    printf("%s",string);
    printf("\n___________String_____________\n");
}

bool check_equal_string(char *string1,char *string2, char *string3) {
    if(strcmp(string1,string2)==0 || strcmp(string1,string3)==0 ){
        fprintf(stderr,"Le due stringhe sono uguali");
        return true;
    }
    return false;

}


void  check_string(char *string1,char *string2, char *string3){
    if(!check_equal_string(string1,string2,string3)){
        if(strcmp(string1,string2)<0 && strcmp(string1,string3)) {
            print_string(string1);
        }
        if(strcmp(string2,string3)<0 && strcmp(string2,string1)<0){
            print_string(string2);
        }
        print_string(string3);

    }
}



