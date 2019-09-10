#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

class MathHelper
{
public:
	MathHelper();
	~MathHelper();
	static void vec2_norm(float& x, float &y) {
		// sets a vectors length to 1 (which means that x + y == 1)
		float length = sqrt((x * x) + (y * y));
		if (length != 0.0f) {
			length = 1.0f / length;
			x *= length;
			y *= length;
		}
	}
	//
	void updateBall() {
		// fly a bit
		ball_pos_x += ball_dir_x * ball_speed;
		ball_pos_y += ball_dir_y * ball_speed;

		// hit by left racket?
		if (ball_pos_x < racket_left_x + racket_width &&
			ball_pos_x > racket_left_x &&
			ball_pos_y < racket_left_y + racket_height &&
			ball_pos_y > racket_left_y) {
			// set fly direction depending on where it hit the racket
			// (t is 0.5 if hit at top, 0 at center, -0.5 at bottom)
			float t = ((ball_pos_y - racket_left_y) / racket_height) - 0.5f;
			ball_dir_x = fabs(ball_dir_x); // force it to be positive
			ball_dir_y = t;
		}

		// hit by right racket?
		if (ball_pos_x > racket_right_x &&
			ball_pos_x < racket_right_x + racket_width &&
			ball_pos_y < racket_right_y + racket_height &&
			ball_pos_y > racket_right_y) {
			// set fly direction depending on where it hit the racket
			// (t is 0.5 if hit at top, 0 at center, -0.5 at bottom)
			float t = ((ball_pos_y - racket_right_y) / racket_height) - 0.5f;
			ball_dir_x = -fabs(ball_dir_x); // force it to be negative
			ball_dir_y = t;
		}

		// hit left wall?
		if (ball_pos_x < 0) {
			++score_right;
			ball_pos_x = width / 2;
			ball_pos_y = height / 2;
			ball_dir_x = fabs(ball_dir_x); // force it to be positive
			ball_dir_y = 0;
		}

		// hit right wall?
		if (ball_pos_x > width) {
			++score_left;
			ball_pos_x = width / 2;
			ball_pos_y = height / 2;
			ball_dir_x = -fabs(ball_dir_x); // force it to be negative
			ball_dir_y = 0;
		}

		// hit top wall?
		if (ball_pos_y > height) {
			ball_dir_y = -fabs(ball_dir_y); // force it to be negative
		}

		// hit bottom wall?
		if (ball_pos_y < 0) {
			ball_dir_y = fabs(ball_dir_y); // force it to be positive
		}

		// make sure that length of dir stays at 1
		MathHelper::vec2_norm(ball_dir_x, ball_dir_y);
	}
	//
};

