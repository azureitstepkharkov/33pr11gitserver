// Pong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <sstream> 
#include <math.h> 
#include <gl\gl.h>
#include <gl\glu.h>
#include "GL/freeglut.h"
#include"StringHelper.h"
#include"MathHelper.h"
#include"OpenGLHelper.h"
//freeglut - производитель
#pragma comment(lib, "Opengl32.lib")

MathHelper mh;								//Pattern Singleton
OpenGLHelper oGL;


void draw() {
	// clear (has to be done at the beginning)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	// draw rackets
	oGL.drawRect(mh.racket_left_x, mh.racket_left_y, mh.racket_width, mh.racket_height);
	oGL.drawRect(mh.racket_right_x, mh.racket_right_y, mh.racket_width, mh.racket_height);

	// draw ball
	oGL.drawRect(mh.ball_pos_x - mh.ball_size / 2, mh.ball_pos_y - mh.ball_size / 2, mh.ball_size, mh.ball_size);

	// draw score
	oGL.drawText(width / 2 - 10, height - 15, StringHelper::int2str(score_left) + ":" + StringHelper::int2str(score_right));

	// swap buffers (has to be done at the end)
	glutSwapBuffers();
}

void keyboard() {
	// left racket
	if (GetAsyncKeyState(VK_W)) mh.racket_left_y += mh.racket_speed;
	if (GetAsyncKeyState(VK_S)) mh.racket_left_y -= mh.racket_speed;

	// right racket
	if (GetAsyncKeyState(VK_UP)) mh.racket_right_y += mh.racket_speed;
	if (GetAsyncKeyState(VK_DOWN)) mh.racket_right_y -= mh.racket_speed;
}

void update(int value) {
	// input handling
	keyboard();

	// update ball
	mh.updateBall();

	// Call update() again in 'interval' milliseconds
	glutTimerFunc(interval, update, 0);

	// Redisplay frame
	glutPostRedisplay();
}
//
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Pong Example");
	//Регистрация функций обратного вызова 
	glutDisplayFunc(draw);
	glutTimerFunc(interval, update, 0);
	//установка размеров сцены и "базового" цвета
	oGL.enable2D(width, height);
	glColor3f(1.0f, 1.0f, 1.0f);
	glutMainLoop();
	return 0;
}