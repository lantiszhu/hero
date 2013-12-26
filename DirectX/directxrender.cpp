#include "stdafx.h"
#include "directxrender.h"

DirectxRender *DirectxRender::mInstance = NULL;


DirectxRender* DirectxRender::getInstance(){
	if (mInstance == NULL)
	{
		mInstance = new DirectxRender();
	}
	return mInstance;
}

HRESULT DirectxRender::InitD3d(HWND hwnd)
{
	mD3d9 = Direct3DCreate9(D3D_SDK_VERSION);
	if (mD3d9 == NULL)
	{
		return E_FAIL;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory( &d3dpp, sizeof( d3dpp ) );

	//d3dpp.BackBufferWidth            = 512;
	//d3dpp.BackBufferHeight           = 512;
	//d3dpp.BackBufferFormat           = D3DFMT_A8R8G8B8;
	//d3dpp.BackBufferCount            = 1;
	//d3dpp.MultiSampleType            = D3DMULTISAMPLE_NONE;
	//d3dpp.MultiSampleQuality         = 0;
	//d3dpp.SwapEffect				 = D3DSWAPEFFECT_DISCARD;
	//d3dpp.hDeviceWindow              = hwnd;
	//d3dpp.Windowed					 = TRUE;
	//d3dpp.EnableAutoDepthStencil	 = TRUE;
	//d3dpp.AutoDepthStencilFormat	 = D3DFMT_D24S8;
	//d3dpp.Flags                      = 0;
	//d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_DEFAULT;

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferCount = 1; // `Ìá¹©Ò»¿ébackbuffer`
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.hDeviceWindow = hwnd;

	if( FAILED( mD3d9->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &mD3d9Device ) ) )
	{
		return E_FAIL;
	}

	mhwnd = hwnd;

	globerrenderstate();

	mVertexBuffer = NULL;
	mIndexBuffer = NULL;

	return S_OK;
}

void DirectxRender::globerrenderstate(){
	mD3d9Device->SetRenderState(D3DRS_LIGHTING, FALSE);
	mD3d9Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	//mD3d9Device->SetRenderState(D3DRS_ZENABLE, FALSE);
}

void DirectxRender::globerenderstateframebegin(){

}

void DirectxRender::globerenderstateframeend(){

}

void DirectxRender::BeginRender(){
	globerenderstateframebegin();
	mD3d9Device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL, D3DCOLOR_XRGB( 0, 0, 0 ), 1.0f, 0);
	mD3d9Device->BeginScene();	
}

void DirectxRender::EndRender(){
	mD3d9Device->EndScene();
	mD3d9Device->Present( NULL, NULL, NULL, NULL );
	globerenderstateframeend();
}

void DirectxRender::Cleanup()
{
	if( mVertexBuffer != NULL )
		mVertexBuffer->Release();

	if( mD3d9Device != NULL )
		mD3d9Device->Release();

	if( mD3d9 != NULL )
		mD3d9->Release();
}