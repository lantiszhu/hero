#pragma once

#include "../../HeroEngine.h"

/*
渲染节点 里面包含真正和D3D或者OPENGL交互的API 真实的渲染数据 DP 
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
