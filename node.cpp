#include "StdAfx.h"
#include "node.h"
#include "directxrender.h"

node::node(void)
{
	D3DXMatrixIdentity(&mWorldmat);
	D3DXMatrixIdentity(&mTranslatemat);
	D3DXMatrixIdentity(&mRotatemat);	
	D3DXMatrixIdentity(&mScalemat);
}

node::~node(void)
{
}

void node::updateWorldMatrix()
{
	mWorldmat = mRotatemat * mTranslatemat * mScalemat;

	DirectxRender::getInstance()->mD3d9Device->SetTransform( D3DTS_WORLD, &mWorldmat );
}