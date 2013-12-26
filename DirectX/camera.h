#pragma once
#include "object.h"
#include "node.h"

class camera :
	public object
{
public:
	camera(const D3DXVECTOR3 &eye,const D3DXVECTOR3 &look,const D3DXVECTOR3 &up);
	~camera(void);
public:
	HRESULT virtual Init();
	virtual void Update();
	virtual void Draw();
	virtual void Release();
	void RotateCamera(float offsetx,float offsety);
	void ZoomCamera(float delta);
private:
	void buildViewMatrix();
	void buildProjMatrix();
public:
	D3DXMATRIXA16 mViewMatrix;
	D3DXMATRIXA16 mProjMatrix;
	D3DXMATRIXA16 mPitchMatrix;
	D3DXMATRIXA16 mYawMatrix;

	D3DXVECTOR3 mEyePt;
	D3DXVECTOR3 mLookatPt;
	D3DXVECTOR3 mUpVec;
	D3DXVECTOR3 mVecFace;
	float mFov;
	float mAspect;
	float mZn;
	float mFn;
	node mNode;
};
