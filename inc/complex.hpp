#ifndef COMPLEX_H
#define COMPLEX_H

//#include <iostream> all of this libs aren't used here
//#include <cstdlib>
//#include <cstring>
//#include <cstdio>
//#include <cmath>
//#include <sstream>
//#include <iomanip>

#include <string> //missing lib

namespace numbers {
    class complex {
        double real;
        double imag;

    public:
        complex(double x = 0, double y = 0);

        explicit complex(const std::string &num);

        double re() const;

        double im() const;

        double abs2() const;

        double abs() const;

        std::string to_string() const;

        complex operator~() const;

        complex operator-() const;

        complex &operator+=(const complex &num);

        complex &operator-=(const complex &num);

        complex& operator*=(const complex &rhs);

        complex& operator/=(const complex &rhs);

        friend complex operator*(const complex &lhs, const complex &rhs);

        friend complex operator/(const complex &lhs, const complex &rhs);

        friend complex operator+(const complex &lhs, const complex &rhs);

        friend complex operator-(const complex &lhs, const complex &rhs);
    };
    complex operator*(const complex &lhs, const complex &rhs);

    complex operator/(const complex &lhs, const complex &rhs);

    complex operator+(const complex &lhs, const complex &rhs);

    complex operator-(const complex &lhs, const complex &rhs);
};

#endif // COMPLEX_H
