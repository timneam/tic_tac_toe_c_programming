// C program to find the next best move for ai_player
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../tictactoe.h"

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

// add counter to check number of times minimax function is called
int counter1;
// Create a structure for move object 
// where the return value should give us row and col
struct Move
{
	int row, col;
};

// Create x for player and o for ai_player
char player = 'X', ai_player = 'O';

// This function is to check if there are empty spots in the board
bool empty_spots(char board_spots[3][3])
{
	// for every row
	for (int i = 0; i<3; i++)
		// for every column
		for (int j = 0; j<3; j++)
			// if there are empty spots
			if (board_spots[i][j]==' ')
				// return true
				return true;
	// else return false
	return false;
}

// This is the check for win function
int check_win(char b[3][3])
{
	// Checking for Rows for X or O victory.
	for (int row = 0; row<3; row++)
	{
		// if there is a row that column 0 == 1 and 1 == 2
		if (b[row][0]==b[row][1] &&
			b[row][1]==b[row][2])
		{	
			// if row 0 symbol represents ai_player which is O
			if (b[row][0]==ai_player)
				// return +10 for ai_player
				return +10;
			// else if row 0 symbol represents player which is X
			else if (b[row][0]==player)
				// return -10 for ai_player
				return -10;
		}
	}

	// Checking for Columns for X or O victory.
	for (int col = 0; col<3; col++)
	{
		// if there is a row that column 0 == 1 and 1 == 2
		if (b[0][col]==b[1][col] &&
			b[1][col]==b[2][col])
		{
			// if row 0 symbol represents ai_player which is O
			if (b[0][col]==ai_player)
				// return +10 for ai_player
				return +10;
			// else if row 0 symbol represents player which is X
			else if (b[0][col]==player)
				// return -10 for ai_player
				return -10;
		}
	}

	// Checking for Diagonals for X or O victory.
	// if row 0 col 0 is == row 1 col 1 && 
	// row 1 col 1 is == row 2 col 2
	if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
	{
		// if row 0 col 0 symbol represents ai_player which is O		
		if (b[0][0]==ai_player)
			// return +10 for ai_player
			return +10;
		// else if row 0 col 0 symbol represents player which is X
		else if (b[0][0]==player)
			// return -10 for ai_player
			return -10;
	}

	// Checking for Diagonals for X or O victory.
	// if row 0 col 2 is == row 1 col 1 && 
	// row 1 col 1 is == row 2 col 0
	if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
	{
		// if row 0 col 2 symbol represents ai_player which is O		
		if (b[0][2]==ai_player)
			// return -10 for ai_player
			return +10;
		// else if row 0 col 2 symbol represents player which is X
		else if (b[0][2]==player)
			// return -10 for ai_player
			return -10;
	}

	// Else if none of them have won then return 0
	return 0;
}

