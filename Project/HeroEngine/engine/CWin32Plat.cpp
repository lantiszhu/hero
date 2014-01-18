#include "CWin32Plat.h"
#include "IFrame.h"

using namespace hero;

namespace hero
{

LRESULT WINAPI freeWin32Proc(HWND _hwnd, UINT _msg, WPARAM _wparam, LPARAM _lparam)
{
	long lr = 0;
	switch(_msg)
	{
	case WM_SIZE:
		{
			break;
		}
	case WM_CLOSE:
		{
			QuitFlag = true;
			break;
		}
	case WM_DESTROY:
		{
			QuitFlag = true;
			break;
		}
	default:
		 lr = DefWindowProc(_hwnd,_msg,_wparam,_lparam);
	}
	return lr;
}

CWin32Plat::CWin32Plat()
{
	m_width = 1024;
	m_height = 768;
}

CWin32Plat::~CWin32Plat(void)
{
}

bool CWin32Plat::Init()
{
	HMODULE cur_instatnce =  GetModuleHandle(NULL);

	WNDCLASS t_wndclass;
	t_wndclass.style         = 0; 
	t_wndclass.lpfnWndProc   = freeWin32Proc; 
	t_wndclass.cbClsExtra    = 0; 
	t_wndclass.cbWndExtra    = 0; 
	t_wndclass.hInstance     = cur_instatnce; 
	t_wndclass.hIcon         = LoadIcon (cur_instatnce, NULL); 
	t_wndclass.hCursor       = LoadCursor (NULL,IDC_ARROW); 
	t_wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1); 
	t_wndclass.lpszMenuName  = NULL; 
	t_wndclass.lpszClassName = L"FreeFrameClass";

	//
	HRESULT hr = RegisterClass(&t_wndclass);
	if(!hr)
	{
		MessageBox(NULL,L"RegisterWindowClass Failure!",NULL,MB_OK);
		return false;
	}
	m_hwnd = CreateWindow(t_wndclass.lpszClassName,L"FreeFrame",WS_OVERLAPPEDWINDOW,0,0,m_width,m_height,NULL,NULL,cur_instatnce,NULL);
	if(m_hwnd==NULL)
	{
		MessageBox(NULL,L"CreateWindow Failure!",NULL,MB_OK);
		return false;
	}
	UpdateWindow(m_hwnd);
	//
	if(m_Frame)
	{
		m_Frame->Init((void*)m_hwnd);
	}
	//
	ShowWindow(m_hwnd,SW_SHOWNORMAL);


	return true;
}

void CWin32Plat::Update()
{
	while(1)
	{
		MSG tMsg;
		if(PeekMessage(&tMsg,m_hwnd,0,0,1)) 
		{ 
			TranslateMessage(&tMsg); 
			DispatchMessage(&tMsg);
		} 
		else
		{
			if(m_Frame)
			{
				m_Frame->Run();
			}
		}

		if(QuitFlag)
			break;
	}
}

void CWin32Plat::Destroy()
{
	if(m_Frame)
	{
		m_Frame->Destroy();
	}
	//结束窗口
	DestroyWindow(m_hwnd);
	//结束进程
	PostQuitMessage(0);
}




//!namespace
}
