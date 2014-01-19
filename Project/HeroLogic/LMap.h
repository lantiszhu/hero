#pragma once

namespace hero
{

#define GRID_SIZE 64.0

class LMap
{
public:
	LMap(void);
	~LMap(void);

	void Create(int _w,int _h);

protected:
	int m_Width;
	int m_Height;
};


//!namespace hero
}