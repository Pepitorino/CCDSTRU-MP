#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int board[3][3]={{0,0,0},{0,0,0},{0,0,0}};
int pegs[9][2]={{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0}};
bool ok = false;
bool next = false;
bool turn = true;
int One;
int Two;
int Three;
int Four;
int Five;
int Six;

void
printBoard()
{

	printf("  1 2 3\n");
	printf("1 %d %d %d\n", board[0][0], board[0][1], board[0][2]);
	printf("2 %d %d %d\n", board[1][0], board[1][1], board[1][2]);
	printf("3 %d %d %d\n", board[2][0], board[2][1], board[2][2]);

}

int
main()
{
	int i;
	int x,y;
	int choice;
	printf("%15s\n", "=================");
	printf("%15s\n", "MAGIC SQUARES");
	printf("%15s\n", "=================");

	do
	{
		printBoard();

		if (next) printf("\nPlayer B move");
		else printf("\nPlayer A move");

		do
		{
			printf("\nChoose Peg to Move (1-9): ");
			scanf(" %d", &choice);
			fflush(stdin);
			if (pegs[choice-1][1]) printf("Peg already in use");	
		} while (pegs[choice-1][1]!=0);
		
		pegs[choice-1][1]=1;

		i=0;
		do
		{
			if (i>0) printf("\nINVALID\n");
			printf("\nWhere would you like to move (x,y): ");
			scanf("\n%d,%d", &x, &y);
			fflush(stdin);
			if (board[y-1][x-1]>0) printf("\nSquare already occupied\n");
			i++;
		} while (x<1||x>3||y<1||y>3||board[y-1][x-1]>0);
		
		board[y-1][x-1]=pegs[choice-1][0];
		next=!next;
		turn=!turn;

		One = board[0][0] + board[0][1] + board[0][2];
		Two = board[1][0] + board[1][1] + board[1][2];
		Three = board[2][0] + board[2][1] + board[2][2];
		Four = board[0][0] + board[1][0] + board[2][0];
		Five = board[0][1] + board[1][1] + board[2][1];
		Six = board[0][2] + board[1][2] + board[2][2];

		printf("\nOne: %d\nTwo: %d\nThree: %d\nFour: %d\nFive: %d\nSix: %d\n", One, Two, Three, Four, Five, Six);
		
	} while (1);
	

	return 0;
}
