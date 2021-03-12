#include <iostream>
#include "inc/complex_stack.hpp"
#include "inc/complex.hpp"
#include "inc/integral.hpp"
#include "inc/polish_notation.hpp"


int main(int argc, char **argv) {
    if(argc < 2) {
        return 1;
    }

    numbers::complex c(argv[1]);   
    double r = strtod(argv[2], nullptr);
    long n = strtol(argv[3], nullptr, BASE);
    std::vector<std::string> func;
    for(int i = 4; i < argc; ++i) {
        func.push_back(argv[i]);
    }

    std::cout << integral(func, c, r, n).to_string() << std::endl;

    return 0;
}