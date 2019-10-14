/* ENGGEN131 Project - C Project - 2018 */
/* Connect Four */

#include "connect4.h"

/*
XinMing Yang 144124039
This is the file that you will be submitting for marking
Complete the definitions of the functions in this file
DO NOT REMOVE ANY FUNCTION DEFINITIONS - they all must be present when you submit this file
*/

/*HELPER FUNCTIONS START HERE*/

// The 'shiftLeft' function is a helper function which deletes the character at the array index and
// shifts the rest of the characters to the left one index
void shiftLeft(char *name,int index) 
{
	while (name[index] != '\0') {
		name[index] = name[index + 1];
		index++;
	}

}

// The 'winOrLose' function takes an array and determine whether or not there is a number appearing
// 4 times in a row (excluding 0) and returns '0' if it does not appear or returns '1' if there are 
// 4 in a row. This is similar to the 'FourInARow' function.
int winOrLose(int values[], int length, int player)
{
	//  initialise variables
	int i = 0;

	// compare each value within the array (up to but not including the last 3)
	// with the next 3 variables in the array
	while (i < length - 3) {
			if ((values[i] == player)&&(values[i] == values[i + 1]) && (values[i] == values[i + 2]) && (values[i] == values[i + 3])){
					return 1;
				}
			// reset count if numbers don't match and compare the next number in the array 
			else {
				i++;
			}
		}
	
	// when there is no 4 in a row, return 0
	return 0;
}

/*MAIN FUNCTIONS START HERE*/

// The 'SecondPlacePrize' function takes 3 integers (prize1,prize2,prize3) as input and return the
// the second largest integer
int SecondPlacePrize(int prize1, int prize2, int prize3)
{
	// Store the 3 integers in an array
	int values[MAX_SIZE] = { 0 };
	values[0] = prize1;
	values[1] = prize2;
	values[2] = prize3;

	
	// Arrange the array from largest to smallest using the "bubble sort" method
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 2; i++) {
			if (values[i] < values[i + 1]) {
				int temp = values[i];
				values[i] = values[i + 1];
				values[i + 1] = temp;
			}
		}
	}

	// return middle value
	return values[1];
}


// The 'FourInARow' function takes an array and determine whether or not there is a number appearing
// 4 times in a row and returns '-1' if it does not appear or return the index of the first variable 
// of occurance
int FourInARow(int values[], int length)
{
	//  initialise variables
	int i = 0;

	// compare each value within the array (up to but not including the last 3)
	// with the next 3 variables in the array
	while (i < length - 3) {
		if ((values[i] == values[i + 1]) && (values[i] == values[i + 2]) && (values[i] == values[i + 3])) {
			// return index of first number in the sequence
			return i;
		}
		// reset count if numbers don't match and compare the next number in the array 
		else {
			i++;
		}
	}
	// when there is no 4 in a row, return -1
	return -1;
}

int BinaryToDecimal(int binary)
{
	// initialise variables
	int bitToConvert;
	int remainder = binary;
	int base = 1; 
	int sum = 0;
	
	// when remainder is not 0, perform task
	while (remainder != 0) {
		// get least significant bit
		bitToConvert = remainder % 10;
		// get rid of last number of the remainder
		remainder = remainder / 10;
		// add up the totals of the values of each bit
		sum += bitToConvert * base;
		// incrase the base for next loop around
base = 2 * base;
	}

	// return the total 
	return sum;

}

double MedianAbility(double abilities[], int length)
{
	// Arrange the array from largest to smallest using the "bubble sort" method
	for (int j = 0; j < length; j++) {
		for (int i = 0; i < length; i++) {
			if (abilities[i] < abilities[i + 1]) {
				double temp = abilities[i];
				abilities[i] = abilities[i + 1];
				abilities[i + 1] = temp;
			}
		}
	}

	// determine if length of array is even or not
	if (length % 2 == 0) {
		// get the midpoint of the two middle values and return it
		int index = length / 2;
		return abilities[index] / 2 + abilities[index - 1] / 2;
	}
	else {
		// get the median values and return it
		int index = length / 2;
		return abilities[index];
	}
}

// The function 'RemoveSpaces' takes a character string as the input and deletes all but one space if 
// there are more than 2 spaces in a row
void RemoveSpaces(char *name)
{
	int i = 0;
	while (name[i] != '\0') {
		// when there are 2 spaces in a row, call on the 'shiftLeft' function to delete the character
		// at index i until only 1 space i that region remains
		while ((name[i] == ' ') && (name[i + 1] == ' ')) {
			shiftLeft(name, i);
		}
		i++;
	}

}


