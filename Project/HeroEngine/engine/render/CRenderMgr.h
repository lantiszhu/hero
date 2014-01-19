#pragma once

#include <vector>
#include <list>
#include <map>

using namespace std;

namespace hero
{

//äÖÈ¾Æ÷
class CRenderNode;
class CRenderBatch;

class CRenderMgr
{
public:
	CRenderMgr(void);
	~CRenderMgr(void);

	void Init();
	void Render();

	void AddRenderBase(CRenderNode* _node);

protected:
	typedef list<CRenderNode*> RenderNodePool;
	RenderNodePool m_RenderPool;

};

//!namespace
}