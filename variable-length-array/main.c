#include <stddef.h>

#define N 42

void common() {
	int (*p)[N] = NULL;
}

void var(int n) {
	int (*p)[n] = NULL;
}

int main() {
	common();
	var(123);
}
