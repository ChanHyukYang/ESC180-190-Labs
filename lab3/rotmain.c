#include <stdlib.h>
#include <stdio.h>
#include "avlrot.h"

int main(void) {
   int n = 0;
   avlNode *root=NULL;
   add_avl(&root,5);
   add_avl(&root,3);
   add_avl(&root,1);
   add_avl(&root,4);
   add_avl(&root,7);
   add_avl(&root,6);
   add_avl(&root,9);
   add_avl(&root,100);
   add_avl(&root,8);
   add_avl(&root,1000);
   printf("%d\n",isAVL(&root));
   n=rotate(&root, 0);
   printf("%d\n",isAVL(&root));
   return 0;
} 
