
#define NUM_DONATIONS 15

#include "array_ptr.h"


int main()
{
   // An array containing the donation amounts.
   int donations[NUM_DONATIONS] = {5,100, 5,25, 10, 5,  25, 5,  5, 100, 10, 15, 10, 5,  10 };
   int *arrPtr[NUM_DONATIONS]; // An array of pointers to int.
   
   // Each element of arrPtr is a pointer to an int element in donations 
   for (int count = 0; count < NUM_DONATIONS; count++)
      arrPtr[count] = &donations[count];

   arrSelectSort(arrPtr, NUM_DONATIONS); // Sort the elements of the array of pointers.

   // Display the donations using the array of pointers in sorted order.
   printf("The donations, sorted in ascending order are: \n");
   showArrPtr(arrPtr, NUM_DONATIONS);

   // Display the donations in their original order.
   printf("The donations, in their original order are: \n");
   showArray(donations, NUM_DONATIONS);
   return 0;
}
