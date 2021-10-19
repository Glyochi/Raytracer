#ifndef VEC_H
#define VEC_H

#include <string>
#include <cmath>
#include <iostream>

class vec3
{
private:
    double v[3];

public:
    //Constructor/destructor
    vec3(double x, double y, double z)
    {
        v[0] = x;
        v[1] = y;
        v[2] = z;
    }

    vec3(const vec3 &in)
    {
        v[0] = in.v[0];
        v[1] = in.v[1];
        v[2] = in.v[2];
    }
    vec3()
    {
        v[0] = v[1] = v[2] = 0;
    }
    ~vec3() {}

    //Accessors (position and color)
    double x() { return v[0]; }
    double y() { return v[1]; }
    double z() { return v[2]; }
    void setX(int x) { v[0] = x; }
    void setY(int y) { v[1] = y; }
    void setZ(int z) { v[2] = z; }
    //Unary operators
    vec3 operator-()
    {
        return vec3(-v[0], -v[1], -v[2]);
    }
    const vec3 &operator+() { return *this; }

    //Array syntax
    double operator[](int i) const
    {
        return v[i];
    }
    double &operator[](int i) { return v[i]; }

    //Arithmetic
    vec3 &operator+=(const vec3 &in);
    vec3 &operator-=(const vec3 &in);
    vec3 &operator*=(const vec3 &in);
    vec3 &operator/=(const vec3 &in);
    vec3 &operator*=(const double f);
    vec3 &operator/=(const double f);
    vec3 &operator=(const vec3 &in);

    vec3 operator+(const vec3 &in) const;
    vec3 operator-(const vec3 &in) const;
    vec3 operator*(const vec3 &in) const;
    vec3 operator/(const vec3 &in) const;

    friend vec3 operator*(double f, const vec3 &v1);
    vec3 operator*(double f);
    vec3 operator/(double f);

    double dot(const vec3 &in);
    vec3 cross(const vec3 &in) const;

    //Vector operations
    double length() const
    {
        return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    }
    double squared_length() const { return (v[0] * v[0] +
                                           v[1] * v[1] +
                                           v[2] * v[2]); }

    vec3 &to_unit();

    vec3 unit() const;

    double magnitude();

    std::string toString();

    //I/O
    friend std::ostream &operator<<(std::ostream &o, const vec3 &v);
    friend std::istream &operator>>(std::istream &i, vec3 &v);

    // RGB Primaries
    const static vec3 RED;
    const static vec3 GREEN;
    const static vec3 BLUE;
    // RGB Secondaries
    const static vec3 CYAN;
    const static vec3 MAGENTA;
    const static vec3 YELLOW;
    // Black and white
    const static vec3 WHITE;
    const static vec3 BLACK;
    // RGB Tertiaries
    const static vec3 ORANGE;
    const static vec3 CHARTREUSE;
    const static vec3 SPRING_GREEN;
    const static vec3 AZURE;
    const static vec3 VIOLET;
    const static vec3 ROSE;
    // Offical ISU colors
    const static vec3 CARDINAL;
    const static vec3 GOLD;

    // Check if the caller vector's direction is on the same side as the parameter normal vector
    bool sameSide(const vec3 &n);
};

#endif