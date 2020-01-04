#include <stdio.h>
Int main(void){
    int *b;
    int **a;
    int c = 10;
    int d = 20;
    int q = 10;
    b = &c;
    a = &b;
    q = **a;
    *b = 0;
    d = c + 100;
    q = q + 100;
    /* a points to b
 *        b points to c
 *               c = 0
 *                      d = 100
 *                             q = 130 */
    return 0;
}

