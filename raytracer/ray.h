#pragma once

#include "vec3.h"

class ray {
public:
	point3 origin;
	vec3 direction;
public:
	ray() {}
	ray(const point3& orig, const vec3& dir) : origin(orig), direction(dir) {}

	point3 origin() const
	{
		return origin;
	}

	vec3 direction() const
	{
		return direction;
	}

	point3 at(double t) const
	{
		return origin + t * direction;
	}
};