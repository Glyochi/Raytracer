#include "camera.h"


vec3 camera::getPos(){
    return this->pos;
}
vec3 camera::getUpperLeft(){
    return this->upper_left;
}
vec3 camera::getVert(){
    return this->vert;
}
vec3 camera::getHor(){
    return this->hor;
}

// x and y range from [0, 1). randomRange is the size of a pixel, the ray can be in any random positions in the pixel, default to 0.
ray camera::getRay(double x, double y, double randomRangeX, double randomRangeY)
{   
    return ray(this->pos,
               (this->upper_left + (x + random_double(0, randomRangeX)) * this->hor - (y + random_double(0, randomRangeY)) * this->vert - this->pos));
}


// x and y range from [0, 1). randomRange is the size of a pixel, the ray can be in any random positions in the pixel. sample_rate is the number of rays inside a pixel.
// Have to free the ray after using.
ray* camera::getRays(double x, double y, double randomRangeX, double randomRangeY, int sample_rate)
{
    ray* array = (ray*) malloc(sizeof(ray) * sample_rate);
    for(int i = 0; i < sample_rate; i++){
        array[i] = this->getRay(x, y, randomRangeX, randomRangeY);
    }

    return array;
}