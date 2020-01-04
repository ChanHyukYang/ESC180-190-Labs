#include<stdlib.h>
#include<stdio.h>
unsigned char prng(unsigned char x,unsigned char pattern);
int crypt(char*data,unsigned int size,unsigned char password);

unsigned char prng(unsigned char x, unsigned char pattern) {
   unsigned char oldbit0 = x & pattern; /* extract bit 0 */
   unsigned char r = x >> 1;        /* shift right   */
   unsigned char newbit7 = oldbit0 << 7; /* move bit0 to the bit7 pos */
   r = r ^ newbit7; /* rotate the old value of bit 0 into the bit 7 pos */
   return r;
}

int crypt(char *data,unsigned int size,unsigned char password) {
   unsigned char prngVal = password;
   int i = 0;
   for(i=0;i<size;i++){
      prngVal = prng(prngVal,0xb8);
      data[i] = data[i]^prngVal;
   }
   return 0;
}
