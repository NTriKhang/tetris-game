#pragma once
class Matrix
{
private:
	int sizeX, sizeY;
	bool** matrix;
public:
	Matrix(int sizeX, int sizeY,bool trueArr[][10]);
	~Matrix();
	bool getMatrix(int sizeX, int sizeY);
	void setMatrix(int sizeX, int sizeY, bool value);
	int getX();
	int getY();
};

