#include "StdAfx.h"
#include "CRenderMgr.h"
//#include "CRenderSample.h"
#include "CRenderNode.h"
//#include "CCamera.h"

using namespace hero;

CRenderMgr::CRenderMgr(void)
{
}


CRenderMgr::~CRenderMgr(void)
{
}

void CRenderMgr::Init()
{
	//CCamera* m_mainCam = new CCamera();
	//AddRenderBase((CRenderNode*)m_mainCam);
}

void CRenderMgr::Render()
{
	//glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//glClearColor(0.0,0.0,0.0,1.0);

	//RenderNodePool::iterator it = m_RenderPool.begin();
	//while(it!=m_RenderPool.end())
	//{
	//	(*it)->Render();
	//	it++;
	//}
	//CRenderSample::GetInst()->DrawAxis();
	//CRenderSample::GetInst()->DrawTeapot();
}

void CRenderMgr::AddRenderBase(CRenderNode* _node)
{
//	if(_node)
//		m_RenderPool.push_back(_node);
}