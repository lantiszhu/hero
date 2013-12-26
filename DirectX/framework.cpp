#include "StdAfx.h"
#include "framework.h"
#include "directxrender.h"
#include "sceneManager.h"
#include "mousecontrol.h"
#include "camera.h"
#include "keycontrol.h"

FlowControl::FlowControl(void)
{
}

FlowControl::~FlowControl(void){
}

void FlowControl::Init(HWND hwnd){
	mHwnd = hwnd;
	initMoudle();
}

void FlowControl::UpdateAll(){
	updateMoudle();
}

void FlowControl::RenderAll(){
	renderWorld();
}

void FlowControl::FlushAll(){

}

void FlowControl::ReleaseAll(){
	releaseMoudle();
}

LRESULT FlowControl::HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	switch (message)
	{
	case WM_LBUTTONDOWN:
		{
			mMouseMgr->mLeftButtonDown = true;
			mMouseMgr->mMousePosx = (float)LOWORD(lParam);
			mMouseMgr->mMousePosy = (float)HIWORD(lParam);
		}
		break;
	case WM_LBUTTONUP:
		{
			mMouseMgr->mLeftButtonDown = false;
		}
		break;
	case WM_RBUTTONDOWN:
		{
			mMouseMgr->mRightButtonDown = true;
		}
		break;
	case WM_RBUTTONUP:
		{
			mMouseMgr->mRightButtonDown = false;
		}
		break;
	case WM_MOUSEMOVE:
		{
			WORD x = LOWORD(lParam);
			WORD y = HIWORD(lParam);
			if (mMouseMgr->mLeftButtonDown)
			{

				mSceneMgr->mMcamera->RotateCamera(x - mMouseMgr->mMousePosx,y - mMouseMgr->mMousePosy);
			}
			mMouseMgr->mMousePosx = (float)x;
			mMouseMgr->mMousePosy = (float)y;
		}
		break;
	case WM_MOUSEWHEEL:
		{
			short delta = GET_WHEEL_DELTA_WPARAM(wParam);
			mSceneMgr->mMcamera->ZoomCamera(delta);
		}
	case WM_CHAR:
		{
			Keycontrol::getInstance()->HandleChar(char(wParam));
			break;
		}
	case WM_KEYDOWN:
		{
			Keycontrol::getInstance()->HandleKeyDown(wParam);
			break;
		}
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

/*
**
**
**
*/

void FlowControl::initMoudle(){
	mRender = DirectxRender::getInstance();
	if (mRender){
		mRender->InitD3d(mHwnd);
	}

	mSceneMgr = SceneManager::getInstance();
	if (mSceneMgr)
	{
		mSceneMgr->InitScene();
	}

	mMouseMgr = new mousecontrol();
	if (NULL == mMouseMgr)
	{
		log("mousecontrol init faild!\n");
	}
}

void FlowControl::updateMoudle(){
	if (mSceneMgr)
	{
		mSceneMgr->UpdateScene();
	}
}

void FlowControl::renderWorld(){

	if (mRender)
	{
		mRender->BeginRender();
	}

	if (mSceneMgr)
	{
		mSceneMgr->RenderObjects();
	}

	if (mRender)
	{
		mRender->EndRender();
	}
}

void FlowControl::releaseMoudle(){
	if (mMouseMgr)
	{
		delete mMouseMgr;
		mMouseMgr = NULL;
	}

	if (mSceneMgr)
	{
		mSceneMgr->ReleasScene();
	}

	if (mRender)
	{
		mRender->Cleanup();
	}
}

