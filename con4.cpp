/*
 * con4.cpp
 *
 *  Created on: Nov. 7, 2019
 *      Author: Raksha
 */
#include<iostream>
void print(char a[6][7]);
bool check_win(char board[6][7], char &p_winner);
void winner_row(char *p_start, char dir);
int main()
{

}
void print(char a[6][7]) {
	int i;
	int j;
	for (i = 0; i < 7; i++)
		std::cout << i;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 7; j++)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}


