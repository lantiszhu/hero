#pragma once

#include "IFrame.h"

namespace hero
{

class HERO_ENGINE_API CGLFrame :public IFrame
{
public:
	CGLFrame(void);
	~CGLFrame(void);

	void Init(void* param);
	void Destroy();
	void Run();

protected:
	HDC		m_hDC;
	HGLRC	m_hRC;
	HWND	m_hWnd;

private:
	void _init_gl_env();

};

//!namespace
}