// The function 'InitialliseBoard' takes a 2D array of -1 and an integer to which the function sets
// the board size to
void InitialiseBoard(int board[MAX_SIZE][MAX_SIZE], int size)
{
	// initialise variable(s)
	int midpoint = size / 2;

	// form the board's empty spaces
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = 0;
		}
	}

	// add the fixed pieces
	if (size % 2 == 1) {
		board[midpoint][midpoint] = 3;
	}
	else {
		board[midpoint][midpoint] = 3;
		board[midpoint][midpoint - 1] = 3;
		board[midpoint - 1][midpoint] = 3;
		board[midpoint - 1][midpoint - 1] = 3;
	}
}


// The function 'AddMoveToBoard' determines where the token is placed 
void AddMoveToBoard(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player, int *lastRow, int *lastCol)
{
	// initialise variables
	int mark;
	int index = size - 1;
	int i = 1;


	// determine which player it is and match the token
	if (player == 1) {
		mark = 1;
	}
	else {
		mark = 2;
	}

	// Starting from top to bottom, determine which first position is not a 0 
	if (side == 'N') {
		if (board[0][move] != 0) {
			*lastRow = -1;
			*lastCol = -1;
		}
		else {
			while ((board[i][move] == 0) && (i < size)) {
				i++;
			}
			*lastRow = i - 1;
			*lastCol = move;
		}
	}


	// Starting from right to left, determine which first position is not a 0 
	if (side == 'E') {
		if (board[move][index] != 0) {
			*lastRow = -1;
			*lastCol = -1;
		}
		else {
			while ((board[move][size - i-1] == 0) && (i < size)) {
				i++;
			}
			*lastRow = move;
			*lastCol = size - i;
		}
	}


	// Starting from bottom to top, determine which first position is not a 0 
	if (side == 'S') {
		if (board[index][move] != 0) {
			*lastRow = -1;
			*lastCol = -1;
		}
		else {
			while ((board[size - i-1][move] == 0) && (i < size)) {
				i++;
			}
			*lastRow = size - i;
			*lastCol = move;
		}
	}


	// Starting from left to right, determine which first position is not a 0 
	if (side == 'W') {
		if (board[move][0] != 0) {
			*lastRow = -1;
			*lastCol = -1;
		}
		else {
			while ((board[move][i] == 0) && (i < size)) {
				i++;
			}
			*lastRow = move;
			*lastCol = i - 1;
		}
	}

	if ((*lastRow != -1) || (*lastCol != -1)) {
		board[*lastRow][*lastCol] = mark;
	}
		
}

// The function 'CheckGameOver' determines whether or not a game has been won and returns 0 if no-one has
// won or the respective player number
int CheckGameOver(int board[MAX_SIZE][MAX_SIZE], int size, int player, int row, int col)
{
	// initialise variables
	int count0s = 0;
	int temprow = row;
	int tempcol = col;
	int temp;
	int length;
	int verticalArray[MAX_SIZE];
	int horizontalArray[MAX_SIZE];
	int DiagArray1[MAX_SIZE];
	int DiagArray2[MAX_SIZE];

	if ((row == -1) && (col == -1)) {
		return 0;
	}

	// check if there are any moves avaliable, if not return player
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == 0) {
				count0s++;
			}
		}
	}
	if (count0s == 0) {
		return player;
	}

	
	// check if player has won vertically
	while (temprow != 0) {
		temprow--;
	}
	// store column in array
	for (int j = 0; j < size; j++) {
		 verticalArray[j] =  board[j][col] ;
	}
	// check for winning condition
	if ((winOrLose(verticalArray, size,player)) == 1) {
		return player;
	}
	// reset temprow
	temprow = row;


	// check if player has won horizontally
	while (tempcol != 0) {
		tempcol--;
	}
	// store row in array
	for (int j = 0; j < size; j++) {
		horizontalArray[j] = board[row][j];
	}
	// check for winning condition
	if ((winOrLose(horizontalArray, size,player)) ==1) {
		return player;
	}
	// reset tempcol
	tempcol = col;
	

	// check if player has won diagonally (top left to bottom right)
	while ((tempcol >= 1) && (temprow >= 1)) {
		tempcol--;
		temprow--;
	}
	// determine length of diagonal array
	if (tempcol > temprow) {
		temp = tempcol;
	} else if (temprow > tempcol) {
		temp =temprow;
	} else {
		temp = 0;
	}
	length = size - temp;
	//store diagonal in array
	for (int j = 0; j <= length; j++) {
		DiagArray1[j] = board[temprow + j][tempcol + j];
	} 
	// check for winning condition
	if ((winOrLose(DiagArray1, length,player)) == 1) {
		return player;
	}
	// reset temprow and tempcol
	temprow = row;
	tempcol = col;


	// check if player has won diagonally (bottom left to top right)
	while ((tempcol >= 1) && (temprow < size-2)) {
		tempcol--;
		temprow++;
	}
	// determine length of diagonal array
	length = 1 + abs(tempcol - temprow);
	// store diagonal in array
	for (int j = 0; j <= length; j++) {
		DiagArray2[j] = board[temprow - j][tempcol + j];
	}
	// check for winning condition
	if ((winOrLose(DiagArray2, length,player)) == 1) {
		return player;
	}

	// if not conidtions are met, return 0
	return 0;
}

