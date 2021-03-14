#ifndef INTEGRAL_H
#define INTEGRAL_H

//#include <iostream> this libs aren't required here
//#include <cmath>
//#include <map>
//#include "complex_stack.hpp"
//#include "polish_notation.hpp"

#include <vector>
#include <string> //missing library
#include "complex.hpp"

//constexpr int BASE = 10; why it's here?

numbers::complex integral(const std::vector<std::string> &func, const numbers::complex &center, double r, long n);

#endif //INTEGRAL_H
