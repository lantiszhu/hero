// Free.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "engine\CWin32Plat.h"
#include "engine\CGLFrame.h"

using namespace Free;

int _tmain(int argc, _TCHAR* argv[])
{
	CWin32Plat* win_plat = new CWin32Plat();
	win_plat->setFrame(new CGLFrame());
	
	win_plat->Init();
	win_plat->Update();
	win_plat->Destroy();

	delete win_plat;

	return 0;
}

