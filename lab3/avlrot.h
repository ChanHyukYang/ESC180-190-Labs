struct avlNode {
   int balance; /* -1 Left, 0 balanced, +1 Right */
   int val;
   struct avlNode *l;
   struct avlNode *r;
};
struct qNode {
   struct avlNode *pval;
   struct qNode *nxt;
};
typedef struct avlNode avlNode;
typedef struct qNode qNode;
int isAVL(avlNode **root);
int rotate(avlNode **root, unsigned int Left0_Right1);
int dblrotate(avlNode **root,unsigned int MajLMinR0_MajRMinL1);
int isavlhelper(avlNode **root);
int add_avl(avlNode **root,int val);
