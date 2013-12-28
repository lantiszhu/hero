#pragma once

#include "matrix.h"

using namespace Free::Core;

namespace Free
{

//描述对象在其父空间的位置和姿态

class CNodeSpace
{
public:
	CNodeSpace(void);
	~CNodeSpace(void);

	virtual void SetPosition(float _x,float _y,float _z);
	virtual void GetPosition(float& _x,float& _y,float& _z);

protected:
	CMatrix m_Mat;
};

//!namespace
}

