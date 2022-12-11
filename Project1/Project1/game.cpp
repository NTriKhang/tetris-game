#include "collision.h"
#include "nextCube.h"
#include "Cube.h"

const int HEIGHT = 20;
const int WIDTH = 10;
int cX, cY, oldPlace, oldRote;
bool trueArr[HEIGHT][WIDTH];
bool trueArrMove[4][4];
int dem, key, eventChange = 0;
Cube cb;
nextCube nCb;
int GameOver = 0;

void init() {
	glClearColor(0, 0, 0, 1);
	glLineWidth(1);
	srand(time(NULL));
	cX = rand() % 5 + 1, cY = 0;
	dem = 0;
	key = rand() % 7 + 1;
	nCb.changeCube = true;
	nCb.keyNextCube = rand() % 7 + 1;

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			trueArr[i][j] = false;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			trueArrMove[i][j] = false;
		}
	}
	//trueArr[5][6] = trueArr[10][2] = trueArr[10][6] = true;
	//trueArrMove[2][1] = trueArrMove[2][2] = trueArrMove[3][2] = trueArrMove[2][3] = true;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, WIDTH * 2, HEIGHT, 0, -1, 1);

}
void display_callback();
void time_callback(int x);
void special_callback(unsigned char key, int x, int y);
void drawGrid(collisions game);
void specialKey(int keu, int x, int y);

