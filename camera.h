#ifndef CAMERA_H
#define CAMERA_H

#include <math.h>
#include "utils.h"

#include "vec3.h"
#include "ray.h"


// X increase left, Y increase Up, Z increase into the screen

class camera
{

private:
    vec3 pos;
    vec3 hor;
    vec3 vert;

    //Camera's view's upperleft
    vec3 upper_left;

public:
    //pos and lookAt are 3d points, up, however, is a vector
    camera(const vec3 &pos, const vec3 lookAt, const vec3 up, double fov, double ar)
    {
        vec3 x, y, z;

        this->pos = vec3(pos);

        //unit vectors for x, y, z (side to side, up and down, front and back)
        z = (lookAt - pos).unit();  
        y = up.unit();
        x = z.cross(y);

        double halfFOVRadian = fov * pi / (180 * 2);

        
        vert = 2 * tan(halfFOVRadian) * y;
        hor = 2 * tan(halfFOVRadian) * ar * x;
        upper_left = pos + z + vert/2 - hor/2;



    }

    vec3 getPos();
    vec3 getUpperLeft();

    vec3 getVert();
    vec3 getHor();

    ray getRay(double x, double y, double randomRangeX, double randomRangeY);
    ray* getRays(double x, double y, double randomRangeX, double randomRangeY, int sample_rate);
};

#endif