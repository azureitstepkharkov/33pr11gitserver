#pragma once
#include <gl\gl.h>
#include <gl\glu.h>
#include "GL/freeglut.h"
class OpenGLHelper
{
public:
	OpenGLHelper() {};
	~OpenGLHelper() {};
	void enable2D(int width, int height) {
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void drawRect(float x, float y, float width, float height) {
		glBegin(GL_QUADS);
		glVertex2f(x, y);
		glVertex2f(x + width, y);
		glVertex2f(x + width, y + height);
		glVertex2f(x, y + height);
		glEnd();
	}
	void drawText(float x, float y, std::string text) {
		glRasterPos2f(x, y);
		glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
	}
};

