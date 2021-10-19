#include <iostream>
#include "triangle.h"



vec3 triangle::getA(){
	return this->a;
}
vec3 triangle::getB(){
	return this->b;
}
vec3 triangle::getC(){
	return this->c;
}


bool triangle::hit(ray &r, double t_min, double t_max, hit_record &rec) const
{
	vec3 o = r.getOrigin();
	vec3 d = r.getDirection();
	vec3 a = this->a - o;
	vec3 b = this->b - o;
	vec3 c = this->c - o;



	//find t
	double t = a.dot(n)/(d.dot(n));

	if(t < t_min || t > t_max){
		return false;
	}

	vec3 intersection = vec3(r.eval(t));

	vec3 v0 = c - a;
	vec3 v1 = b -a;
	vec3 v2 = intersection - a;

	double dot00 = v0.dot(v0);
	double dot01 = v0.dot(v1);
	double dot02 = v0.dot(v2);
	double dot11 = v1.dot(v1);
	double dot12 = v1.dot(v2);

	double invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
	
	//find gamma
	double gamma = (dot11 * dot02 - dot01 * dot12) * invDenom;

	//find beta
	double beta = (dot00 * dot12 - dot01 * dot02) * invDenom;

	if(gamma >= 0 && beta >= 0 && gamma + beta < 1){
		rec.t = t;
		rec.p = r.eval(t);

		//Checking if the normal of the triangle is pointing in the same direction or opposite direction as the incoming ray. We want the normal to point in the opposite direction
		if(d.sameSide(this->n)){
			rec.normal = -1 * (this->n);
		}else{
			rec.normal = this->n;
		}

		rec.hitObj = (hittable*) this;

		return true;
	} 
	return false;
}


