#include <stdlib.h>
#include <stdio.h>

int main() {
	/* A pointer to constant value.
	 * you can't modify the pointed thing via the pointer
	 */
	const char *p0 = "string in .data section?";

	/*
	 * The pointer itself is const, you can't store other
	 * address in it after its first initialization
	 */
	char *const p1 = malloc(256);

	
	/* A pointer to a function.
	 * The function take no argument and return nothing.
	 */
	void (*func)() = NULL;

	/*
	 * A more complex example, but works in the obvious way.
	 */
	char *(*str_func)(const char *arg0, char *const arg1, const char *const arg2) = NULL;

	printf("%p\n",func);
	printf("%p\n",str_func);
}
