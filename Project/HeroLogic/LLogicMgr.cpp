#include "LLogicMgr.h"
#include "io\LIOMgr.h"

using namespace hero;

LLogicMgr::LLogicMgr(void)
:m_IOMgr(NULL)
{
}

LLogicMgr::~LLogicMgr(void)
{
}

void LLogicMgr::Init()
{
	if(m_IOMgr==NULL)
		m_IOMgr = new LIOMgr();

	m_IOMgr->Init();
}

void LLogicMgr::Update(float _tm)
{

}

void LLogicMgr::Release()
{
	if(m_IOMgr)
		m_IOMgr->Release();

	delete m_IOMgr;
}
