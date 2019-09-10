#pragma once
#include <gl\gl.h>
#include <gl\glu.h>
#include "GL/freeglut.h"

class OpenGLHelper
{
public:
	OpenGLHelper() {};
	~OpenGLHelper() {};
	//OGL
	void enable2D(int width, int height) {
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	
};

