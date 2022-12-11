#pragma once
#include "Matrix.h"
class move
{
private:
	bool** matrixMove;
	int currentX, currentY;
	bool canMove;
public:
	move(int currentX, int currentY, bool arrTrue[][4]);
	~move();
	void setMoveMatrix(int x, int y, bool value);
	bool getMatrixMove(int x, int y);
	int getCrX();
	int getCrY();
	int getKey();
	void setKey(int key);
	bool getCanMove();
	void setCanMove(bool value);

};

