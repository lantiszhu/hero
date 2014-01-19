#pragma once
#include "CRenderNode.h"

namespace hero
{

	class CMapNode:public CRenderNode
	{
	public:
		CMapNode(void);
		~CMapNode(void);

		virtual void Render(){};
		
	};

//!namespace
}
