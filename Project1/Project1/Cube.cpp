#include "Cube.h"
void Cube::cubeT(bool trueArrMove[][4]) {
	if (rote == 0) {
		/*setMoveMatrix(2, 1, true);
		setMoveMatrix(2, 2, true);
		setMoveMatrix(2, 3, true);	
		setMoveMatrix(3, 2, true);*/
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[2][1] = true;
		trueArrMove[2][2] = true;
		trueArrMove[2][3] = true;
		trueArrMove[3][2] = true;
	}
	else if (rote == 90) {
		/*setMoveMatrix(1, 2, true);
		setMoveMatrix(1, 2, true);
		setMoveMatrix(1, 2, true);
		setMoveMatrix(1, 2, true);*/
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[1][2] = true;
		trueArrMove[2][2] = true;
		trueArrMove[3][2] = true;
		trueArrMove[2][3] = true;
	}
	else if (rote == 180) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[1][2] = true;
		trueArrMove[2][1] = true;
		trueArrMove[2][2] = true;
		trueArrMove[2][3] = true;
	}
	else if (rote == 270) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[1][2] = true;
		trueArrMove[2][1] = true;
		trueArrMove[2][2] = true;
		trueArrMove[3][2] = true;
	}
}
void Cube::cubeLL(bool trueArrMove[][4]) {
	if (rote == 0) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[1][2] = true;
		trueArrMove[2][2] = true;
		trueArrMove[3][2] = true;
		trueArrMove[3][1] = true;
	}
	else if (rote == 90) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[2][1] = true;
		trueArrMove[2][2] = true;
		trueArrMove[2][3] = true;
		trueArrMove[1][1] = true;
	}
	else if (rote == 180) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[1][1] = true;
		trueArrMove[1][2] = true;
		trueArrMove[2][1] = true;
		trueArrMove[3][1] = true;
	}
	else if (rote == 270) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[1][1] = true;
		trueArrMove[1][2] = true;
		trueArrMove[1][3] = true;
		trueArrMove[2][3] = true;
	}
}
void Cube::cubeLR(bool trueArrMove[][4]) {
	if (rote == 0) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[1][1] = true;
		trueArrMove[2][1] = true;
		trueArrMove[3][1] = true;
		trueArrMove[3][2] = true;
	}
	else if (rote == 90) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[1][1] = true;
		trueArrMove[1][2] = true;
		trueArrMove[1][3] = true;
		trueArrMove[2][1] = true;
	}
	else if (rote == 180) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[1][1] = true;
		trueArrMove[1][2] = true;
		trueArrMove[2][2] = true;
		trueArrMove[3][2] = true;
	}
	else if (rote == 270) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[2][1] = true;
		trueArrMove[2][2] = true;
		trueArrMove[2][3] = true;
		trueArrMove[1][1] = true;
	}
}
void Cube::cubeSquare(bool trueArrMove[][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			trueArrMove[i][j] = false;
		}
	}
	trueArrMove[1][1] = true;
	trueArrMove[1][2] = true;
	trueArrMove[2][1] = true;
	trueArrMove[2][2] = true;
}
void Cube::cubeRtg(bool trueArrMove[][4]) {
	if (rote == 0 || rote == 180) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[2][0] = true;
		trueArrMove[2][1] = true;
		trueArrMove[2][2] = true;
		trueArrMove[2][3] = true;
	}
	else if (rote == 90 || rote == 270) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[0][2] = true;
		trueArrMove[1][2] = true;
		trueArrMove[2][2] = true;
		trueArrMove[3][2] = true;
	}
}
void Cube::cubeZL(bool trueArrMove[][4]) {
	if (rote == 0 || rote == 180) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[1][1] = true;
		trueArrMove[2][1] = true;
		trueArrMove[2][2] = true;
		trueArrMove[3][2] = true;
	}
	else if (rote == 90 || rote == 270) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[1][3] = true;
		trueArrMove[1][2] = true;
		trueArrMove[2][2] = true;
		trueArrMove[2][1] = true;
	}
}
void Cube::cubeZR(bool trueArrMove[][4]) {
	if (rote == 0 || rote == 180) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[1][2] = true;
		trueArrMove[2][2] = true;
		trueArrMove[2][1] = true;
		trueArrMove[3][1] = true;
	}
	else if (rote == 90 || rote == 270) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = false;
			}
		}
		trueArrMove[1][1] = true;
		trueArrMove[1][2] = true;
		trueArrMove[2][2] = true;
		trueArrMove[2][3] = true;
	}
}