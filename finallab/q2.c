#include <stdio.h>
#include <stdlib.h>

struct blah {
    int id;
    int val[4];
    char label[4];
    int*data;
};

int main(void) {
    printf("%d",sizeof(struct blah));
    return 0;
}
/*32*/

