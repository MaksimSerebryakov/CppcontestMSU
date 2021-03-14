#ifndef POLISH_NOTATION_H
#define POLISH_NOTATION_H

//#include <map> not used here
//#include "../inc/complex_stack.hpp"

#include <vector>
#include "../inc/complex.hpp"

namespace numbers{
    complex eval(const std::vector<std::string> &args, const complex &z);
};

#endif // POLISH_NOTATION_H
