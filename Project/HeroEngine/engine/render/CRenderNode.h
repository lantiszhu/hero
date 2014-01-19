#pragma once

#include "../../HeroEngine.h"

/*
��Ⱦ�ڵ� �������������D3D����OPENGL������API ��ʵ����Ⱦ���� DP 
*/

namespace hero
{

enum RN_TYPE
{
	RN_MAP,
	RN_BASE
};

class CRenderNode
{
public:
	CRenderNode(void);
	~CRenderNode(void);

	virtual void Render(){};
	
	//
	int GetType();

protected:
	int m_Type;
};

//!namespace
}
