#include "StdAfx.h"
#include "sceneManager.h"
#include "camera.h"
#include "object_model.h"
#include "keycontrol.h"

SceneManager *SceneManager::mInstance = NULL;

SceneManager* SceneManager::getInstance(){
	if (mInstance == NULL)
	{
		mInstance = new SceneManager();
	}
	return mInstance;
}

SceneManager::SceneManager(void)
: mMcamera(NULL)
{
	mObjectList.clear();
}

SceneManager::~SceneManager(void)
{
}

void SceneManager::InitScene(){

	D3DXVECTOR3 vEyePt( 0.0f, 0.0f,-20.0f );
	D3DXVECTOR3 vLookatPt( 0.0f, 0.0f, 0.0f );
	D3DXVECTOR3 vUpVec( 0.0f, 1.0f, 0.0f );

	mMcamera = new camera(vEyePt,vLookatPt,vUpVec);
	AddObjectList(mMcamera);


	mPic = new object_model();
	AddObjectList(mPic);

	Objlist_iter it = mObjectList.begin();
	while(it != mObjectList.end()){
		(*it)->Init();
		++it;
	}
}

void SceneManager::UpdateScene(){
	Objlist_iter it = mObjectList.begin();
	while(it != mObjectList.end()){
		(*it)->Update();
		++it;
	}
}

void SceneManager::ReleasScene(){
	Objlist_iter it = mObjectList.begin();
	while(it != mObjectList.end()){
		(*it)->Release();
		++it;
	}
}

void SceneManager::RenderObjects(){
	Objlist_iter it = mObjectList.begin();
	while(it != mObjectList.end()){
		(*it)->Draw();
		++it;
	}
}

void SceneManager::AddObjectList(object *obj){
	if (obj != NULL){
		mObjectList.push_back(obj);
	}
}