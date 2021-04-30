#include <stdio.h>
#include <stdlib.h>

// peculiar signature
// return a pointer to an int array of size 3, i.e. double pointer
//
// Dereferencing the returned pointer once, we get the address of the
// first element of an int array of size 3
int (*foo(void))[3] {
    // 4 row x 3 column
    int(*ret)[3] = malloc(sizeof(int) * 3 * 4);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            ret[i][j] = i + j;
    return ret;
}

int main() {
    int(*p)[3] = foo();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++)
            printf("%d ", p[i][j]);
        putchar('\n');
    }
    free(p);
    return 0;
}
