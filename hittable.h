#ifndef HITTABLE_H
#define HITTABLE_H

#include "utils.h"
#include "surface.h"

#include "vec3.h"
#include "ray.h"




class hittable: public surface{

    public:
        hittable(const vec3 &c = vec3(vec3::BLACK),const surfaceType t = DIFFUSER, double fuzziness = 0): surface{c, t, fuzziness}{};
        

        //Check if the ray hits any object in the world. If it does then return true, else return false
        virtual bool hit(ray &r, double t_min, double t_max, hit_record& rec) const = 0;



};

#endif