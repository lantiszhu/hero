#pragma once
#include "esshead.h"

class Keycontrol
{
private:
	Keycontrol(void);
	~Keycontrol(void);
public:
	static Keycontrol* getInstance();
	void udpateKeyImport();
	void HandleChar(char c);
	void HandleKeyDown(WORD k);
private:
	void clearKeyState();
public:
	static Keycontrol *mInstance;
	D3DXMATRIXA16 mTranslatemat;
	D3DXMATRIXA16 mRoatemat;
	D3DXMATRIXA16 mRoatemat_x;
	D3DXMATRIXA16 mRoatemat_y;
	D3DXMATRIXA16 mRoatemat_z;
	bool mNum1,mNum2,mNum3,mNum4,mNum5;
};
