#pragma once

namespace hero
{

class CFreeEngine;

class IFrame
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