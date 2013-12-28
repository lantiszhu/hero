#include "StdAfx.h"
#include "CFreeEngine.h"
#include "CSceneMgr.h"
#include "CRenderMgr.h"

using namespace Free;

CFreeEngine::CFreeEngine(void)
{
}


CFreeEngine::~CFreeEngine(void)
{
}

void CFreeEngine::Init()
{
	m_scene_mgr = new CSceneMgr();
	m_render_mgr = new CRenderMgr();

	//
	m_scene_mgr->Init();
	m_render_mgr->Init();
}

void CFreeEngine::Update()
{
	//�߼����� �� ���ݵ���
	m_scene_mgr->Update();
}

void CFreeEngine::Render()
{
	//������ѡ����Ⱦ

	//��Ⱦ��
	m_render_mgr->Render();
}
