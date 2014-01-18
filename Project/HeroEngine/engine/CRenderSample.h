#pragma once

#include "../HeroEngine.h"

namespace hero
{

class CRenderSample
{
private:
	CRenderSample(void);
	~CRenderSample(void);

	static CRenderSample* m_Inst;
public:
	static CRenderSample* GetInst();

	void DrawAxis();
	void DrawCube();
	void DrawTeapot();
};

//!namespace
}

