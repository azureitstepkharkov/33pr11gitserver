#ifndef PCH_H
#define PCH_H

// TODO: add headers that you want to pre-compile here

// a few keycodes from 
// http://msdn.microsoft.com/en-us/library/windows/desktop/dd375731%28v=vs.85%29.aspx
#define VK_W 0x57
#define VK_S 0x53

// window size and update rate (120 fps)
const int width = 800;
const int height = 600;
const int interval = 1000 / 120;

#endif //PCH_H
