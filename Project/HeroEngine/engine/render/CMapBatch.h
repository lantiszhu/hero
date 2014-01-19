#pragma once
#include "CRenderBatch.h"

/*
	Batch  下挂一个或者多个Node 为同类Node的渲染和更新 提供统一的支持
*/

namespace hero
{
	class CMapNode;
	class CMapBatch :public CRenderBatch
	{
	public:
		CMapBatch(void);
		~CMapBatch(void);

		void Update();
		void Render();
		void Release();

		void SetNode(CMapNode* _node);

	protected:
		CMapNode* m_Node;
	};

//!
}