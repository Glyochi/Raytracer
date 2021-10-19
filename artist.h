#ifndef ARTIST_H
#define ARTIST_H

#include "vec3.h"
#include "ray.h"
#include "hittable_list.h"


//Making a seperate class to handle color mixing because I might want to add filters in the future idk :3
class artist
{
private:
    vec3 backgroundColor;

public:
    artist(vec3 &backgroundColor){
        this->backgroundColor = backgroundColor;
    };
    artist(const vec3 &backgroundColor){
        this->backgroundColor = backgroundColor;
    };
    
    //mix the color of all the rays and return a color vector
    vec3 getPixelColor(ray* array, int arrayLength, hittable_list world, double t_min, double t_max, int bounce);
    

};

#endif