void GetDisplayBoardString(int board[MAX_SIZE][MAX_SIZE], int size, char *boardString)
{
	// initialise veriables
	int total_length;
	int length = size + 4;
	int width = size + 5;


	// establsih string total length exlcuding '\0'
	total_length = (size + 4)*(size + 5);

	// underlay whole boardstring with '-'
	for (int i = 0; i < total_length; i++) {
		boardString[i] = '-';
	}

	// set up new lines 
	for (int i = 0; i < length; i++) {
		boardString[(i*width) + width - 1] = '\n';
	}


	// end the string with '\0'
	boardString[total_length] = '\0';

	// set NESW
	for (int i = 0; i < size; i++) {
		boardString[i + 2] = 'N';
		boardString[(2 * width) + (i*width) + (width - 2)] = 'E';
		boardString[(length - 1)*width + 2 + i] = 'S';
		boardString[(2 * width) + (i*width)] = 'W';

		// set numbers 

		boardString[width + 2 + i] = (char) (48+i);
		boardString[(2 * width) + (i*width) + (width - 2) - 1] = (char) (48 + i);
		boardString[(length - 2)*width + 2 + i] = (char) (48 + i);
		boardString[(2 * width) + (i*width) + 1] = (char) (48  + i);
	}

	// set up board
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			if (board[i][j] == 0) {
				boardString[j + (width * 2) + 2 + (width*i)] = '.';
			}
			else if (board[i][j] == 1) {
				boardString[j + (width * 2) + 2 + (width*i)] = 'X';
			} 
			else if (board[i][j] == 2) {
				boardString[j + (width * 2) + 2 + (width*i)] = 'O';
			}
			else if ((board[i][j] == 3)) {
				boardString[j + (width * 2) + 2 + (width*i)] = '#';
			}

		}
	}



}

void GetMoveBot1(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	int tempboard[MAX_SIZE][MAX_SIZE];
	char direction='0';
	int lastRow = 0;
	int lastCol = 0;
	int validMove = 0;

	// duplicate board
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			tempboard[i][j] = board[i][j];
		}
	}

	// check for winning move by slotting token at every position 
	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			// check if any position from N will make the bot win 
			direction = 'N';
			if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) == 0) {
				for (int j = 0; j < size; j++) {
					// place a token on the dummy board
					AddMoveToBoard(tempboard, size, direction, j, player, &lastRow, &lastCol);
					if ((lastRow == -1) || (lastCol == -1)) {
						// do nothing and go onto the next iteration
					}
					else {
						// remove token if it does not win
						if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) == 0) {
							tempboard[lastRow][lastCol] = 0;
						}
						else if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) != 0) {
							*side = direction;
							*move = j;
							return;

						}
					}
				}
			}
		}


		else if (i == 1) {
			// check if any position from E will make the bot win 
			direction = 'E';
			if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) == 0) {
				for (int j = 0; j < size; j++) {
					// place a token on the dummy board
					AddMoveToBoard(tempboard, size, direction, j, player, &lastRow, &lastCol);
					if ((lastRow == -1) || (lastCol == -1)) {
						// do nothing and go onto the next iteration
					}
					else {
						// remove token if it does not win
						if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) == 0) {
							tempboard[lastRow][lastCol] = 0;
						}
						else if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) != 0) {
							*side = direction;
							*move = j;
							return;

						}
					}
				}
			}
		}


		else if (i == 2) {
			// check if any position from S will make the bot win 
			direction = 'S';
			if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) == 0) {
				for (int j = 0; j < size; j++) {
					// place a token on the dummy board
					AddMoveToBoard(tempboard, size, direction, j, player, &lastRow, &lastCol);
					if ((lastRow == -1) || (lastCol == -1)) {
						// do nothing and go onto the next iteration
					}
					else {
						// remove token if it does not win
						if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) == 0) {
							tempboard[lastRow][lastCol] = 0;
						}
						else if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) != 0) {
							*side = direction;
							*move = j;
							return;

						}
					}
				}
			}
		}

		else if (i == 3) {
			// check if any position from W will make the bot win 
			direction = 'W';
			if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) == 0) {
				for (int j = 0; j < size; j++) {
					// place a token on the dummy board
					AddMoveToBoard(tempboard, size, direction, j, player, &lastRow, &lastCol);
					if ((lastRow == -1) || (lastCol == -1)) {
						// do nothing and go onto the next iteration
					}
					else {
						// remove token if it does not win
						if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) == 0) {
							tempboard[lastRow][lastCol] = 0;
						}
						else if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) != 0) {
							*side = direction;
							*move = j;
							return;

						}
					}
				}
			}
		}
	}

	// get if randomly generated move is valid
	while (validMove == 0) {
		int randomNumber = rand() % 4;
		if (randomNumber == 0) {
			direction = 'N';
		}
		else if (randomNumber == 1) {
			direction = 'E';
		}
		else if (randomNumber == 2) {
			direction = 'S';
		}
		else if (randomNumber == 3) {
			direction = 'W';
		}
		*side = direction;
		*move = rand() % size;
		AddMoveToBoard(tempboard, size, direction, *move, player, &lastRow, &lastCol);
		if ((lastCol != -1) && (lastRow != -1)) {
			validMove = 1;
		}

	}

}

