#include "hittable_list.h"
#include <iostream>

using namespace std;

bool hittable_list::hit(ray &r, double t_min, double t_max, hit_record &rec)
{

    hit_record temp_rec;
    auto closest_so_far = t_max;

    bool hitAnything = false;
    int index = -1;

    for (const auto &object : objects)
    {

        index++;
        int debug = object->hit(r, t_min, closest_so_far, temp_rec);

        if (debug)
        {

            if (temp_rec.t > 0 && temp_rec.t < closest_so_far)
            {
                //update rec - have not update color yet
                closest_so_far = temp_rec.t;
                rec = temp_rec;

                hitAnything = true;
            }
        }
    }

    return hitAnything;
}


// vec3 hittable_list::getRayColor(ray &r, double t_min, double t_max, int depth, vec3 &backgroundColor)
// {
//     if (depth == 0)
//     {
//         return backgroundColor;
//     }

//     //create new hit_record
//     hit_record rec;

//     if (this->hit(r, t_min, t_max, rec))
//     {

//         vec3 i = r.getDirection();
//         vec3 reversed_i = -1 * i;
//         vec3 n = rec.normal;

//         //This is the value of cos of the angle created by the incoming ray and the normal
//         //This value is equal to how much of the color of the object will contribute to the final color value of the ray
//         double minIllumination = rec.hitObj->getIntensity();
//         // double illumination = minIllumination + std::max(0.0, n.dot(reversed_i)) * (1 - minIllumination); //yes n.dot(reversed_i)
//         double illumination = (minIllumination * std::max(0.0, n.dot(reversed_i)) + minIllumination)/2; //yes n.dot(reversed_i)
//         // double illumination = minIllumination;

//         vec3 combinedColor;

//         //if illumination == 1 then no reflection
//         if (illumination == 1 || depth == 1)
//         {
//             // combinedColor = rec.hitObj->getColor() * r.getIntensity() * illumination;
//             combinedColor = rec.hitObj->getColor() * illumination;

//         }
//         //if illumination != 1 and ray can still bounce then theres some reflection
//         else
//         {

//             ray reflectedRay = rec.hitObj->getReflectedRay(r, rec);

//             double reflectedIllumination = 1 - illumination;

//             combinedColor = rec.hitObj->getColor() * illumination + reflectedIllumination * this->getRayColor(reflectedRay, t_min, t_max, depth - 1, backgroundColor);

//         }

//         return combinedColor;
//     }

//     return backgroundColor;
// }

vec3 hittable_list::getRayColor(ray &r, double t_min, double t_max, int depth, vec3 &backgroundColor)
{
    if (depth == 0)
    {
        return vec3(vec3::BLACK);
    }

    //create new hit_record
    hit_record rec;

    if (this->hit(r, t_min, t_max, rec))
    {

        vec3 i = r.getDirection();
        vec3 reversed_i = -1 * i;
        vec3 n = rec.normal;

        vec3 combinedColor;


        //Blinn-Phong model

        if (rec.hitObj->getType() == DIFFUSER)
        {
            ray reflectedRay = rec.hitObj->getReflectedRay(r, rec);
            combinedColor = 0.6 * rec.hitObj->getColor() + 0.4 * this->getRayColor(reflectedRay, t_min, t_max, depth - 1, backgroundColor);
            // combinedColor = (rec.hitObj->getColor() + rec.hitObj->getColor() * this->getRayColor(reflectedRay, t_min, t_max, depth - 1, backgroundColor))/2;


            // ray reflectedRay = rec.hitObj->getReflectedRay(r, rec);

            // vec3 h = (reversed_i + (reflectedRay.getDirection() - rec.p)).unit();

            // double p = 1;
            // double k_d = 0.8;
            // double k_s = 0.2;
            // double k_a = 0.0;

            // combinedColor = k_a * backgroundColor + k_d * std::max(0.0, n.dot(reversed_i)) * rec.hitObj->getColor() + k_s * pow(max(0.0, n.dot(h)), p) * this->getRayColor(reflectedRay, t_min, t_max, depth - 1, backgroundColor);
        }
        else
        {

            ray reflectedRay = rec.hitObj->getReflectedRay(r, rec);
            combinedColor = this->getRayColor(reflectedRay, t_min, t_max, depth - 1, backgroundColor);
            //  combinedColor = (rec.hitObj->getColor() + rec.hitObj->getColor() * this->getRayColor(reflectedRay, t_min, t_max, depth - 1, backgroundColor))/2;


            // ray reflectedRay = rec.hitObj->getReflectedRay(r, rec);

            // vec3 h = (reversed_i + (reflectedRay.getDirection() - rec.p)).unit();

            // double p = 1;
            // double k_d = 0.0;
            // double k_s = 1;
            // double k_a = 0.0;

            // combinedColor = k_a * backgroundColor + k_d * std::max(0.0, n.dot(reversed_i)) * rec.hitObj->getColor() + k_s * pow(max(0.0, n.dot(h)), p) * this->getRayColor(reflectedRay, t_min, t_max, depth - 1, backgroundColor);
        }

        return combinedColor;
    }

    return backgroundColor;
}