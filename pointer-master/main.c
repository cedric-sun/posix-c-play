#include <stdlib.h>
#include <stdio.h>

int main() {

/* ------------------ Pointer and const ------------------*/

	/* Pointer to const.
	 * A pointer to constant value.
	 * you can't modify the pointed thing via the pointer.
	 */
	const char *p0 = "string in .rodata section";

	/* Const pointer.
	 * The pointer itself is const, you can't store other
	 * address in it after its first initialization
	 */
	char *const p1 = malloc(256);

	/*  Const pointer again, but pointing to a pointer. */
	char **const p2 = malloc(8 * sizeof(char*));

/* ------------------ Pointer and Array ------------------*/

	/* The pointed value has type int[NCOL], meaning
	 * that pointer arithmetic on arr_p will use
	 * sizeof(int) * NCOL as a unit.
	 */
#define NROW 10
#define NCOL 10
	int (*arr_p)[NCOL] = malloc(NROW * sizeof *arr_p);


#define N 10
	/* Array of pointers.
	 *
	 * Note that if this statement appears inside a function,
	 * the array will be allocated right on stack.
	 */
	int *ptr_arr[N];

/* ------------------ Function pointer ------------------*/
	
	/* A pointer to a function.
	 * 
	 * The function take no argument and return nothing.
	 */
	void (*func)() = NULL;

	/*
	 * A more complex example, but works in the obvious way.
	 */
	char *(*str_func)(const char *arg0, char *const arg1, const char *const arg2) = NULL;
}
