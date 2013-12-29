#include "StdAfx.h"
#include "CCamera.h"

using namespace hero;

CCamera::CCamera(void)
{
	//m_ViewX = 0;
	//m_ViewY = 0;
	//m_ViewW = 1024;
	//m_ViewH = 768;

	//m_StanardProj = true;
	//m_Distance = 100.0;

	//m_Pos.set(0,0,0);
	//m_Target.set(0,0,100);
	//m_Up.set(0,1,0);
}


CCamera::~CCamera(void)
{
}
//
//void CCamera::SetPosition(float _x,float _y,float _z)
//{
//	m_Pos.set(_x,_y,_z);
//}
//
//void CCamera::GetPosition(float& _x,float& _y,float& _z)
//{
//	_x = m_Pos.x;
//	_y = m_Pos.y;
//	_z = m_Pos.z;
//}
//
//void CCamera::SetTarget(float _x,float _y,float _z)
//{
//	m_Target.set(_x,_y,_z);
//	//modify dir and distance
//	m_Dir = m_Target-m_Pos;
//	m_Distance = m_Dir.length();
//	m_Dir.normalize();
//}
//
//void CCamera::GetTarget(float& _x,float& _y,float& _z)
//{
//	_x = m_Target.x;
//	_y = m_Target.y;
//	_z = m_Target.z;
//}
//
//void CCamera::SetDistance(float _dis)
//{
//	m_Distance = _dis;
//	//modify target
//	m_Target.x = m_Pos.x+m_Distance*m_Dir.x;
//	m_Target.y = m_Pos.y+m_Distance*m_Dir.y;
//	m_Target.z = m_Pos.z+m_Distance*m_Dir.z;
//}
//
//float CCamera::GetDistance()
//{
//	return m_Distance;
//}
//
//void CCamera::SetDirection(float _x,float _y,float _z)
//{
//	m_Dir.set(_x,_y,_z);
//	//modify target
//	m_Target.x = m_Pos.x+m_Distance*m_Dir.x;
//	m_Target.y = m_Pos.y+m_Distance*m_Dir.y;
//	m_Target.z = m_Pos.z+m_Distance*m_Dir.z;
//}
//
//void CCamera::GetDirection(float& _x,float& _y,float& _z)
//{
//	_x = m_Dir.x;
//	_y = m_Dir.y;
//	_z = m_Dir.z;
//}
//	
//void CCamera::SetUp(float _x,float _y,float _z)
//{
//	m_Up.set(_x,_y,_z);
//}
//
//void CCamera::GetUp(float& _x,float& _y,float& _z)
//{
//	_x = m_Up.x;
//	_y = m_Up.y;
//	_z = m_Up.z;
//}
//	
//
//bool CCamera::isStandardProj()
//{
//	return m_StanardProj;
//}
//
////CMatrix& CCamera::getViewMatrix()
////{
////	return m_Mat;
////}
////
////CMatrix& CCamera::getProjMatrix()
////{
////	return m_ProjMat;
////}
//
//void CCamera::setProj(float _fov,float _aspect,float _near,float _far)
//{
//	m_StanardProj = true;
//}
//
//void CCamera::setFrustum(float _fov_r,float _fov_l,float _fov_t,float _fov_b,float _near,float _far)
//{
//	m_StanardProj = false;
//}
//
//
//void CCamera::_update()
//{
//	////更新视矩阵
//	////Vec3	m_Pos;
//	////Vec3	m_Target;
//	////Vec3	m_Dir;
//	////Vec3	m_Up;
//	//Vec3 tmp_Dir = m_Target-m_Pos;
//	////更新投影矩阵
//	//glMatrixMode(GL_PROJECTION);
//	//glLoadIdentity();
//
//	//glMultMatrixf(m_ProjMat.M);
//	////设置模型视图矩阵
//	//glMatrixMode(GL_MODELVIEW);
//}
//
//void CCamera::Render()
//{
//	//glViewport(m_ViewX,m_ViewY,m_ViewW,m_ViewH);
//	////设置投影矩阵
//	//glMatrixMode(GL_PROJECTION);
//	//glLoadIdentity();
//	//gluPerspective(60,3.0/4.0,0.1f,100000.0);
//	////glMultMatrixf(m_ProjMat.M);
//
//	////设置模型视图矩阵
//	//glMatrixMode(GL_MODELVIEW);
//	//glLoadIdentity();
//	//gluLookAt(10,10,10,0,0,0,0.0,1.0,0.0);
//	////glMultMatrixf(m_Mat.M);
//}
