#include "collision.h"


void swap(bool &x, bool &y) {
	bool temp = x;
	x = y;
	y = temp;
}

collisions::collisions(int sizeX, int sizeY, int currentX, int currentY,bool trueArr[][10], bool trueArrMove[][4]) : Matrix(sizeX, sizeY, trueArr), move(currentX, currentY, trueArrMove) {
	isFull();
	if (!full.empty()) {
		int row = full[0];

		for (int i = 0; i < full.size(); i++) {
			for (int j = 0; j < 10; j++)
			{
				trueArr[row][j] = false;
			}
			for (int k = row; k > 1; k--) {
				for (int h = 0; h < sizeX; h++) {
					swap(trueArr[k][h], trueArr[k - 1][h]);
				}
			}
		}
		full.clear();
	}
	
}

bool collisions::canRote(bool trueArr[][10], bool trueArrMove[][4]) {
	int crX = getCrX();
	int crY = getCrY();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((trueArrMove[i][j] && trueArr[crY + i][crX + j]) || (trueArrMove[i][j] == true && crX + j < 1) || (trueArrMove[i][j] == true && crX + j > 8)) {
				return false;
			}
		}
	}
}
void collisions::isCollision() {
	int crY = getCrY();
	int crX = getCrX();
	for (int i = 0; i < 4; i++) {
		bool flag = false;
		for (int j = 0; j < 4; j++) {
			bool valueMatrixMove = getMatrixMove(j, i);
			if (valueMatrixMove) {
				if (valueMatrixMove == true && getMatrix(j + crX, i + crY) == true || crY + i >= 19) {
					setCanMove(false);
					flag = true;
					break;
				}
			}
			
		}
		if (flag)
			break;
	}
}

void collisions::isFull() {
	for (int i = 19; i >= 0; i--) {
		int count = 0;
		for (int j = 1; j < 10; j++) {
			if (getMatrix(j, i) == true)
				count++;
		}
		if (count == 8) {
			full.push_back(i);
		}
	}
}
