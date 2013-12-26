#include "StdAfx.h"
#include "object_model.h"
#include "directxrender.h"
#include "vertexformat.h"
#include "sceneManager.h"
#include "camera.h"

const float g_fSize = 0.8f;



object_model::object_model(void)
{
	mTeapot = NULL;
}

object_model::~object_model(void)
{
}

HRESULT object_model::Init(){

	mDevice = DirectxRender::getInstance()->mD3d9Device;
	HRESULT hr;

	Vertex_PC triangle[6] =
	{
		{ D3DXVECTOR3(-1.0f,-1.0f, 0.0f), D3DCOLOR_ARGB(255,255,0,0), },
		{ D3DXVECTOR3(0.0f,1.0f, 0.0f), D3DCOLOR_ARGB(255,255,255,255), },
		{ D3DXVECTOR3(1.0f, -1.0f, 0.0f), D3DCOLOR_ARGB(255,0,0,255), },

		{ D3DXVECTOR3(2.0f,1.0f, 0.0f), D3DCOLOR_ARGB(255,0,255,0), },
		{ D3DXVECTOR3(3.0f, -1.0f, 0.0f), D3DCOLOR_ARGB(255,255,255,255), },
		{ D3DXVECTOR3(4.0f, 1.0f, 0.0f), D3DCOLOR_ARGB(255,255,0,0), },
	};
	
	// Create the vertex buffer.
	if( FAILED( mDevice->CreateVertexBuffer( 3 * sizeof( Vertex_PC ),
		D3DUSAGE_WRITEONLY, D3DFVF_CUSTOMVERTEX,
		D3DPOOL_MANAGED, &DirectxRender::getInstance()->mVertexBuffer, NULL ) ) )
	{
		return E_FAIL;
	}

	if( FAILED( mDevice->CreateIndexBuffer( 10 * sizeof( Vertex_PC ),
		D3DUSAGE_WRITEONLY, D3DFMT_INDEX16,
		D3DPOOL_MANAGED, &DirectxRender::getInstance()->mIndexBuffer, NULL ) ) )
	{
		return E_FAIL;
	}

	// Fill the vertex buffer.
	VOID* pVertices;
	if( FAILED( DirectxRender::getInstance()->mVertexBuffer->Lock( 0, sizeof( triangle ), ( void** )&pVertices, 0 ) ) )
		return E_FAIL;
	memcpy( pVertices, triangle, sizeof( triangle ) );
	DirectxRender::getInstance()->mVertexBuffer->Unlock();


	WORD *indices = 0;
	DirectxRender::getInstance()->mIndexBuffer->Lock(0,0,(void**)&indices,0);
	indices[0] = 0;indices[1] = 1;
	indices[2] = 1;indices[3] = 2;
	indices[4] = 2;indices[5] = 3;
	indices[6] = 3;indices[7] = 4;
	indices[8] = 4;indices[9] = 5;
	DirectxRender::getInstance()->mIndexBuffer->Unlock();

	hr = D3DXCreateTextureFromFile(mDevice,L"D:/work/DirectX/dxwork/dxwork/pictures/brickwall_broken.tga",&mTex1);
	if (FAILED(hr))
	{
		MessageBox(NULL,L"cant find texture",L"",MB_OK);
		return S_FALSE;
	}

	hr = D3DXCreateTextureFromFile(mDevice,L"D:/work/DirectX/dxwork/dxwork/pictures/spotlight_effect.tga",&mTex2);
	if (FAILED(hr))
	{
		MessageBox(NULL,L"cant find texture",L"",MB_OK);
		return S_FALSE;
	}

	mDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	mDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	mDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);


	mDevice->SetSamplerState(1, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	mDevice->SetSamplerState(1, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	mDevice->SetSamplerState(1, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);


	//mTeapotMaterial = YELLOW_MTRL;

	//D3DXCreateTeapot(mDevice, &mTeapot, 0);


	//D3DXVECTOR3 lightDir(0.707f, -0.707f, 0.707f);
	//D3DXCOLOR color(1.0f, 1.0f, 1.0f, 1.0f);
	//D3DLIGHT9 light = InitDirectionalLight(&lightDir, &color);

	//mDevice->SetLight(0, &light);
	//mDevice->LightEnable(0, true);

	//mDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	//mDevice->SetRenderState(D3DRS_SPECULARENABLE, true);

	return S_OK;
}

void object_model::Update(){
	
}

void object_model::Draw(){
	updateTransform();

	mDevice->SetStreamSource( 0, DirectxRender::getInstance()->mVertexBuffer, 0, sizeof( Vertex_PC ) );
	//mDevice->SetIndices(DirectxRender::getInstance()->mIndexBuffer);
	mDevice->SetFVF( D3DFVF_CUSTOMVERTEX );
	mDevice->DrawPrimitive( D3DPT_POINTLIST, 0, 6 );
}

void object_model::Release(){

}

void object_model::updateTransform(){
	mNode.updateWorldMatrix();
}