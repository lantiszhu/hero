// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "HeroEngine.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		printf("dll process attach HeroEngine \n"); break;
	case DLL_THREAD_ATTACH:
		printf("dll thread attach HeroEngine \n"); break;
	case DLL_THREAD_DETACH:
		printf("dll process detach HeroEngine \n"); break;
	case DLL_PROCESS_DETACH:
		printf("dll thread detach HeroEngine \n"); break;
		break;
	}
	return TRUE;
}

