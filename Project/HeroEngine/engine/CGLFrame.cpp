#include "CGLFrame.h"

using namespace hero;

CGLFrame::CGLFrame(void)
{
	m_hRC = NULL;
	m_hDC = NULL;
	m_hWnd = NULL;
}


CGLFrame::~CGLFrame(void)
{
}

void CGLFrame::Init(void* param)
{
	m_hWnd = (HWND)param;
	m_hDC = GetDC(m_hWnd);
	_init_gl_env();
}

void CGLFrame::Destroy()
{
	wglMakeCurrent(NULL,NULL);
	if (m_hRC) 
		wglDeleteContext(m_hRC); 
	if (m_hDC) 
		ReleaseDC(m_hWnd, m_hDC); 
}

void CGLFrame::Run()
{
	IFrame::Run();
	SwapBuffers(m_hDC);
}

void CGLFrame::_init_gl_env()
{
	//…Ë÷√œÒÀÿ√Ë ˆ∏Ò Ω
	PIXELFORMATDESCRIPTOR pfd;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1; 
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER ; 
	pfd.dwLayerMask = PFD_MAIN_PLANE; 
	pfd.iPixelType = PFD_TYPE_RGBA; 
	pfd.cColorBits = 32; 
	pfd.cDepthBits = 8; 
	pfd.cAccumBits = 0; 
	pfd.cStencilBits = 0; 

	int pixelformat = ChoosePixelFormat(m_hDC,&pfd);
	if(!pixelformat)
	{
		MessageBox(NULL, L"ChoosePixelFormat failed", L"Error", MB_OK); 
		return; 
	}
	if(!SetPixelFormat(m_hDC, pixelformat, &pfd)) 
	{ 
		MessageBox(NULL, L"SetPixelFormat failed", L"Error", MB_OK); 
		return ; 
	}
	//
	m_hRC = wglCreateContext(m_hDC);
	wglMakeCurrent(m_hDC,m_hRC);
}
