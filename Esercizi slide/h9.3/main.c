#include <stdio.h>

int main() {
    char car;
    printf("\nInserisci un carettere: \n");
    scanf("%c",&car);
   // printf("%d",car);
    switch (car)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("\n carettere (%c)\n",car);
            break;

        case 'A':{
            printf("\n carettere (%c)\n",car);
            break;
        }
        case 'E':{
            printf("\n carettere (%c)\n",car);
            break;
        }
        case 'I':{
            printf("\n carettere (%c)\n",car);
            break;
        }
        case 'O':{
            printf("\n carettere (%c)\n",car);
            //fprintf(stdout,"\n carettere (%c)\n",car);
            break;
        }case 'U':{
            printf("\n carettere (%c)\n",car);
            break;
        }
        default:
        {
            if((int)car<1){
                if((int)car>3){
                    printf("%d",((int)car*10));
                }
            }
        }

    }
}