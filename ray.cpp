#include <iostream>
#include <math.h>
#include "ray.h"


vec3 ray::getOrigin() {
    return this->origin;
}

vec3 ray::getDirection() { 
    return this->direction;
}

void ray::setColor(const vec3 &color){
    this->color[0] = color[0];
    this->color[1] = color[1];
    this->color[2] = color[2];
}

vec3 ray::getColor(){
    return this->color;
}

vec3 ray::eval(double t) { 
    return this->origin + t * this->direction;
}

