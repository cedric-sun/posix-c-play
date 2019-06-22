#include <stdlib.h>
#include <stdio.h>

#define N 10
#define LF '\n'

void print_array_2d(int **array_2d) {
	for (int i =0;i<N;i++) {
		printf("%18p:",array_2d[i]);
		for (int j =0;j<N;j++) {
			printf("%4d",array_2d[i][j]);
		}
		putchar(LF);
	}
}

void init_array_2d(int **array_2d) {
	unsigned int cnt = 0;
	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			array_2d[i][j] = cnt++;
		}
	}
}

void way0() {
	int **array_2d = (int**)malloc(N * sizeof(int*));
	for (size_t i = 0;i<N;i++) {
		array_2d[i] = (int*)malloc(N * sizeof(int));
	}
	init_array_2d(array_2d);
	print_array_2d(array_2d);
}

void way1() {
	int (*array_2d)[N] = malloc(N * sizeof *array_2d);
	init_array_2d((int**)array_2d);
	print_array_2d((int**)array_2d);
}

int main() {
	way1();
}
