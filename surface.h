#ifndef SURFACE_H
#define SURFACE_H

#include "utils.h"
#include "vec3.h"
#include "ray.h"

enum surfaceType {SPECULAR, PERFECT_MIRROR, DIFFUSER};


//Forward declaration to enable hit_record to able to point to a hittable object before its defined
class hittable;

struct hit_record{
    vec3 p;
    vec3 normal;
    double t;
    hittable* hitObj;
};


class surface{
    private:
        vec3 color;
        surfaceType type;
        double fuzziness;
    
    public:
        surface(const vec3 &c = vec3(vec3::BLACK), const surfaceType t = DIFFUSER, double fuzziness = 0): color{c}, type{t}, fuzziness{fuzziness}
        {};

        surfaceType getType(){
            return this->type;
        }

        void setType(surfaceType type){
            this->type = type;
        }
        
        vec3 getColor();

        void setColor(const vec3 color);


        //Call the appropriate function to calculate the reflected ray depends on the
        ray getReflectedRay(ray &r, hit_record &rec);

        //Return a reflected ray with some randomness.
        //1. Calculate the perfectly reflected ray using getReflectedRayPerfectLambertian
        //2. At the tip of the perfectly reflected ray, spawn a random ray inside the unit sphere that has the tip of the perfectly reflected ray as the center
        //3. Add the perfectly reflected ray with the random ray to get the not so perfectly reflected ray
        ray getReflectedRaySpecular(ray &r, hit_record &rec);

        //Return a perfectly reflected ray calculated using the incoming ray, the plane's normal, and the intersection point
        ray getReflectedRayPerfectMirror(ray &r, hit_record &rec);

        //Return a random ray from the intersection point to any point in the unit sphere that has the unit normal's end point as the center.
        ray getReflectedRayDiffuser(ray &r, hit_record &rec);


};

#endif