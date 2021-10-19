#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <limits>

const double double_infinity = std::numeric_limits<double>::infinity();
const int int_infinity = std::numeric_limits<int>::infinity();
const double pi = 3.1415926535897932385;

//Return a random dobule [0, 1)
double random_double();

//Return a random double in [min, max)
double random_double(double min, double max);

#endif