#include "StdAfx.h"
#include "IFrame.h"
#include "CFreeEngine.h"

using namespace hero;

CFreeEngine* IFrame::m_engine = NULL;

IFrame::IFrame(void)
{
	if(!m_engine)
	{
		m_engine = new CFreeEngine();
		m_engine->Init();
	}
}


IFrame::~IFrame(void)
{
	if(m_engine)
		delete m_engine;
}

void IFrame::Init(void* param)
{
}

void IFrame::Run()
{
	m_engine->Update();
	m_engine->Render();
}

void IFrame::Destroy()
{

}
