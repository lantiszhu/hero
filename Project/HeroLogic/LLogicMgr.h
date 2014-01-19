#pragma once

#include "HeroLogic.h"

namespace hero
{

	class LIOMgr;

	class LLogicMgr
	{
	public:
		LLogicMgr(void);
		~LLogicMgr(void);

		void Init();
		void Update(float _tm);
		void Release();

	protected:
		LIOMgr* m_IOMgr;
	};

//¬ﬂº≠π‹¿Ì¿‡
}
