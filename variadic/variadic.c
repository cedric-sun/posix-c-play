#include <stdio.h>
#include <stdarg.h>

/* at least 1 named parameter before ... */
void my_variadic_func(const int gao, ...) {
	va_list args;
	va_start(args,fmt);
}

int main() {
	my_variadic_func(1,2,3);
}
