#pragma once
#include "object.h"

struct Vertex_PT;

class object_model :
	public object
{
public:
	object_model(void);
	virtual ~object_model(void);
public:
	HRESULT virtual Init();
	virtual void Update();
	virtual void Draw();
	virtual void Release();
private:
	void updateTransform();
public:
	LPD3DXMESH mMesh;
	LPDIRECT3DTEXTURE9 mTex1;
	LPDIRECT3DTEXTURE9 mTex2;
	ID3DXMesh* mTeapot;
	D3DMATERIAL9 mTeapotMaterial;
	LPDIRECT3DDEVICE9 mDevice;
};
