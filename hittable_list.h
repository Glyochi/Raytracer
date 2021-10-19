#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "utils.h"
#include "surface.h"
#include "hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class hittable_list{
    public:
        hittable_list() {}
        hittable_list(shared_ptr<hittable> object) { add(object); }

        void clear() { objects.clear(); }
        void add(shared_ptr<hittable> object) { objects.push_back(object); }

        //Check if the ray hits any object in the world
        bool hit(
            ray& r, double t_min, double t_max, hit_record& rec);

        //Recursive function. 
        //  Call hit() to check if the ray hit any object. From the intersection between the ray and
        //the closest object, span an appropriate ray into the world and call itself again. For each iteration depth 
        //decrements by one. This process finishes collecting color information when depth == 0.
        //  If the ray hits nothing then return background color.
        //  The color of the ray will be the combination of all the colors received from the recursive calls.
        vec3 getRayColor(ray& r, double t_min, double t_max, int depth, vec3 &backgroundColor);


    public:
        std::vector<shared_ptr<hittable>> objects;
};


#endif