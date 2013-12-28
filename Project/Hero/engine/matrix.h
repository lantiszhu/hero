#pragma once

namespace Free
{
namespace Core
{
	// 算法采用行主元  后乘  OPENGL可能需要转置
	/*
		vec x  m0  m1  m2  m3
		vec y  m4  m5  m6  m7
		vec z  m8  m9  m10 m11
		trans  m12 m13 m14 m15
	*/

	class CMatrix
	{
	public:
		CMatrix(){};
		~CMatrix(){};

		//operator
		CMatrix operator*(CMatrix _mat);

		//func
		void Identity();
		CMatrix Trans();
		CMatrix Inver();

		void SetTranslate(float x,float y,float z);
		void GetTranslate(float& x,float& y,float& z);

	public:
		float M[16];
	};

//!namespace core
}
//!namespace Free
}