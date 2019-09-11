
#include "pch.h"
#include "StringHelper.h"
#include "MathHelper.h"
#include "OpenGlHelper.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <sstream> 
#include <math.h> 
#include <gl\gl.h>
#include <gl\glu.h>
#include "GL/freeglut.h"

#pragma comment(lib, "Opengl32.lib")
//using namespace std;

MathHelper mh;
OpenGlHelper oGl;

//OGL or win
void keyboard() {
	// left racket
	if (GetAsyncKeyState(VK_W)) racket_left_y += racket_speed;
	if (GetAsyncKeyState(VK_S)) racket_left_y -= racket_speed;

	// right racket
	if (GetAsyncKeyState(VK_UP)) racket_right_y += racket_speed;
	if (GetAsyncKeyState(VK_DOWN)) racket_right_y -= racket_speed;
}

void enable2D(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//OGL решение - механизм делегатов в языке c#
// для функций обратного вызова - трубование библиотеки
void draw() {
	// clear (has to be done at the beginning)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	MathHelper mh;
	// draw rackets
	oGl.drawRect(mh.racket_left_x, mh.racket_left_y, mh.racket_width, mh.racket_height);
	oGl.drawRect(mh.racket_right_x, mh.racket_right_y, mh.racket_width, mh.racket_height);

	// draw ball
	oGl.drawRect(mh.ball_pos_x - mh.ball_size / 2, mh.ball_pos_y - mh.ball_size / 2, mh.ball_size, mh.ball_size);

	// draw score
	//StringHelper sh;
	oGl.drawText(width / 2 - 10, height - 15, StringHelper::int2str(score_left) + ":" + StringHelper::int2str(score_right));

	// swap buffers (has to be done at the end)
	glutSwapBuffers();
}
//OGL
void update(int value) {
	// input handling
	keyboard();

	// update ball
	updateBall();

	// Call update() again in 'interval' milliseconds
	glutTimerFunc(interval, update, 0);

	// Redisplay frame
	glutPostRedisplay();
}


int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Pong Example");

	glutDisplayFunc(draw);
	glutTimerFunc(interval, update, 0);

	enable2D(width, height);
	glColor3f(1.0f, 1.0f, 1.0f);

	glutMainLoop();
	return 0;


}

