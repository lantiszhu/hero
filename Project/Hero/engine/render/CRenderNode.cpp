#include "StdAfx.h"
#include "CRenderNode.h"

using namespace hero;

CRenderNode::CRenderNode(void)
{
	m_Type = 0;
}


CRenderNode::~CRenderNode(void)
{
}

int CRenderNode::GetType()
{
	return m_Type;
}