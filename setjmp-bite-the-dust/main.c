#include <stdio.h>
#include <setjmp.h>

jmp_buf b;

void foo() {
	longjmp(b,0x42);
}

int main() {
	if (setjmp(b)) {
		puts("bite the dust!");
	} else {
		fputs("hello, ",stdout);
		foo();
	}
}