int main(int argv, char** argc) {
	glutInit(&argv, argc);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("tetris game");
	init();
	glutDisplayFunc(display_callback);
	//glutSpecialFunc(special_callback);
	glutSpecialFunc(specialKey);
	glutKeyboardFunc(special_callback);
	glutTimerFunc(0, time_callback, NULL);
	glutMainLoop();

}
void specialKey(int key, int x, int y) {
	eventChange = 1;
	oldPlace = cX;
	switch (key)
	{
	case GLUT_KEY_LEFT:
		cX--;
		break;
	case GLUT_KEY_RIGHT:
		cX++;
		break;
	case GLUT_KEY_DOWN:
		cY++;
		break;
	default:
		break;
	}
}
void special_callback(unsigned char key, int x, int y) {
	eventChange = 2;
	if (key == 32) {
		oldRote = cb.getRote();
		if (oldRote == 270) {
			cb.setRote(0);
		}
		else {
			cb.setRote(oldRote + 90);
		}
	}	
	else if (key == 27) {
		exit(0);
	}
	
}
void time_callback(int x) {
	glutPostRedisplay();
	glutTimerFunc(100 / 10, time_callback, NULL);
}
void display_callback() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    L1:
	GameOver++;
	collisions game(WIDTH, HEIGHT, cX, cY, trueArr, trueArrMove);
	if (GameOver == 60) {
		MessageBox(0, (LPCWSTR)"YOUR SCORE: ", (LPCWSTR)"GAME OVER", 0);
		exit(0);
	}
	glViewport(300, 0, 500, 500);
	
	switch (nCb.keyNextCube)
	{
	case 1:
		cb.cubeT(trueArrMove);
		break;
	case 2:
		cb.cubeLL(trueArrMove);
		break;
	case 3:
		cb.cubeLR(trueArrMove);
		break;
	case 4:
		cb.cubeSquare(trueArrMove);
		break;
	case 5:
		cb.cubeRtg(trueArrMove);
		break;
	case 6:
		cb.cubeZL(trueArrMove);
		break;
	case 7:
		cb.cubeZR(trueArrMove);
		break;
	default:
		break;
	}
	glColor3f(1.0, 0, 0);
	glBegin(GL_QUAD_STRIP);
	for (int j = 0; j <= 5; j++) {
		glVertex2i(j, 0);
		glVertex2i(j, 0 + 1);
	}
	glEnd();
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= 6; i++) {
		glVertex2i(5, i);
		glVertex2i(5 + 1, i);
	}
	glEnd();
	glBegin(GL_QUAD_STRIP);
	for (int j = 0; j <= 6; j++) {
		glVertex2i(j, 6);
		glVertex2i(j, 6 + 1);
	}
	glEnd();
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= 6; i++) {
		glVertex2i(0, i);
		glVertex2i(0 + 1, i);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (trueArrMove[i][j]) {
				glBegin(GL_QUADS);
				glVertex2i(j+ 1, i + 1);
				glVertex2i(j + 1 + 1, i + 1);
				glVertex2i(j + 1 + 1, i + 1 + 1);
				glVertex2i(j + 1, i + 1 + 1);
				glEnd();
			}
		}
	}
	glViewport(0, 0, 500, 800);

	switch (key)
	{
	case 1:
		cb.cubeT(trueArrMove);
		break;
	case 2:
		cb.cubeLL(trueArrMove);
		break;
	case 3:
		cb.cubeLR(trueArrMove);
		break;
	case 4:
		cb.cubeSquare(trueArrMove);
		break;
	case 5:
		cb.cubeRtg(trueArrMove);
		break;
	case 6:
		cb.cubeZL(trueArrMove);
		break;
	case 7:
		cb.cubeZR(trueArrMove);
		break;
	default:
		break;
	}

	bool flag = game.canRote(trueArr, trueArrMove);
	if (!flag && eventChange == 2) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				trueArrMove[i][j] = game.getMatrixMove(j, i);
				cb.setRote(oldRote);
			}
		}
		eventChange = 0;
	}
	if (!flag && eventChange == 1) {
		cX = oldPlace;
		eventChange = 0;
		goto L1;
	}
	game.isCollision();
	if (!game.getCanMove()) {
		if (nCb.isChangeCube(nCb.changeCube)) {
			nCb.changeCube = false;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (game.getMatrixMove(j, i)) {
					trueArr[cY + i - 1][cX + j] = true;
				}
			}
		}
		key = nCb.keyNextCube;
		nCb.keyNextCube = rand() % 7 + 1;
		nCb.changeCube = true;
		cX = rand() % 5 + 1;
		cY = 0;
		goto L1;
	}
	if (eventChange != 0) {
		eventChange = 0;
	}
	dem++;
	glColor3f(1.0, 1.0, 1.0);
	//drawGrid(game);
	for (int i = 1; i < HEIGHT - 1; i++) {
		for (int j = 1; j < WIDTH - 1; j++) {
			if (game.getMatrix(j,i)) {
				glBegin(GL_QUADS);
				glColor3f(1.0, 0, 0);
				glVertex2i(j, i);
				glVertex2i(j + 1, i);
				glVertex2i(j + 1, i + 1);
				glVertex2i(j, i + 1);
				glEnd();
			}
			glBegin(GL_LINE_LOOP);
			glColor3f(1.0, 1.0, 1.0);
			glVertex2i(j, i);
			glVertex2i(j + 1, i);
			glVertex2i(j + 1, i + 1);
			glVertex2i(j, i + 1);
			glEnd();
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (game.getMatrixMove(j, i)) {
				glBegin(GL_QUADS);
				glVertex2i(cX + j, cY + i);
				glVertex2i(cX + j + 1, cY + i);
				glVertex2i(cX + j + 1, cY + i + 1);
				glVertex2i(cX + j, cY + i + 1);
				glEnd();
			}
		}
	}
	
	if (dem == 14) {
		cY++;
		dem = 0;
		eventChange = 0;
		GameOver = 0;
	}
	glutSwapBuffers();
}
void drawGrid(collisions game) {
	for (int i = 1; i < HEIGHT - 1; i++) {
		for (int j = 1; j < WIDTH - 1; j++) {
			if (game.getMatrix(j, i)) {
				glBegin(GL_QUADS);
				glColor3f(1.0, 0, 0);
				glVertex2i(j, i);
				glVertex2i(j + 1, i);
				glVertex2i(j + 1, i + 1);
				glVertex2i(j, i + 1);
				glEnd();
			}
			else {
				glBegin(GL_LINE_LOOP);
				glColor3f(1.0, 1.0, 1.0);
				glVertex2i(j, i);
				glVertex2i(j + 1, i);
				glVertex2i(j + 1, i + 1);
				glVertex2i(j, i + 1);
				glEnd();
			}
		}
	}
}