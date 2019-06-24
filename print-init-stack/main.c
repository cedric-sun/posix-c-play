#include <stdio.h>
#include <elf.h>

/* TODO: handle x86-64 */
int main(int argc, char* argv[]) {
	int *p = (int *)argv;
	printf("Argument count:%d\n", *(p-1));

	int i;
	for (i=0;i<*(p-1);++i) {
		printf("Argument %d: %s\n",i, *(p+i));
	}

	p+=i;

	p++;

	printf("Env:\n");
	while (*p) {
		printf("%s\n",*p);
		p++;
	}
	
	p++;

	printf("Aux Vec:\n");

	Elf32_auxv_t *aux = (Elf32_auxv_t *)p;

	while (aux -> a_type != AT_NULL) {
		printf("Type: %02d Value: %x\n", aux->a_type, aux->a_un.a_val);
		aux++;
	}
	return 0;
}
