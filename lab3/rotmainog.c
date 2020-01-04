#include <stdlib.h>
#include <stdio.h>
struct avlNode {
   int balance; /* -1 Left, 0 balanced, +1 Right */
   int val;
   struct avlNode *l;
   struct avlNode *r;
};
typedef struct avlNode avlNode;
struct qNode {
   avlNode *pval;
   struct qNode *nxt;
};
typedef struct qNode qNode;
int isAVL(avlNode **root){
   int n = 0;
   n = -isavlhelper(&(*root)->l) + isavlhelper(&(*root)->r);
   if(n == 0 ||n == -1 || n == 1){
      return 0;
}  else{
      return -1;
}}

int rotate(avlNode **root, unsigned int Left0_Right1){
   avlNode *temp1;
   avlNode *temp2;
   if (root==NULL){
      return -1;
}  if (Left0_Right1==1){
      temp1 = (*root)->l->r;
      temp2 = (*root)->l;
      (*root)->l->r = *root;
      (*root)->l = temp1;
      *root = temp2;
      return 0;
}  else if (Left0_Right1==0){
      temp1 = (*root)->r->l;
      temp2 = (*root)->r;
      (*root)->r->l = *root;
      (*root)->r = temp1;
      *root = temp2;
      return 0;
}  
}
int dblrotate(avlNode **root,unsigned int MajLMinR0_MajRMinL1){
   avlNode *temp1;
   avlNode *temp2;
   avlNode *temp3;
   if(root==NULL){
      return -1;
}  if (MajLMinR0_MajRMinL1 == 0){
      temp1 = (*root)->r->l->r;
      temp3 = (*root)->r->l;
      (*root)->r->l->r = (*root)->r;
      (*root)->r->l = temp1;
      (*root)->r = temp3;
      temp2 = (*root)->r->l;
      (*root)->r->l = (*root);
      (*root)->r = temp2;
      *root = temp3;
      return 0;
}  else if (MajLMinR0_MajRMinL1 == 1){      
      temp1 = (*root)->l->r->l;
      temp3 = (*root)->l->r;
      (*root)->l->r->l = (*root)->l;
      (*root)->l->r = temp1;
      (*root)->l= temp3;
      temp2 = (*root)->l->r;
      (*root)->l->r = (*root);
      (*root)->l = temp2;
      *root = temp3;
      return 0;
}} 
int isavlhelper(avlNode **root){
   int l = isavlhelper(&(*root)->l);
   int r = isavlhelper(&(*root)->r);
    if(root == NULL){
      return -1;
}   if ((*root) == NULL){
      return 0;
}   if(r>l){
      return r + 1;
}  else{
   return l+1;
}}
int add_avl(avlNode **root,int val) {
   if (root == NULL){
      return -1;
}  if (*root == NULL) {
      *root=(avlNode*)malloc(sizeof(avlNode));
      if (*root==NULL){
         return -1;
}     (*root)->val = val;
      return 1;
}  if (val<(*root)->val){
      return(add_avl(&(*root)->l,val));
}  else if(val>(*root)->val){
      return(add_avl(&(*root)->r,val));
}}

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
