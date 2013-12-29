#pragma once

namespace hero
{

class CSceneMgr;
class CRenderMgr;

class CFreeEngine
{
public:
	CFreeEngine(void);
	~CFreeEngine(void);

	void Init();
	void Update();
	void Render();

protected:
	CSceneMgr* m_scene_mgr;
	CRenderMgr* m_render_mgr;
};


//!namespace 
}

