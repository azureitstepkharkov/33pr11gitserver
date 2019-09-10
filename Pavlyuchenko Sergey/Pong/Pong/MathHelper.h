#pragma once
class MathHelper
{
public:
	MathHelper() {};
	~MathHelper() {};
	static void vec2_norm(ball_dir_x, ball_dir_y);

	// a few keycodes from 
// http://msdn.microsoft.com/en-us/library/windows/desktop/dd375731%28v=vs.85%29.aspx
#define VK_W 0x57
#define VK_S 0x53
// window size and update rate (60 fps)
	const int width = 434;
	const int height = 200;
	const int interval = 1000 / 60;

	#endif "MathHelper.h"
};

