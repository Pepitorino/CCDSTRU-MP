#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "magic.h"

void
init_pegs(int pegs[][PEGS])
{
	int i;
	for (i=0;i<PEGS;i++)
	{
		pegs[0][i]=i+1;
		pegs[1][i]=0;
	}
}
