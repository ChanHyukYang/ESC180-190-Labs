#include <stdio.h>
float bsqrt(float x,float tol);
float mabs(float x);

int main(void){
   int i;
   for(i=0; i<10; i++){
      float sqrt;
      sqrt = bsqrt((float)i, 0.00001);
      printf("this is %d, it's square root is %f\n",i,sqrt);
}  return 0;
}

float bsqrt(float x,float tol){
   float est;
   est = x/2.0;
   while(mabs(x-est*est)>tol){
      est = (est+x/est)/2.0;
}  return est;
}

float mabs(float x){
   if (x > 0){
      return x;
}  else if (x < 0){
      return -x;
}  else if (x == 0){
      return 0;
}
}
