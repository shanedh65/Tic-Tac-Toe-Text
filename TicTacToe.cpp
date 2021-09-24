#include "TicTacToe.h"
#include <iostream>

using namespace std;
char currentPlayer;

int main()
{
	bool finishedGame = false;
	std::cout << "Welcome to TicTacToe Extended\n";
	std::cout << "By Shane De-Hayr \n";
	while (finishedGame == false) {
		TicTacToe game;
		cout << "Entering game loop"; //Nocheckin: for testing
		game.playGame();
	}
	//system("pause");
	return 0;
}

TicTacToe::TicTacToe()
{
	clearBoard();
}

void TicTacToe::playGame() {
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
		else 
		{
			//bug: why is turns increased to 9 after 1 placement?
			/// turns++; 
			if (checkForVictory() == true) {
				cout << currentPlayer << " You have won!!!!"; 
				finishedGame = true;
			}
			else if (turns = 9){
				cout << "It is a tie game";
				finishedGame = true;
			}
			//if the marker has been placed, change the player
			else if (currentPlayer == player1) {
				currentPlayer = player2;
			}
			else {
				currentPlayer = player1;
			}
		
			//system("cls");
			cout <<"Finished game loop is " << finishedGame;
			cout << "How many turns there is " << turns;
		}

	}
}

int TicTacToe::getXCoord() {
	bool isInputBad = true;
	int x;
	while (isInputBad == true) {
		cout << "Enter row: \n";
		cin >> x;

		if (x < 1 || x > 3)
		{
			cout << "Input must be between 1 and 3!\n";
		}
		else {
			isInputBad = false;
		}
	}
	return x - 1;
}

int TicTacToe::getYCoord() {
	bool isInputBad = true;
	int y;
	while (isInputBad == true) {

		cout << "Enter Column: \n";
		cin >> y;
		if (y < 1 || y > 3)
		{
			cout << "Input must be between 1 and 3!\n";
		}
		else {
			isInputBad = false;
		}
	}
	return y;
}

bool TicTacToe::checkForVictory() {
	//board[row][column]
	for (int i = 0; i <3; i++){
		//check the rows loop
		//need to check if the first column is a blank, if it is then it will say it is a win.
		if (board[i][0] != ' ' && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])){
			cout <<"Row check returns true"; ////Nocheckin: for testing
			return true;
		}
	}
	
	for (int j = 0; j <3; j++){
		//check the columns
		if (board[0][j] != ' ' && (board[0][j] == board[1][j]) && (board[1][j] == board[2][j])){
			cout <<"Column check returns true"; //Nocheckin: for testing
			return true;
		}
	}
	//check the diagnol, 
	if (board[0][0] != ' ' && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])){
		cout <<"Diagnol check left to right returns true"; //Nocheckin: for testing
		return true;
	}
		
	if (board[0][2] != ' ' && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0])){
		cout <<"Diagnol check right to left returns true"; //Nocheckin: for testing
		return true;
	}
	return false;
}

bool TicTacToe::placeMarker(int x, int y, char currentPlayer) {
	if (board[x][y] != ' ')
	{
		return false;
	}
	board[x][y] = currentPlayer;
	return true;

}

void TicTacToe::clearBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			board[i][j] = ' ';
		}
	}

}
void TicTacToe::printBoard() {
	cout << endl;
	cout << "  1 2 3 \n";

	for (int i = 0; i < 3; i++) {
		cout << "--------------\n";
		cout << i + 1 << "|" << board[i][1] << "|" << board[i][2] << "|" << board[i][3] << "|" << "\n";
	}
	cout << "--------------\n";
}



