#include <stdio.h>
#include "magic.h"
#include "functions.c"

int
main()
{
	int pegs[2][PEGS];
	board board;
	
	init_pegs(pegs);
	
	printf("%15s\n", "=================");
	printf("%15s\n", "MAGIC SQUARES");
	printf("%15s\n", "=================");

	return 0;
}
