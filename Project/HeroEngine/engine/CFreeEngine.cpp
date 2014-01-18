#include "CFreeEngine.h"
#include "scene/CSceneMgr.h"
#include "render/CRenderMgr.h"

using namespace hero;

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
