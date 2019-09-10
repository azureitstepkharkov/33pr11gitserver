#pragma once
class GameMatrix
{
private:
	int** Matrix;
	int N;
	GameMatrix(const GameMatrix& a) {};
public:
	int getSize() { return N; }
	int get(int x, int y);
	void set(int x, int y, int v);
	void generate();
	void Reset();
	int**getMatrix() { return Matrix; };
	GameMatrix(int x, int y, int v);
	GameMatrix();
	~GameMatrix();
};

