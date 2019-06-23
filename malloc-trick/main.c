#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int attr0;
	double attr1;
	char *attr2;
} mytype;

int main() {
	mytype *p0 = malloc(sizeof(mytype));
	
	/* in case you misspell mytype */
	mytype *p1 = malloc(sizeof(*p1));

#define NROW 10
#define NCOL 10
	/* also useful when the pointed type is complicated, instead of writing this:*/
	int (*array_2d)[NCOL] = malloc(NROW*sizeof(int[NCOL]));
	/* you could write: */
	int (*array_2d_trick)[NCOL] = malloc(10*sizeof(*array_2d_trick));

}
