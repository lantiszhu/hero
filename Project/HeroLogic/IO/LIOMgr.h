#pragma once

//!资源序列化模块

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
