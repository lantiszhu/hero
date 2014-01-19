#include "CMapBatch.h"
#include "CMapNode.h"

using namespace hero;

CMapBatch::CMapBatch(void)
:m_Node(NULL)
{
}

CMapBatch::~CMapBatch(void)
{
}

void CMapBatch::Update()
{
}

void CMapBatch::Render()
{
	if(m_Node)
	{
		m_Node->Render();
	}
}

void CMapBatch::Release()
{
	m_Node = NULL;
}

void CMapBatch::SetNode(CMapNode* _node)
{
	m_Node = _node;
}