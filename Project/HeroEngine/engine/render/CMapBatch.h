#pragma once
#include "CRenderBatch.h"

/*
	Batch  �¹�һ�����߶��Node Ϊͬ��Node����Ⱦ�͸��� �ṩͳһ��֧��
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