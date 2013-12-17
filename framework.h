#pragma once
#include "node.h"

class DirectxRender;
class SceneManager;
class mousecontrol;

class FlowControl
{
public:
	FlowControl(void);
	~FlowControl(void);
public:
	void Init(HWND hwnd);
	void RenderAll();
	void UpdateAll();
	void FlushAll();
	void ReleaseAll();
	LRESULT HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
private:
	void initMoudle();
	void updateMoudle();
	void renderWorld();
	void releaseMoudle();
private:
	DirectxRender *mRender;
	SceneManager *mSceneMgr;
	mousecontrol *mMouseMgr;
	HWND mHwnd;
};
