#include <stdio.h>
#include <stdlib.h>
struct bstNode {
   int val;
   struct bstNode *l;
   struct bstNode *r;
   };
   typedef struct bstNode bstNode;

int add_bst(bstNode **root, int val);
int printTreeInOrder(bstNode *root);
int printLevelOrder(bstNode *root);

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
   if (root == NULL){
      return -1;
}  printLevelOrder((root)->l);
   printf("%d\n",(root->val));
   printLevelOrder((root)->r);
   return 0;
}

int main(void) {
bstNode *root=NULL;
int value = 0;
while(scanf("%d", &value) != EOF){
   add_bst(&root,value);
}
printTreeInOrder(root);
return 0;
}
