#include <stdlib.h>
#include <stdio.h>

#define LF '\n'

#define NCOL 10
#define NROW 10
/*
 * 	<-----------NCOL----------->
 * 	^
 * 	|
 * 	|
 * 	|
 * 	|
 *     NROW
 * 	|
 * 	|
 * 	|
 * 	|
 * 	v
 */

/* Wrong. Allocated memory is not contiguous. */
void way0() {
	int **array_2d = malloc(NROW * sizeof(int*));
	for (size_t i = 0;i<NROW;i++)
		array_2d[i] = malloc(NCOL * sizeof(int));

	unsigned int cnt = 0;
	for (int i=0;i<NROW;i++) for (int j=0;j<NCOL;j++) array_2d[i][j] = cnt++;

	for (int i =0;i<NROW;i++) {
		printf("%18p:",array_2d[i]);
		for (int j =0;j<NCOL;j++) printf("%4d",array_2d[i][j]);
		putchar(LF);
	}
}

/* Contiguous memory. The right thing to do.
 * 
 * DO NOT let the array_2d decay to pointer: 
 * type info int[NCOL] is important for pointer arithmetic.
 */
void way1() {
	int (*array_2d)[NCOL] = malloc(NROW * sizeof *array_2d);

	unsigned int cnt = 0;
	for (int i=0;i<NROW;i++) for (int j=0;j<NCOL;j++) array_2d[i][j] = cnt++;

	for (int i=0;i<NROW;i++) {
		printf("%18p: ",array_2d[i]);
		for (int j =0;j<NCOL;j++) printf("%4d",array_2d[i][j]);
		putchar(LF);
	}
}

int main() {
	way1();
}
