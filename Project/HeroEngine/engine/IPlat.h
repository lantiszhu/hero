#pragma once
#include "../HeroEngine.h"

namespace hero
{

class IFrame;
class CRY_ENGINE_API IPlat
{
public:
	IPlat(void);
	~IPlat(void);

	virtual bool Init(){ return true;};
	virtual void Update(){};
	virtual void Destroy(){};

	void setFrame(IFrame* _frame){ m_Frame = _frame; }

protected:
	IFrame* m_Frame;
};

//!namespce
}

