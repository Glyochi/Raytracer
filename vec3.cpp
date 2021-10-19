#include <math.h>

#include "vec3.h"

using namespace std;

const vec3 vec3::RED          = vec3(1,0,0);
const vec3 vec3::GREEN        = vec3(0,1,0);
const vec3 vec3::BLUE         = vec3(0,0,1);
const vec3 vec3::CYAN         = vec3::GREEN  + vec3::BLUE;
const vec3 vec3::MAGENTA      = vec3::RED    + vec3::BLUE;
const vec3 vec3::YELLOW       = vec3::RED    + vec3::GREEN;
const vec3 vec3::WHITE        = vec3::RED    + vec3::GREEN    + vec3::BLUE;
const vec3 vec3::BLACK        = vec3(0,0,0);
const vec3 vec3::ORANGE       = (vec3::RED   + vec3::YELLOW)  / 2;
const vec3 vec3::CHARTREUSE   = (vec3::GREEN + vec3::YELLOW)  / 2;
const vec3 vec3::SPRING_GREEN = (vec3::GREEN + vec3::CYAN)    / 2;
const vec3 vec3::AZURE        = (vec3::BLUE  + vec3::CYAN)    / 2;
const vec3 vec3::VIOLET       = (vec3::BLUE  + vec3::MAGENTA) / 2;
const vec3 vec3::ROSE         = (vec3::RED   + vec3::MAGENTA) / 2;
const vec3 vec3::CARDINAL     = vec3(200.0/255.0,16.0/255.0,46.0/255.0);
const vec3 vec3::GOLD         = vec3(241.0/255.0,190.0/255.0,72.0/255.0);

double vec3::dot(const vec3 &in)
{
    return v[0] * in.v[0] + v[1] * in.v[1] + v[2] * in.v[2];
}

vec3 vec3::cross(const vec3 &in) const
{
    return vec3(v[1] * in.v[2] - v[2] * in.v[1],
                v[2] * in.v[0] - v[0] * in.v[2],
                v[0] * in.v[1] - v[1] * in.v[0]);
}

std::ostream &operator<<(std::ostream &o, const vec3 &v)
{
    return o << v.v[0] << " " << v.v[1] << " " << v.v[2];
}

std::istream &operator>>(std::istream &i, vec3 &v)
{
    return i >> v.v[0] >> v.v[1] >> v.v[2];
}

vec3 &vec3::operator+=(const vec3 &in)
{
    this->v[0] = this->v[0] + in.v[0];
    this->v[1] = this->v[1] + in.v[1];
    this->v[2] = this->v[2] + in.v[2];

    return *this;
}

vec3 &vec3::operator-=(const vec3 &in)
{
    this->v[0] = this->v[0] - in.v[0];
    this->v[1] = this->v[1] - in.v[1];
    this->v[2] = this->v[2] - in.v[2];

    return *this;
}

vec3 &vec3::operator*=(const vec3 &in)
{
    this->v[0] = this->v[0] * in.v[0];
    this->v[1] = this->v[1] * in.v[1];
    this->v[2] = this->v[2] * in.v[2];

    return *this;
}

vec3 &vec3::operator/=(const vec3 &in)
{
    this->v[0] = this->v[0] / in.v[0];
    this->v[1] = this->v[1] / in.v[1];
    this->v[2] = this->v[2] / in.v[2];

    return *this;
}

vec3 &vec3::operator*=(const double f)
{
    this->v[0] = this->v[0] * f;
    this->v[1] = this->v[1] * f;
    this->v[2] = this->v[2] * f;

    return *this;
}

vec3 &vec3::operator/=(const double f)
{
    this->v[0] = this->v[0] / f;
    this->v[1] = this->v[1] / f;
    this->v[2] = this->v[2] / f;

    return *this;
}

vec3 &vec3::operator=(const vec3 &in)
{
    this->v[0] = in.v[0];
    this->v[1] = in.v[1];
    this->v[2] = in.v[2];

    return *this;
}

vec3 vec3::operator+(const vec3 &in) const
{
    return vec3(this->v[0] + in.v[0],
                this->v[1] + in.v[1],
                this->v[2] + in.v[2]);
}

vec3 vec3::operator-(const vec3 &in) const
{
    return vec3(this->v[0] - in.v[0],
                this->v[1] - in.v[1],
                this->v[2] - in.v[2]);
}

vec3 vec3::operator*(const vec3 &in) const
{
    return vec3(this->v[0] * in.v[0],
                this->v[1] * in.v[1],
                this->v[2] * in.v[2]);
}

vec3 vec3::operator/(const vec3 &in) const
{

    return vec3(this->v[0] / in.v[0],
                this->v[1] / in.v[1],
                this->v[2] / in.v[2]);
}

vec3 operator*(double f, const vec3 &v1)
{
    return vec3(v1.v[0] * f,
                v1.v[1] * f,
                v1.v[2] * f);
}

vec3 vec3::operator*(double f)
{
    return vec3(this->v[0] * f,
                this->v[1] * f,
                this->v[2] * f);
}

vec3 vec3::operator/(double f)
{
    return vec3(this->v[0] / f,
                this->v[1] / f,
                this->v[2] / f);
}

vec3 &vec3::to_unit()
{
    double oneOverMag = 1.0 / sqrt(this->v[0] * this->v[0] +
                                  this->v[1] * this->v[1] +
                                  this->v[2] * this->v[2]);

    this->v[0] *= oneOverMag;
    this->v[1] *= oneOverMag;
    this->v[2] *= oneOverMag;

    return *this;
}

vec3 vec3::unit() const
{
    double oneOverMag = 1.0 / sqrt(this->v[0] * this->v[0] +
                                  this->v[1] * this->v[1] +
                                  this->v[2] * this->v[2]);

    return vec3(this->v[0] * oneOverMag,
                this->v[1] * oneOverMag,
                this->v[2] * oneOverMag);
}

double vec3::magnitude()
{
    return sqrt(this->v[0] * this->v[0] +
                this->v[1] * this->v[1] +
                this->v[2] * this->v[2]);
}

string vec3::toString(){
    return to_string(this->v[0]) + " " + to_string(this->v[1]) + " " + to_string(this->v[2]);
}

bool vec3::sameSide(const vec3 &n){
    if (this->dot(n) > 0.0)
        return true;
    return false;
}