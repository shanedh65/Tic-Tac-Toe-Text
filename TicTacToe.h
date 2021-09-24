#pragma once
class TicTacToe
{
public:
	TicTacToe();
	void playGame();

private:
	int getXCoord();
	int getYCoord();
	bool placeMarker(int x, int y, char currentPlayer);
	int checkForVictory();

	char board[3][3];
	void clearBoard();
	void printBoard();
};