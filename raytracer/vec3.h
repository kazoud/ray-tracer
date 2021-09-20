#pragma once
#include <iostream>
#include <math.h>

class vec3 {
public:
	double e[3];

public:
	vec3() : e{ 0,0,0 } {}

	vec3(double e0, double e1, double e2) : e{ e0, e1, e2 } {}

	double x() const 
	{ 
		return e[0];
	}
	double y() const 
	{ 
		return e[1];
	}
	double z() const 
	{ 
		return e[2];
	}
	vec3 operator-() 
	{ 
		return vec3(-e[0], -e[1], -e[2]); 
	}
	double operator[](int i) const 
	{
		return e[i];
	}

	double& operator[](int i)
	{ 
		return e[i];
	}

	vec3& operator+=(const vec3& vec)
	{
		e[0] += vec.e[0];
		e[1] += vec.e[1];
		e[2] += vec.e[2];

		return *this;
	}

	vec3& operator*=(const double t)
	{
		e[0] *= t;
		e[1] *= t;
		e[2] *= t;

		return *this;
	}

	vec3& operator/=(const double t)
	{
		(*this) *= 1 / t;
		return *this;
	}
	
	double length_squared()
	{
		return (e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	}

	double length()
	{
		return sqrt(length_squared());
	}

	friend inline std::ostream& operator<<(std::ostream& out, const vec3& vec);

	friend inline vec3 operator+(const vec3& u, const vec3& v) 
	{
		return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
	}

	friend inline vec3 operator-(const vec3& u, const vec3& v) 
	{
		return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
	}

	friend inline vec3 operator*(const vec3& u, const vec3& v) 
	{
		return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
	}

	friend inline vec3 operator*(double t, const vec3& v)
	{
		return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
	}

	friend inline vec3 operator*(const vec3& v, double t) 
	{
		return t * v;
	}

	friend inline vec3 operator/(vec3 v, double t) 
	{
		return (1 / t) * v;
	}

	friend inline double dot(const vec3& u, const vec3& v) 
	{
		return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
	}

	friend inline vec3 cross(const vec3& u, const vec3& v) 
	{
		return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
			u.e[2] * v.e[0] - u.e[0] * v.e[2],
			u.e[0] * v.e[1] - u.e[1] * v.e[0]);
	}

	friend inline vec3 unit_vector(vec3 v) 
	{
		return v / v.length();
	}
};

inline std::ostream& operator<<(std::ostream& out, const vec3& vec)
{
	out << vec.e[0] << " " << vec.e[1] << " " << vec.e[2];
	return out;
}

// Type aliases for vec3
using point3 = vec3;   // 3D point
using color = vec3;    // RGB color