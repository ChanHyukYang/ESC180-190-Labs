#include <stdio.h>
#include <stdlib.h>
struct avlNode {
   int balance; /* -1 Left, 0 balanced, +1 Right */
   int val;
   struct avlNode *l;
   struct avlNode *r;
};
typedef struct avlNode avlNode;

struct bstNode {
   int val;
   struct bstNode *l;
   struct bstNode *r;
   };
   typedef struct bstNode bstNode;

struct qNode {
   avlNode *pval;
   struct qNode *nxt;
};
typedef struct qNode qNode;

struct qNodeb {
   bstNode *bval;
   struct qNodeb *nxt;
};
typedef struct qNodeb qNodeb;

int enqueue(qNodeb **root, bstNode *node){
   if(root==NULL){
      return -1;
}  if(*root==NULL){
      (*root) = (qNodeb*)malloc(sizeof(qNodeb));
      (*root)->bval = node;
      (*root)->nxt = NULL;
      return 0;
}  else{
      return(enqueue(&(*root)->nxt, node));
}}
bstNode dequeue(qNodeb **root){
   qNodeb *r = (*root)->nxt;
   bstNode *temp = (*root)->bval;
   free(*root);
   *root = r;
   return *temp;
}
       
int add_bst(bstNode **root,int val) {
   if (root == NULL){
      return -1;
}  if (*root == NULL) {
      *root=(bstNode*)malloc(sizeof(bstNode));
      if (*root==NULL){
         return -1;
}     (*root)->val = val;
      return 1;
}  if (val<(*root)->val){
      return(add_bst(&(*root)->l,val));
}  else if(val>(*root)->val){
      return(add_bst(&(*root)->r,val));
}}  

int printTreeInOrder(bstNode *root){
   if (root == NULL){
      return -1;
}  if ((root)->l != NULL){
      (printTreeInOrder((root)->l));
}  printf("%d\n",(root)->val);
   if ((root)->r != NULL){
      (printTreeInOrder((root)->r));
}  return 1;
}

int printLevelOrder(bstNode *root){
   qNodeb *u = NULL;
   bstNode tem;
   if (root == NULL){
      return -1;
}  enqueue(&u,root);
   while(1==1){
      tem = dequeue(&u);
      printf("%d", tem.val);
      enqueue(&u,tem.l);
      enqueue(&u,tem.r);
      if(u==NULL){
         break;
}}  
}

int main(void) {
bstNode *root=NULL;
add_bst(&root,5);
add_bst(&root,3);
add_bst(&root,1);
add_bst(&root,4);
add_bst(&root,7);
add_bst(&root,6);
add_bst(&root,8);
printTreeInOrder(root);
printLevelOrder(root);
return 0;
}       
