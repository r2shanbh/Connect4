/*
 * con4.cpp
 *
 *  Created on: Dec. 18, 2019
 *      Author: Raksha
 */
#include<iostream>
#include<cassert>

void print(char board[6][7]);
void intialize(char board[6][7]);

bool response();
bool left_diagonal(char board[6][7]);
bool right_diagonal(char board[6][7]);
bool horizontal(char board[6][7]);
bool vertical(char board[6][7]);

void entry(char pon, char board[6][7], char option, int turn);
unsigned int column_enter(char board[6][7], char option, int turn);
void game();

int main()
{
	do
	{game();
	}while(response());
exit(0);
	return 0;
}

bool response()
{char answer;
	std::cout<<std::endl<<std::endl<<"Do you want to play again ( Y / N ) ?  ";
	std::cin>>answer;

	if(answer=='y'||answer=='Y')
	{
		return true;
	}
	return false;
}

void print(char board[6][7])
{
	int i;

	std::cout<< std::endl<<' ';
		for (i = 1; i < 8; i++)
			std::cout << '_'<<" ";

	std::cout<< std::endl<<'|';
	for (i = 1; i < 8; i++)
		std::cout << i <<'|';

	/*std::cout<< std::endl<<'|';
	for (i = 1; i < 8; i++)
		std::cout << '-'<<'|';*/

	std::cout << std::endl;
	for (i = 0; i < 6; i++) {
		std::cout << "|";
		for (int j = 0; j < 7; j++) {
			std::cout << board[i][j]<<'|';
		}
		std::cout << std::endl;
	}

}

void intialize(char board[6][7])
{
	int i, j;
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 7; j++)
		{
			board[i][j] = '_';
		}
	}

}

void game()
{
	char board[6][7];
	char player_pon;
	char option;

	intialize(board);

	std::cout << "   LA board";
	print(board);

	std::cout<<std::endl<<"Would you like to play with the computer (Press M to do so, else press any other letter)? - ";
	std::cin>>option;

	int i = 0;

	while (i < 42)
	{
		if (i % 2 == 0)
			player_pon = '#';
		else
			player_pon = '@';

		std::cout<<std::endl<<"PLAYER "<<player_pon<<"'s Turn";
		entry(player_pon, board,option,i);
		print(board);

		if (right_diagonal(board) || left_diagonal(board) || vertical(board)
				|| horizontal(board))
		{
		std::cout<<std::endl << "Player " << player_pon << " wins!";
			break;
		}
		i++;

	}
	if (i == 42)
	{
		std::cout << std::endl << "It's a draw!";
	}
}

unsigned int column_enter(char board[6][7], char option, int turn)//33
{
	unsigned int col = 0;
	if ((option=='M'||option=='m')&&(turn%2==1))
	{col=col+std::rand()%7;
		if (board[0][col-1] != '_')
		{
			return column_enter(board,option,turn);
		}
		else
		{
			return col-1;
		}
	}
	else
	{
	std::cout << std::endl << "Enter column - ";
	std::cin >> col;

	if (col > 7)
	{
		std::cout << std::endl << "Please Re-enter column - ";
		return column_enter(board, option, turn);
	}
	if (board[0][col-1] != '_')
		{
			std::cout << std::endl << "Column full! Please Re-enter column!";
			return column_enter(board, option, turn);
		}
	return col-1;
	}
}

void entry(char pon, char board[6][7], char option, int turn)
{
	unsigned int column = column_enter(board, option, turn);

	for (int i = 5; i >= 0; i--)
	{
		if (board[i][column] == '_')
		{
			board[i][column] = pon;
			break;

		}
	}
}

bool left_diagonal(char board[6][7])//up to down
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == board[i + 1][j + 1]&&board[i][j] == board[i + 2][j + 2]&&board[i][j] == board[i + 3][j + 3]&&board[i][j] !='_' )
				return true;

		}

	}
		return false;

}

bool right_diagonal(char board[6][7])//down to up
{
	for (int i = 5; i > 2; i--)
	{
		for (int j = 0; j <4; j++)
		{
			if (board[i][j] == board[i - 1][j + 1]&&board[i][j] == board[i - 2][j + 2]&&board[i][j] == board[i - 3][j + 3]&&board[i][j] !='_' )
				return true;

		}

	}
		return false;

}

bool vertical(char board[6][7])
{
	int i, j;
	int ct = 0;

	for (j = 0; j < 7; j++)
	{
			for (i = 5; i >0; i--)
		{
			if (board[i][j] == board[i + 1][j]) {ct++;}
			else {ct = 0;}
						if (board[i][j]=='_') {ct = 0;}

			if (ct == 3)
				return true;

		}

	}

		return false;

}

bool horizontal(char board[6][7])
{
	int i, j;
	int ct = 0;

	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (board[i][j] == board[i][j + 1])
			{ct++;}
			else {ct = 0;}
			if(board[i][j]=='_'){ct=0;}

			if (ct == 3)
				return true;

		}

	}
		return false;
}
