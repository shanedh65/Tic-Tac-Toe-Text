#pragma once
class TicTacToeGame
{
public:
	TicTacToeGame();
	void playGame();
	

private:
	
	int getXCoord();
	int getYCoord();
	bool placeMarker(int x, int y, char currentPlayer);
	void checkForVictory();

	char board[6][6];
	void clearBoard();
	void printBoard();
};

