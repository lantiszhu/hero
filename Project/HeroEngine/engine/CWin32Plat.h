#pragma once

#include "IPlat.h"

namespace hero
{

static bool QuitFlag = false;

LRESULT WINAPI freeWin32Proc(HWND _hwnd, UINT _msg, WPARAM _wparam, LPARAM _lparam);

class HERO_ENGINE_API CWin32Plat :public IPlat
{
public:
	CWin32Plat();
	~CWin32Plat(void);

	bool Init();
	virtual void Update();
	virtual void Destroy();

protected:
	HWND m_hwnd;
	unsigned int m_width;
	unsigned int m_height;

public:

};

//!namespace
}

