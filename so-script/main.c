#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc !=2 ){
		fprintf(stderr,"Usage: %s FLOAT_NUMBER\n",argv[0]);
		return -1;
	}
	double value = atof(argv[1]);
	printf("%f\n",sqrt(value));
}
