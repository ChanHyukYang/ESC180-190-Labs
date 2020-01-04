#include <stdio.h>
#include <stdlib.h>
#include "ge.c"
void printMatrix(float *m, int rows, int cols){
   int i=0;
   int j=0;
   for (i = 0; i < rows; i += 1){
      for (j = 0; j < cols; j += 1)
         printf("%8.1f", m[i * cols + j]);
      printf("\n");
}
}
int main(void){
   const int rows = 3;
   const int columns = 5;
   float m[15] = { 5, 2, 6, 8, 1, 3, 7, 3, 1, 2, 3, 8, 1, 2, 6 };
   float *m2 = NULL;
   float *m3 = NULL;
   printMatrix(m, rows, columns);
   m2 = (float*)malloc(sizeof(float) * rows * columns);
   m3 = (float*)malloc(sizeof(float) * rows * columns);
   ge_fw((float*)m, rows, columns, m2);
   ge_bw((float*)m2, rows, columns, m3);
   printf("*****************\n");
   printMatrix(m3, rows, columns);
   return 0;
}
