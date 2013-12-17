#pragma once
#include <vector>

class object;
class camera;

class SceneManager
{
	typedef std::vector<object*> Objlist;
	typedef std::vector<object*>::iterator Objlist_iter;
	SceneManager(void);
	~SceneManager(void);
public:
	static SceneManager* getInstance();
	void InitScene();
	void UpdateScene();
	void ReleasScene();
	void AddObjectList(object *obj);
	void RenderObjects();
public:
	Objlist mObjectList;
	static SceneManager *mInstance;
	camera *mMcamera;
	object *mPic;
};
