#pragma once

#include <vector>
#include <list>

using namespace std;

namespace Free
{

//äÖÈ¾Æ÷
class CRenderNode;

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