#include <stdio.h>
float bsqrt(float x, float accuracy);
float myAbs(float i);

int main(void){
   int i;
   for(i=0;i<10;i++){
      float sqrt;
      sqrt=bsqrt((float)i, 0.001);
      printf("The sqrt of %d is %f\n",i,sqrt);
   }
   return 0;
}

float bsqrt(float x, float accuracy){
   float est = x/2;
   while (myAbs(x - est*est)>accuracy){
      est = (est + x/est)/2;
}  return est;
}   
float myAbs(float i){
   if (i < 0){
      return -i;
}  else if (i > 0){
      return i;
}  else if (i == 0){
      return 0;
}
}
