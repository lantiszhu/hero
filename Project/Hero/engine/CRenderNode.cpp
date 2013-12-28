#include "StdAfx.h"
#include "CRenderNode.h"

using namespace Free;

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