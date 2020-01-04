#include<stdlib.h>
#include<stdio.h>
#include"crypt.c"
int main(void){
   unsigned char r = 15;
   unsigned char password = 'a';
   char h[4] = {'c','h','a','n'};
   printf("%u\n",r);
   r = crypt(h,4,password);
   printf("%c,%c,%c,%c,%x,%x,%x,%x",h[0],h[1],h[2],h[3],h[0],h[1],h[2],h[3]);
   r = crypt(h,4,password);
   printf("%c,%c,%c,%c,%x,%x,%x,%x",h[0],h[1],h[2],h[3],h[0],h[1],h[2],h[3]);
   return 0;
}
