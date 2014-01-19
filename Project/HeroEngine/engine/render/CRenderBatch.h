#pragma once

#include "../../HeroEngine.h"

namespace hero
{

class CRenderBatch
{
public:
	CRenderBatch(void);
	~CRenderBatch(void);

	virtual void Update();
	virtual void Render();
	virtual void Release();
	
};

//!namespace
}