void GetMoveBot2(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{

	int tempboard[MAX_SIZE][MAX_SIZE];
	char direction = 'N';
	int lastRow = 0;
	int lastCol = 0;
	int validMove = 0;

	// duplicate board
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			tempboard[i][j] = board[i][j];
		}
	}

	// check for winning move by slotting token at every position 
	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			direction = 'N';
			if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) == 0) {
				for (int j = 0; j < size; j++) {
					AddMoveToBoard(tempboard, size, direction, j, player, &lastRow, &lastCol);
					if ((lastRow == -1) || (lastCol == -1)) {
						// do nothing and go onto the next iteration
					}
					else {
						if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) == 0) {
							tempboard[lastRow][lastCol] = 0;
						}
						else if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) != 0) {
							*side = direction;
							*move = j;
							return;

						}
					}
				}
			}
		}


		else if (i == 1) {
			direction = 'E';
			if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) == 0) {
				for (int j = 0; j < size; j++) {
					AddMoveToBoard(tempboard, size, direction, j, player, &lastRow, &lastCol);
					if ((lastRow == -1) || (lastCol == -1)) {
						// do nothing and go onto the next iteration
					}
					else {
						if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) == 0) {
							tempboard[lastRow][lastCol] = 0;
						}
						else if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) != 0) {
							*side = direction;
							*move = j;
							return;

						}
					}
				}
			}
		}


		else if (i == 2) {
			direction = 'S';
			if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) == 0) {
				for (int j = 0; j < size; j++) {
					AddMoveToBoard(tempboard, size, direction, j, player, &lastRow, &lastCol);
					if ((lastRow == -1) || (lastCol == -1)) {
						// do nothing and go onto the next iteration
					}
					else {
						if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) == 0) {
							tempboard[lastRow][lastCol] = 0;
						}
						else if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) != 0) {
							*side = direction;
							*move = j;
							return;

						}
					}
				}
			}
		}

		else if (i == 3) {
			direction = 'W';
			if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) == 0) {
				for (int j = 0; j < size; j++) {
					AddMoveToBoard(tempboard, size, direction, j, player, &lastRow, &lastCol);
					if ((lastRow == -1) || (lastCol == -1)) {
						// do nothing and go onto the next iteration
					}
					else {
						if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) == 0) {
							tempboard[lastRow][lastCol] = 0;
						}
						else if ((CheckGameOver(tempboard, size, player, lastRow, lastCol)) != 0) {
							*side = direction;
							*move = j;
							return;

						}
					}
				}
			}
		}
	}


	while (validMove == 0) {
		int randomNumber = rand() % 4;
		if (randomNumber == 0) {
			direction = 'N';
		}
		else if (randomNumber == 1) {
			direction = 'E';
		}
		else if (randomNumber == 2) {
			direction = 'S';
		}
		else if (randomNumber == 3) {
			direction = 'W';
		}
		*side = direction;
		*move = rand() % size;
		AddMoveToBoard(tempboard, size, direction, *move, player, &lastRow, &lastCol);
		if ((lastCol != -1) && (lastRow != -1)) {
			validMove = 1;
		}
	}
}


		