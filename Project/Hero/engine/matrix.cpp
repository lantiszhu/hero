#include "stdafx.h"
#include "matrix.h"

using namespace Free;
using namespace Free::Core;

//
CMatrix CMatrix::operator*(CMatrix _mat)
{
	CMatrix t_mat;
	t_mat.M[0] = M[0]*_mat.M[0]+M[1]*_mat.M[4]+M[2]*_mat.M[8]+M[3]*_mat.M[12];
	t_mat.M[1] = M[0]*_mat.M[1]+M[1]*_mat.M[5]+M[2]*_mat.M[9]+M[3]*_mat.M[13];
	t_mat.M[2] = M[0]*_mat.M[2]+M[1]*_mat.M[6]+M[2]*_mat.M[10]+M[3]*_mat.M[14];
	t_mat.M[3] = M[0]*_mat.M[3]+M[1]*_mat.M[7]+M[2]*_mat.M[11]+M[3]*_mat.M[15];

	t_mat.M[4] = M[4]*_mat.M[0]+M[5]*_mat.M[4]+M[6]*_mat.M[8]+M[7]*_mat.M[12];
	t_mat.M[5] = M[4]*_mat.M[1]+M[5]*_mat.M[5]+M[6]*_mat.M[9]+M[7]*_mat.M[13];
	t_mat.M[6] = M[4]*_mat.M[2]+M[5]*_mat.M[6]+M[6]*_mat.M[10]+M[7]*_mat.M[14];
	t_mat.M[7] = M[4]*_mat.M[3]+M[5]*_mat.M[7]+M[6]*_mat.M[11]+M[7]*_mat.M[15];

	t_mat.M[8] = M[8]*_mat.M[0]+M[9]*_mat.M[4]+M[10]*_mat.M[8]+M[11]*_mat.M[12];
	t_mat.M[9] = M[8]*_mat.M[1]+M[9]*_mat.M[5]+M[10]*_mat.M[9]+M[11]*_mat.M[13];
	t_mat.M[10] = M[8]*_mat.M[2]+M[9]*_mat.M[6]+M[10]*_mat.M[10]+M[11]*_mat.M[14];
	t_mat.M[11] = M[8]*_mat.M[3]+M[9]*_mat.M[7]+M[10]*_mat.M[11]+M[11]*_mat.M[15];

	t_mat.M[12] = M[12]*_mat.M[0]+M[13]*_mat.M[4]+M[14]*_mat.M[8]+M[15]*_mat.M[12];
	t_mat.M[13] = M[12]*_mat.M[1]+M[13]*_mat.M[5]+M[14]*_mat.M[9]+M[15]*_mat.M[13];
	t_mat.M[14] = M[12]*_mat.M[2]+M[13]*_mat.M[6]+M[14]*_mat.M[10]+M[15]*_mat.M[14];
	t_mat.M[15] = M[12]*_mat.M[3]+M[13]*_mat.M[7]+M[14]*_mat.M[11]+M[15]*_mat.M[15];

	return t_mat;
}


//
void CMatrix::Identity()
{
	M[0]=1.0;	M[1]=M[2]=M[3]=0.0;
	M[5]=1.0;	M[4]=M[6]=M[7]=0.0;
	M[10]=1.0;	M[8]=M[9]=M[11]=0.0;
	M[15]=1.0;	M[12]=M[13]=M[14]=0.0;
}

CMatrix CMatrix::Trans()
{
	CMatrix t_mat;
	return t_mat;
}

CMatrix CMatrix::Inver()
{
	CMatrix t_mat;
	return t_mat;
}

void CMatrix::SetTranslate(float x,float y,float z)
{
	M[12]=x;	M[13]=y;	M[14]=z;
}

void CMatrix::GetTranslate(float& x,float& y,float& z)
{
	x=M[12];	y=M[13];	z=M[14];
}
