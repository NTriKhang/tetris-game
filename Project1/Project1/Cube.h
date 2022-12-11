#pragma once
#include "move.h"
class Cube
{
private:
	int key = 1;
	int rote = 0;
public:
	int getKey() {
		return key;
	}
	void setKey(int key) {
		this->key = key;
	}
	int getRote() {
		return rote;
	}
	void setRote(int rote) {
		this->rote = rote;
	}
	void cubeT(bool trueArrMove[][4]);
	void cubeLL(bool trueArrMove[][4]);
	void cubeLR(bool trueArrMove[][4]);
	void cubeSquare(bool trueArrMove[][4]);
	void cubeRtg(bool trueArrMove[][4]);
	void cubeZL(bool trueArrMove[][4]);
	void cubeZR(bool trueArrMove[][4]);
};

