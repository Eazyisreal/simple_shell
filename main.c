
// Import header file
#include "main.h"

int main (int argc, char **argv){
	char *prompt = "(shell) $ ";
	char *lineptr;
	size_t n = 0;

	(void) argc, (void) argv;

	printf("%s", prompt);
	getline(&lineptr, &n, stdin);
	printf("%s\n", lineptr);

	free(lineptr);
	return (0);
}


