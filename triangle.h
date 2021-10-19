#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>
#include <iostream>
#include "hittable.h"
#include "vec3.h"
#include "ray.h"

class triangle: public hittable {
	private:
		vec3 a,b,c, n;
	public:
		triangle(const vec3 &a, const vec3 &b, const vec3 &c, const vec3 &color, const surfaceType type = DIFFUSER, double fuzziness = 0): hittable{color, type, fuzziness}, a{a}, b{b}, c{c}{			
			n = ((b-a).cross(c-b)).unit();
		}
		
		vec3 getA();
		vec3 getB();
		vec3 getC();
		virtual bool hit(ray &r, double t_min, double t_max, hit_record &rec) const override;

};




#endif