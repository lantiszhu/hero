#pragma once

#include <math.h>

namespace Free
{
namespace Core
{
	class Vec3
	{
	public:
		Vec3();
		~Vec3(){};

		Vec3 operator+(Vec3 _vec);
		Vec3 operator-(Vec3 _vec);

		void set(float _x,float _y,float _z);

		float length();
		float lengthSqr();
		void normalize();

		float dot(Vec3 _vec);
		Vec3 cross(Vec3 _vec);

	public:
		float x;
		float y;
		float z;
	};


//!namespace core
}

//namespace Free
}