#pragma once

//!��Դ���л�ģ��

namespace hero
{

class LIOMgr
{
public:
	LIOMgr(void);
	~LIOMgr(void);

	void Init();
	void Release();

	void load();
	void save();
};


}
