#pragma once
#include <D3d9types.h>

struct Vertex_PT
{
	float m_Position[3]; // ����λ��
	float m_Texcoord[2]; // ��ͼ����
};

struct Vertex_P
{
	D3DXVECTOR4 m_Position; // ����λ��
};

struct Vertex_PC
{
	D3DXVECTOR3 m_Position; // ����λ��
	//D3DXCOLOR m_Color;	// ������ɫ
	DWORD color;
};
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)