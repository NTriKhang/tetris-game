#pragma once
#include <iostream>
#include <stdlib.h>
#include <glut.h>
#include <Windows.h>
#include "Matrix.h"
#include "move.h"
#include <vector>
using namespace std;
class collisions : public Matrix, public move
{
private:
	vector<int> full;
public:
	collisions(int sizeX, int sizeY, int currentX, int currentY,bool trueArr[][10], bool trueArrMove[][4]);
	void isCollision();
	void isFull();
	bool canRote(bool trueArr[][10], bool trueArrMove[][4]);
	bool canStep(bool trueArr[][10], bool trueArrMove[][4], int& crX);

};


