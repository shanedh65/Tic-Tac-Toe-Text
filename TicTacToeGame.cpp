#include "TicTacToeGame.h"
#include <iostream>

using namespace std;
char currentPlayer;

TicTacToeGame::TicTacToeGame()
{
	clearBoard();
}

void TicTacToeGame::playGame() {
	char player1 = 'X';
	char player2 = 'O';
	char currentPlayer = 'X';
	int turns = 0;
	
	bool finishedGame = false;
	int x, y;
	//while the game is still playing
	while (finishedGame == false) {
		printBoard();
		//State who's turn it is
		cout << "It is player " << currentPlayer << " turn.\n";
		x = getXCoord();
		y = getYCoord();
		if (placeMarker(x, y, currentPlayer) == false) {
			system("cls");
			cout << "Cannot place the marker there, it is inuse. Please try again\n";
		}
		else {
			//change the player
			
			if (currentPlayer == player1) {
				currentPlayer = player2;
			}
			else {
				currentPlayer = player1;
			}
			// increment how many turns there has been
			system("cls");
			turns = turns + 1;
			cout << "How many turns there is " << turns;
		}
		
	}
}

int TicTacToeGame::getXCoord() {
	bool isInputBad = true;
	int x;
	while (isInputBad == true) {
		cout << "Enter X coordinte: \n";
		cin >> x;

		if (x < 1 || x > 6)
		{
			cout << "Input must be between 1 and 6!\n";
		}
		else {
			isInputBad = false;
		}
	}
	return x-1;
}

int TicTacToeGame::getYCoord() {
	bool isInputBad = true;
	int y;
	while (isInputBad == true){

		cout << "Enter Y coordinte: \n";
		cin >> y;
		if (y < 1 || y > 6)
			{
			cout << "Input must be between 1 and 6!\n";
		}
		else {
			isInputBad = false;
		}
	}
	return y;
}

void TicTacToeGame::checkForVictory() {


}

bool TicTacToeGame::placeMarker(int x, int y, char currentPlayer) {
	if (board[x][y] != ' ')
	{
		return false;
	}
	board[x][y] = currentPlayer;
	return true;

}

void TicTacToeGame::clearBoard(){
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++){
			board[i][j] = ' ';
		}
	}

}
void TicTacToeGame::printBoard() {
	cout << endl;
	cout << "  1 2 3 4 5 6 \n";

	for (int i = 0; i < 6; i++) {
		cout << "--------------\n";
		cout << i+1 << "|" << board[i][1] << "|" << board[i][2] << "|" << board[i][3] << "|" << board[i][4] << "|" << board[i][5] << "|" << board[i][6] << "|" << "\n";
	}
	cout << "--------------\n";
}



