#pragma once

#include "matrix.h"

using namespace Free::Core;

namespace Free
{

//�����������丸�ռ��λ�ú���̬

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

