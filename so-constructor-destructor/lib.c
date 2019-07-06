#include <stdio.h>

void __attribute__((constructor)) init_function(void){
	puts("in init_function!");
}

void __attribute__((destructor)) fini_function(void) {
	puts("in fini_function!");
}

int foo() {
	return 42;
}
