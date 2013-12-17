#pragma once

class mousecontrol
{
public:
	mousecontrol(void);
	~mousecontrol(void);
public:
	float mMousePosx;
	float mMousePosy;
	bool mLeftButtonDown;
	bool mRightButtonDown;
};
