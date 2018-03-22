#include <stdio.h>
#include "stdlib.h"
#include "string.h"
int main() {
	char *name = (char*)malloc(strlen("Susan") + 1);
	strcpy(name, "Susan");
	while (*name != '\0') {
		printf("%c", *name);
		name++;
	}


	free(name);//When free is writing, the pogram does not work.Because the pointer name is not the point to the start.
	//If we can get the start address, we can free the pointer successfully! :)


	/*name--;
		name--;
		name--;
		name--;
		name--;
		free(name);*/
	return 0;
}
