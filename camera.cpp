#include "StdAfx.h"
#include "camera.h"
#include "directxrender.h"

camera::camera(const D3DXVECTOR3 &eye,const D3DXVECTOR3 &look,const D3DXVECTOR3 &up)
{
	D3DXMatrixIdentity(&mViewMatrix);
	D3DXMatrixIdentity(&mProjMatrix);
	D3DXMatrixIdentity(&mPitchMatrix);
	D3DXMatrixIdentity(&mYawMatrix);

	mEyePt = eye;
	mLookatPt = look;
	mUpVec = up;
	mFov = D3DX_PI / 4;
	mAspect = 1.f;
	mZn = 0.1f;
	mFn = 100.0f;
}

camera::~camera(void)
{
}

HRESULT camera::Init(){
	return S_OK;
}

void camera::Update(){
	mNode.updateWorldMatrix();
	buildViewMatrix();
	buildProjMatrix();
}

void camera::Draw(){
}

void camera::Release(){

}

void camera::buildViewMatrix(){
	D3DXMatrixLookAtLH( &mViewMatrix, &mEyePt, &mLookatPt, &mUpVec );
	DirectxRender::getInstance()->mD3d9Device->SetTransform( D3DTS_VIEW, &mViewMatrix );
}

void camera::buildProjMatrix(){
	D3DXMatrixPerspectiveFovLH( &mProjMatrix, mFov, mAspect, mZn, mFn );
	DirectxRender::getInstance()->mD3d9Device->SetTransform( D3DTS_PROJECTION, &mProjMatrix );
}

void camera::RotateCamera(float offsetx,float offsety){

	offsetx = offsetx * 0.01f;
	offsety = 0 - offsety * 0.01f;

	D3DXMatrixRotationAxis(&mYawMatrix,&mUpVec,offsetx);
	D3DXVec3TransformCoord(&mEyePt,&mEyePt,&mYawMatrix);
	D3DXVec3TransformCoord(&mLookatPt,&mLookatPt,&mYawMatrix);

	mVecFace = mLookatPt - mEyePt;
	D3DXVec3Normalize(&mVecFace,&mVecFace);
	D3DXVec3Cross(&mVecFace,&mVecFace,&mUpVec);
	D3DXMatrixRotationAxis(&mPitchMatrix,&mVecFace,offsety);

	D3DXVec3TransformCoord(&mUpVec,&mUpVec,&mPitchMatrix);
	D3DXVec3TransformCoord(&mEyePt,&mEyePt,&mPitchMatrix);

	buildViewMatrix();
}

void camera::ZoomCamera(float delta){
	mVecFace = mLookatPt - mEyePt;

	D3DXVec3Normalize(&mVecFace,&mVecFace);
	if (delta < 0)
	{
		mEyePt -= mVecFace;	
	}
	else
	{
		mEyePt += mVecFace;
	}

	buildViewMatrix();
}