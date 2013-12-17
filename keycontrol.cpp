#include "StdAfx.h"
#include "keycontrol.h"

Keycontrol *Keycontrol::mInstance = NULL;

Keycontrol* Keycontrol::getInstance(){
	if (mInstance == NULL)
	{
		mInstance = new Keycontrol();
	}
	return mInstance;
}

Keycontrol::Keycontrol(void)
{
	D3DXMatrixIdentity(&mTranslatemat);
	D3DXMatrixIdentity(&mRoatemat_x);
	D3DXMatrixIdentity(&mRoatemat_y);
	D3DXMatrixIdentity(&mRoatemat_z);
	clearKeyState();
}

Keycontrol::~Keycontrol(void)
{
}

void Keycontrol::clearKeyState(){
	mNum1 = mNum2 = mNum3 = mNum4 = mNum5 = false;
}

void Keycontrol::HandleChar(char c){
	clearKeyState();
	switch(c)
	{
	case '1':
		{
			mNum1 = true;
		}
		break;
	case '2':
		{
			mNum2 = true;
		}
		break;
	case '3':
		{
			mNum3 = true;
		}
		break;
	case '4':
		{
			mNum4 = true;
		}
		break;
	case '5':
		{
			mNum5 = true;
		}
		break;
	}	
}

void Keycontrol::HandleKeyDown(WORD k)
{
	switch(k)
	{
	case VK_F1:
		{
			int a = 0;
		}
		break;
	case VK_NUMPAD0:
		{
			int a = 0;
		}
		break;
	}
}

void Keycontrol::udpateKeyImport(){
	static float pos_x = 0;
	static float pos_y = 0;
	static float pos_z = 0;
	static float rot_z = 0;
	static float rot_x = 0;

	if( ::GetAsyncKeyState(VK_LEFT) & 0x8000f )
		pos_x -= 0.01f;
	if( ::GetAsyncKeyState(VK_RIGHT) & 0x8000f )
		pos_x += 0.01f;

	if( ::GetAsyncKeyState(VK_UP) & 0x8000f )
		pos_z += 0.01f;
	if( ::GetAsyncKeyState(VK_DOWN) & 0x8000f )
		pos_z -= 0.01f;

	if( ::GetAsyncKeyState('E') & 0x8000f )
		pos_y += 0.01f;
	if( ::GetAsyncKeyState('Q') & 0x8000f )
		pos_y -= 0.01f;

	if( ::GetAsyncKeyState('C') & 0x8000f ){
		rot_z += 0.01f;
	}

	if( ::GetAsyncKeyState('V') & 0x8000f ){
		rot_z -= 0.01f;
	}

	if( ::GetAsyncKeyState('D') & 0x8000f ){
		rot_x += 0.01f;
	}

	if( ::GetAsyncKeyState('F') & 0x8000f ){
		rot_x -= 0.01f;
	}


	D3DXMatrixTranslation(&mTranslatemat,pos_x,pos_y,pos_z);
	D3DXMatrixRotationY(&mRoatemat_z,rot_z);
	D3DXMatrixRotationX(&mRoatemat_x,rot_x);
	mRoatemat = mRoatemat_y * mRoatemat_x * mRoatemat_z;
}