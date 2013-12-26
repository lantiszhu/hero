#ifndef __FRAME_WORK_H__
#define __FRAME_WORK_H__

#include "esshead.h"

class DirectxRender
{
private:
	DirectxRender(){};
	~DirectxRender(){};
public:
	static DirectxRender* getInstance();
	HRESULT InitD3d(HWND hwnd);
	void Cleanup();
	void BeginRender();
	void EndRender();
private:
	void globerrenderstate();
	void globerenderstateframebegin();
	void globerenderstateframeend();
private:
	LPDIRECT3D9 mD3d9;
	HWND mhwnd;
	static DirectxRender* mInstance;
public:
	LPDIRECT3DDEVICE9 mD3d9Device;
	LPDIRECT3DVERTEXBUFFER9 mVertexBuffer;
	LPDIRECT3DINDEXBUFFER9 mIndexBuffer;
};

#endif //__FRAME_WORK_H__
