#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include "complex.hpp"
#include "complex_stack.hpp"
#include "polish_notation.hpp"

constexpr int BASE = 10;

numbers::complex integral(const std::vector<std::string> &func, const numbers::complex &center, double r, long n);

#endif //INTEGRAL_H