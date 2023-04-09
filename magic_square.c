#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int board[3][3]={{0,0,0},{0,0,0},{0,0,0}};
int pegs[9][2]={{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0}};
bool ok = false;
bool next = false;
bool turn = true;
bool over = false;
int W[6];

void
printBoard()
{
	system("cls");
	printf("  1 2 3\n");
	printf("1 %d %d %d\n", board[0][0], board[0][1], board[0][2]);
	printf("2 %d %d %d\n", board[1][0], board[1][1], board[1][2]);
	printf("3 %d %d %d\n", board[2][0], board[2][1], board[2][2]);

}

void 
pegBoardChoice()
{
    int x, y,
        choice;
    int i,j,k;

    // peg choice
    do
    {
        printf("\nChoose Peg to Move (1-9): ");
        scanf(" %d", &choice);
        fflush(stdin);
        if (pegs[choice-1][1]) printf("Peg already in use");	
    } while (pegs[choice-1][1]!= 0);

    pegs[choice-1][1] = 1;

    // board position choice
    do
    {
        printf("\nWhere would you like to move (x,y): ");
        scanf("\n%d,%d", &x, &y);
        if (board[y-1][x-1] != 0) printf("There is a peg already placed.");
    } while (x<1||x>3||y<1||y>3 || board[y-1][x-1] != 0);
    
    board[y-1][x-1]=pegs[choice-1][0];

    for(i=0;i<6;i++) W[i]=0;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            W[i]=board[i][j]; //Row-Major Order
            W[i+3]=board[j][i]; //Column-Major Order
        }
    }    
}

void
gameOver(bool* over)
{
    int i, j;
    int counter=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if (board[i][j]==0) j=4;
        }
        if (j==3)
        {
            if (W[i]<15) 
            {
                *over=!(*over);
                return;
            }
            else counter++;
        }
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if (board[j][i]==0) j=4;
        }
        if (j==3)
        {
            if (W[i+3]<15)
            {
                *over=!(*over);
                return;
            }
            else counter++;
        }
    }

    if (counter>=3)
    {
        
    }

    turn=!turn;
}

int
main()
{
	int i;
	
	printf("%15s\n", "=================");
	printf("%15s\n", "MAGIC SQUARES");
	printf("%15s\n", "=================");

	do
	{
		printBoard();
		if (turn) printf("\nPlayer A move");
		else printf("\nPlayer B move");

        pegBoardChoice();
        gameOver(&over);
		
	} while (!over);
	

	return 0;
}