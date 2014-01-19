#pragma once

#include "../../HeroEngine.h"

/*
	渲染场景 可以支持多个渲染场景 每个渲染场景可以由多种不同类型渲染序列(RenderBatch)组成 并且按照一定渲染顺序 执行相应的渲染序列
*/

namespace hero
{

class CRenderBatch;

class CRenderScene
{
public:
	CRenderScene(void);
	~CRenderScene(void);

private:
	
	//typedef map<int,CRenderBatch*> RenderBatchPool;
	//RenderBatchPool m_Batchs;
};

//!namespace
}

