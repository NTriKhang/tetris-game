#include <iostream>
using namespace std;
#include "move.h"
move::move(int currentX, int currentY, bool arrTrue[][4]) {
	canMove = true;
	this->currentX = currentX;
	this->currentY = currentY;
	//int sizeMatrixMoveX = currentX + 4, sizeMatrixMoveY = currentY + 4;
	matrixMove = new bool* [4];
	for (int i = 0; i < 4; i++) {
		matrixMove[i] = new bool [4];
		for (int j = 0; j < 4; j++) {
			matrixMove[i][j] = arrTrue[i][j];
		}
	}
	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		cout << matrixMove[i][j] << " ";
	//	}
	//	cout << endl;
	//}
}
move::~move() {
	for (int i = 0; i < 4; i++) {
		delete[] matrixMove[i];
	}
	delete[] matrixMove;
}
bool move::getMatrixMove(int x, int y) {
	return matrixMove[y][x];
}

void move::setMoveMatrix(int x, int y, bool value) {
	matrixMove[y][x] = value;
}
int move::getCrX() {
	return currentX;
}
int move::getCrY() {
	return currentY;
}
void move::setCanMove(bool value) {
	canMove = value;
}
bool move::getCanMove() {
	return canMove;
}

