#pragma once
#include "esshead.h"

class node
{
public:
	node(void);
	~node(void);
public:
	void updateWorldMatrix();
public:
	D3DXMATRIXA16 mWorldmat;
	D3DXMATRIXA16 mTranslatemat;
	D3DXMATRIXA16 mRotatemat;
	D3DXMATRIXA16 mScalemat;
};