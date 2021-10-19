#include <iostream>
#include <math.h>
#include "sphere.h"

bool sphere::hit(ray &r, double t_min, double t_max, hit_record &rec) const
{

    
    vec3 oc = r.getOrigin() - this->center;
    vec3 d = r.getDirection();

    double a = d.dot(d);
    double b = 2 * d.dot(oc);
    double c = oc.dot(oc) - this->radius * this->radius;

    double discriminant = b * b - 4 * a * c;
    double t;

    if(discriminant < 0){
        return false;
    }else if(discriminant == 0){
        t = -b/(2*a);
        if (t < t_min || t > t_max)
            return false;
    }else{
        double sqrtDiscriminant = sqrt(discriminant);
        t = (-b - sqrtDiscriminant)/(2 * a);

        if (t < t_min){
            t = (-b + sqrtDiscriminant)/(2 * a);

            if(t < t_min || t > t_max){
                return false;
            }

        }else if(t > t_max){
            //Because the other t value > this t value => other t value is also > t_max
            return false;
        }
    }

    rec.t = t;
    rec.p = r.eval(t);
    rec.normal = (rec.p - this->center)/radius; //Already unit vector doesnt have to call unit()

    //If normal is poiting to the same direction as the incoming ray then flip the normal
    if(d.sameSide(rec.normal))
        rec.normal = -1 * rec.normal;
    
    rec.hitObj = (hittable*) this;

    return true;

}