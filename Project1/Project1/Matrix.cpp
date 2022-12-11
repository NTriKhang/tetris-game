#include "Matrix.h"

Matrix::Matrix(int sizeX, int sizeY,bool trueArr[][10]) {
	this->sizeX = sizeX;
	this->sizeX = sizeY;

	matrix = new bool* [sizeY];
	for (int i = 0; i < sizeY; i++) {
		matrix[i] = new bool [sizeX];
		for (int j = 0; j < sizeX; j++) {
				matrix[i][j] = trueArr[i][j];
		}
	}
}
Matrix::~Matrix() {
	for (int i = 0; i < sizeY; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
bool Matrix::getMatrix(int x,int y) {
	return matrix[y][x];
}
void Matrix::setMatrix(int x, int y, bool value) {
	matrix[y][x] = value;
}
int Matrix::getX() {
	return sizeX;
}
int Matrix::getY() {
	return sizeY;
}
