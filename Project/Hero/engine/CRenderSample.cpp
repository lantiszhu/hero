#include "StdAfx.h"
#include "CRenderSample.h"

using namespace hero;

CRenderSample* CRenderSample::m_Inst = NULL;

CRenderSample::CRenderSample(void)
{
}


CRenderSample::~CRenderSample(void)
{
}

CRenderSample* CRenderSample::GetInst()
{
	if(!m_Inst)
		m_Inst = new CRenderSample();
	return m_Inst;
}

void CRenderSample::DrawAxis()
{
	glBegin(GL_LINES);
	
	glColor3f(1.0,0.0,0.0);glVertex3f(0.0,0.0,0.0);
	glColor3f(1.0,0.0,0.0);glVertex3f(10000000.0,0.0,0.0);

	glColor3f(0.0,1.0,0.0);glVertex3f(0.0,0.0,0.0);
	glColor3f(0.0,1.0,0.0);glVertex3f(0.0,10000000.0,0.0);

	glColor3f(0.0,0.0,1.0);glVertex3f(0.0,0.0,0.0);
	glColor3f(0.0,0.0,1.0);glVertex3f(0.0,0.0,10000000.0);

	glEnd();
}

void CRenderSample::DrawCube()
{
	
}

void CRenderSample::DrawTeapot()
{
	//glutSolidTeapot(1.0);
	glutWireTeapot(1.0);
}