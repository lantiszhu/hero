#pragma once
#include "../HeroEngine.h"

namespace hero
{

class CFreeEngine;

class HERO_ENGINE_API IFrame
{
public:
	IFrame(void);
	~IFrame(void);

	virtual void Init(void* param);
	virtual void Run();
	virtual void Destroy();

public:
	static CFreeEngine* m_engine;
};

//!namespace
}