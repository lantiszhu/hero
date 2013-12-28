#include "stdafx.h"
#include "vec3.h"

using namespace Free;
using namespace Free::Core;

Vec3::Vec3()
{
	x=y=z=0;
}
//²Ù×÷·ûÖØÔØ
Vec3 Vec3::operator+(Vec3 _vec)
{
	Vec3 t_vec3;
	t_vec3.x = x+_vec.x;
	t_vec3.y = y+_vec.y;
	t_vec3.z = z+_vec.z;
	return t_vec3;
}

Vec3 Vec3::operator-(Vec3 _vec)
{
	Vec3 t_vec3;
	t_vec3.x = x-_vec.x;
	t_vec3.y = y-_vec.y;
	t_vec3.z = z-_vec.z;
	return t_vec3;
}

//

void Vec3::set(float _x,float _y,float _z)
{
	x = _x;y=_y;z=_z;
}

//

float Vec3::length()
{
	return sqrt(x*x+y*y+z*z);
}

float Vec3::lengthSqr()
{
	return x*x+y*y+z*z;
}

void Vec3::normalize()
{
	float t_len = length();
	if(abs(t_len)<0.00001)
	{
		x/=t_len;
		y/=t_len;
		z/=t_len;
	}
}

float Vec3::dot(Vec3 _vec)
{
	return x*_vec.x+y*_vec.y+z*_vec.z;
}

Vec3 Vec3::cross(Vec3 _vec)
{
	Vec3 t_vec;
	t_vec.x = y*_vec.z-z*_vec.y;
	t_vec.y = z*_vec.x-x*_vec.z;
	t_vec.z = x*_vec.y-y*_vec.x;
	return t_vec;
}