// This is the minimax function. It considers all
// the possible ways the game can go and returns
// the value of the board
int minimax(char board_spots[3][3], int alpha, int beta, int depth, bool isMaxTurn)
{
	// counts everytime minimax is called
	counter1++;
	// create an int variable called score
	// give the score if there is a win
	int score = check_win(board_spots);

	// If Maximizer has won the game return his/her score
	if (score == 10)
		return score;
	// If Minimizer has won the game return his/her score
	if (score == -10)
		return score;

	// If there are no more moves and no winner then
	// it is a tie
	if (empty_spots(board_spots)==false)
		return 0;

	// If this maximizer's move
	if (isMaxTurn)
	{
		int eval;
		int best = -100000;

		// Check for every row
		for (int i = 0; i<3; i++)
		{
			// check for every col
			for (int j = 0; j<3; j++)
			{
				// Check if spot is empty
				if (board_spots[i][j]==' ')
				{
					// Put X into the spot
					board_spots[i][j] = ai_player;

					// Call minimax recursively and choose the highest value
					eval = minimax(board_spots, alpha, beta, depth+1, !isMaxTurn);
					best = max(best, eval);

					// Undo the move
					board_spots[i][j] = ' ';

					// alpha-beta pruning
					// alpha will be the best score maximizer will get
					alpha = max(alpha, eval);
					// check if score is the best score
					if(alpha >= beta){
						// since found, no need to continue with other options
						break;
					}
				}
			}
		}
		// return the best value for maximizer turn
		// where 10 is the score for the best spot for maximizer
		return best;
	}

	// If this minimizer's move
	else
	{
		int eval;
		int best = 100000;

		// For every row
		for (int i = 0; i<3; i++)
		{
			// for every col
			for (int j = 0; j<3; j++)
			{
				// Check if spot is empty
				if (board_spots[i][j]==' ')
				{
					// Put O into the spot
					board_spots[i][j] = player;

					// Call minimax recursively and choose the lowest value
					eval = minimax(board_spots, alpha, beta,  depth+1, !isMaxTurn);
					best = min(best, eval);

					// Undo the move
					board_spots[i][j] = ' ';

					// alpha-beta pruning
					// beta is best score minimizer will get
					beta = min(beta, eval);
					// check if score is best score
					if(beta <= alpha){
						// since found, no need to continue with other options
						break;
					}
				}
			}
		}
		// return the best value for minimizer turn
		// where 10 is the score for the best spot for minimizer
		return best;
	}
}

// This will return the best possible move for the ai_player who is O
// create a struct object called find best move so that it will return row and col
struct Move findNextBestMove(char board_spots[3][3])
{
	// alpha set to worst score for maximizer
	int alpha = -100000;
	// beta set to worst score for minimizer
	int beta = 100000;
	// Create a value for best val of -1000
	int bestValue = -1000;
	// Create a structure Move called best move
	struct Move bestMove;
	// let the row be -1
	bestMove.row = -1;
	// let the col be -1
	bestMove.col = -1;

	// For every row
	for (int i = 0; i<3; i++)
	{
		// for every col
		for (int j = 0; j<3; j++)
		{
			// Check if spot is empty
			if (board_spots[i][j]==' ')
			{
				// Make the move for ai_player which is O 
				board_spots[i][j] = ai_player;

				// call the minimax function for next move.
				int currentMoveValue = minimax(board_spots, alpha, beta, 0, false);

				// Undo the move
				board_spots[i][j] = ' ';

				// If the value of the current move is
				// higher than the best value, then update
				// best move value

				// if moveVal is higher than BestVal
				if (currentMoveValue > bestValue)
				{
					// set the bestMove.row 
					// to the current move Val row which is i
					bestMove.row = i;
					// set the Best.col 
					// to the current move Val col which is j
					bestMove.col = j;
					// let the new value of best val 
					// to be the current move val
					bestValue = currentMoveValue;
				}
			}
		}
	}
	// print the value of the best move after computing minimax function
	//printf("The value of the best Move is : %d\n\n", bestValue);
	// print number of times minimax function is called; showing memory efficiency
	printf("Number of minimax tries: %i \n", counter1);
	// return the new best move
	return bestMove;
}

/*
// Mai_playern function
int mai_playern()
{
	// create a board of 2d array of 3x3
	char board_spots[3][3] =
	{
		// use static board to check the minimax function 
		{ 'X', 'O', 'O' },
		{ 'X', 'X', 'O' },
		{ ' ', ' ', ' ' }
	};

	// The structure bestMove 
	// should get the bestMove of the new spot when calling the find next best move function
	// inside this find next best move function, it will call the minimax function 
	// This minimax function will return the best spot for the ai_player
	struct Move bestMove = findNextBestMove(board_spots);

	// Print the best move is
	printf("The Best Move is :\n");
	// printt the row and col of the new best move
	printf("ROW: %d COL: %d\n\n", bestMove.row, bestMove.col );
	return 0;
}
*/