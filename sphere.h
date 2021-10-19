#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>
#include <iostream>
#include "hittable.h"
#include "vec3.h"
#include "ray.h"

class sphere: public hittable {
	private:
		vec3 center;
        double radius;
	public:
		sphere(const vec3 &o, double r, const vec3 &color, const surfaceType type = DIFFUSER, double fuzziness = 0): hittable{color, type, fuzziness}, center{o}, radius{r}{
		}
		
        virtual bool hit(ray &r, double t_min, double t_max, hit_record &rec) const override;

};

#endif