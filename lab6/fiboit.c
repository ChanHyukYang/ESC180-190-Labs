#include <stdio.h>
int fiboit(int n);

int main(void){
   int i = 0;
   for(i=0; i<10; i = i + 1){
      printf("%d\n",fiboit(i));
}  return 0;
}

int fiboit(int n){
   int old = 1;
   int new = 1;
   int dum = 1;
   int m = 1;
   if (n == 0){
      return 1;
}
   if (n == 1){
      return 1;
}  else{
      for(m=1;m<n;m=m+1){
         dum = new;
         new = new + old;
         old = dum;
}   
   return new;
}
}      
