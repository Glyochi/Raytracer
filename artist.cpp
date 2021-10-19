#include "artist.h"
#include <iostream>


//mix the color of all the rays and return a color vector
vec3 artist::getPixelColor(ray* array, int arrayLength, hittable_list world, double t_min, double t_max, int depth){

    vec3 finalColor = vec3(vec3::BLACK);

    for(int i = 0; i < arrayLength; i++){
        vec3 rayColor = world.getRayColor(array[i], t_min, t_max, depth, this->backgroundColor);
        finalColor += rayColor;
    }
    finalColor /= arrayLength;

    return finalColor;

};