#include "CRenderNode.h"

using namespace hero;

CRenderNode::CRenderNode(void)
{
	m_Type = RN_BASE;
}


CRenderNode::~CRenderNode(void)
{
}

int CRenderNode::GetType()
{
	return m_Type;
}