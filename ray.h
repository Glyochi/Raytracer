#ifndef RAY_H
#define RAY_H

#include <cmath>
#include <iostream>
#include "vec3.h"

class ray {
	private:
		//origin of the ray
		vec3 origin;
		//unit direction vector
        vec3 direction;
		//Color of the ray
		vec3 color;
		//Ray color is multiplied with the color of the objects to get the color value of the ray. Ex: (1, 1, 1) * (1, 0.5, 0) = (1, 0.5, 0)
		double intensity;

		//Number of bounces the array can bounce
		int bounce;
	public:
		//Initialize the origin, the direction using the parameters, ray's color = white (1,1,1).
		ray(const vec3 &o, const vec3 &dir){
			this->origin = o;
            this->direction = dir.unit();
			this->color = vec3(1,1,1);
		}

		
        vec3 getOrigin();
        vec3 getDirection();
		void setColor(const vec3 &color);
		vec3 getColor();
        vec3 eval(double t);

};

#endif