#include "surface.h"



vec3 surface::getColor()
{
    return this->color;
}

void surface::setColor(const vec3 color)
{
    this->color = color;
}

ray surface::getReflectedRay(ray &r, hit_record &rec)
{
    if (this->type == SPECULAR)
        return this->getReflectedRaySpecular(r, rec);
    else if (this->type == PERFECT_MIRROR)
        return this->getReflectedRayPerfectMirror(r, rec);
    else
        return this->getReflectedRayDiffuser(r, rec);
}


ray surface::getReflectedRaySpecular(ray &r, hit_record &rec)
{

    //Find the perfectly reflected direction
    vec3 i = r.getDirection();
    vec3 n = rec.normal;

    vec3 perfectlyReflected_Dir = i - 2 * n * i.dot(n);
    //making sure its reflecsted dir not refracted lol
    if (!perfectlyReflected_Dir.sameSide(rec.normal))
        perfectlyReflected_Dir = -1 * perfectlyReflected_Dir;

    //Finding the not perfectly reflected direction
    vec3 notPerfectlyReflected_Dir;

    //Create a bounding box, randomly pic one point until you get one in the sphere
    vec3 random_Dir = vec3(random_double(-1, 1), random_double(-1, 1), random_double(-1, 1));
    while (random_Dir.magnitude() > 1)
        random_Dir = vec3(random_double(-1, 1), random_double(-1, 1), random_double(-1, 1));

    //Making sure the ray is not reflecting into the intersecting plane, and also the randomness is inside the unit sphere
    //Also I multiply perfectlyReflected_Dir by 3 to make the reflection more clear, less fuzzy
    notPerfectlyReflected_Dir = perfectlyReflected_Dir + random_Dir * fuzziness; 
    while (!notPerfectlyReflected_Dir.sameSide(rec.normal) || random_Dir.magnitude() > 1)
    {
        random_Dir = vec3(random_double(-1, 1), random_double(-1, 1), random_double(-1, 1));
        notPerfectlyReflected_Dir = perfectlyReflected_Dir + random_Dir * fuzziness;
    }


    return ray(rec.p, notPerfectlyReflected_Dir.to_unit());
}

ray surface::getReflectedRayPerfectMirror(ray &r, hit_record &rec)
{
    //Calculating the reflected array: https://math.stackexchange.com/questions/13261/how-to-get-a-reflection-vector
    vec3 i = r.getDirection();
    vec3 n = rec.normal;

    vec3 reflectedDir = i - 2 * n * i.dot(n);
    //making sure its reflecsted dir not refracted lol
    if (!reflectedDir.sameSide(rec.normal))
        reflectedDir = -1 * reflectedDir;

    return ray(rec.p, reflectedDir);
}

ray surface::getReflectedRayDiffuser(ray &r, hit_record &rec)
{

    //Create a bounding box, randomly pic one point until you get one in the sphere
    vec3 randomDirection = vec3(random_double(-1, 1), random_double(-1, 1), random_double(-1, 1));
    while (randomDirection.magnitude() > 1)
        randomDirection = vec3(random_double(-1, 1), random_double(-1, 1), random_double(-1, 1));

    //Calculate that randomly reflected ray
    return ray(rec.p, (rec.normal + randomDirection).unit());
}
