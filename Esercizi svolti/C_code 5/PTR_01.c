#include <stdio.h>

void f1(int *p){
  *p = 45;
}

void foo1(int *a){
  a[4] = 20;
}

int main(){
  
  int a = 2;
  int *ptr = &a; 
  //p stores the address of a
    
  int arr[5] = {1,2,3,4,5};
  
  ptr = arr; 
  //ptr stores the address of the first element of arr

  printf("\n a=%d",  a);
  f1(&a);
  printf("\n (after call to f1()) a=%d",  a);

  printf("\n arr[4]=%d", arr[4]);
  foo1(arr);
  printf("\n After foo1(arr), arr[4]=%d", arr[4]);

  int c[20];
  //array are pointer constants
   // TRY the following: 
  //arr = &a; //ERR compilation 
  //arr = c; //ERR
     
}
