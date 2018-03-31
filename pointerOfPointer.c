#include <stdio.h>
#include "stdlib.h"
#include "string.h"
//Why? pp-p = 32 in my linux
int main() {

	int **p;
	p = malloc(sizeof(int) * 3);
	p[0] = malloc(sizeof(int) * 10);
	p[1] = malloc(sizeof(int) * 10);
	p[2] = malloc(sizeof(int) * 10);
	p[0][0] = 1;
	p[2][0] = 1;


	free(p);
	free(*p);
	return 0;
}