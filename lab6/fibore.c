#include <stdio.h>
int fiborec(int n);

int main(void){
   int i = 0;
   for(i=0;i<10;i=i+1){
   printf("%d\n",fiborec(i));
}  return 0;
}

int fiborec(int n){
   if(n == 0){
      return 1;
}  else if(n == 1){
      return 1;
}  else{
      return(fiborec(n-2)+fiborec(n-1));
}
}
