#pragma once
#include <D3d9types.h>

struct Vertex_PT
{
	float m_Position[3]; // 顶点位置
	float m_Texcoord[2]; // 贴图坐标
};

struct Vertex_P
{
	D3DXVECTOR4 m_Position; // 顶点位置
};

struct Vertex_PC
{
	D3DXVECTOR3 m_Position; // 顶点位置
	//D3DXCOLOR m_Color;	// 顶点颜色
	DWORD color;
};
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)