#include <stdio.h>
  
  *float getAvg(float *x, int N);
  
  
   int main (void){
      float test[3] = {1, 2, 3};
      getAvg(test, 3);
      return 0;
  }
  */

float getAvg(float * x, int  N) {
   int i = 0;
   float accum = 0;
   float avg = 0;
   if (x == NULL){
      return -1;
   }
   for (i=0; i<N; i++) {
       accum = accum + x[i];
   }
   avg=accum/N;
   return (avg);
}
