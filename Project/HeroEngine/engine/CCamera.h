#pragma once

#include "CNodeSpace.h"
//#include "CRenderNode.h"
//#include "vec3.h"

#include "core/plane3d.h"

namespace hero
{

class CCamera :public CNodeSpace
{
public:
	CCamera(void);
	~CCamera(void);

	////CMatrix& getViewMatrix();
	////CMatrix& getProjMatrix();

	//bool isStandardProj();

	//void setProj(float _fov,float _aspect,float _near,float _far);
	//void setFrustum(float _fov_r,float _fov_l,float _fov_t,float _fov_b,float _near,float _far);

	//void SetPosition(float _x,float _y,float _z);
	//void GetPosition(float& _x,float& _y,float& _z);

	//void SetTarget(float _x,float _y,float _z);
	//void GetTarget(float& _x,float& _y,float& _z);

	//void SetDistance(float _dis);
	//float GetDistance();

	//void SetDirection(float _x,float _y,float _z);
	//void GetDirection(float& _x,float& _y,float& _z);
	//
	//void SetUp(float _x,float _y,float _z);
	//void GetUp(float& _x,float& _y,float& _z);

	//virtual void Render();
	
protected:
	//bool	m_StanardProj;
	//float	m_Aspect;
	//float	m_ZNear;
	//float	m_ZFar;

	//Vec3	m_Pos;
	//Vec3	m_Target;
	//Vec3	m_Dir;
	//Vec3	m_Up;
	//float	m_Distance;

	////CMatrix m_ProjMat;

	//unsigned int m_ViewX;
	//unsigned int m_ViewY;
	//unsigned int m_ViewW;
	//unsigned int m_ViewH;
protected:
	void _update();
};


//!namespace
}
