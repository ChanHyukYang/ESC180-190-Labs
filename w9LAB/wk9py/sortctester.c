#include <stdio.h>
#include <stdlib.h>
#include "sort.c"
int main(void){
   int y = 0;
   int A[6];
   A[0] = 1;
   A[1] = 4;
   A[2] = 3;
   A[3] = 8;
   A[4] = 9;
   A[5] = 7;
   printf("%d,%d,%d,%d,%d,%d\n",A[0],A[1],A[2],A[3],A[4],A[5]);
   y = bubbleSort(A,6);
   printf("%d,%d,%d,%d,%d,%d,%d\n",y,A[0],A[1],A[2],A[3],A[4],A[5]);
   return 0;
}
