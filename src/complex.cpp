#include "../inc/complex.hpp"

using namespace numbers;

complex::complex(double x, double y) : real{x}, imag{y} {};

complex::complex(const std::string &num) {
    auto offset = num.find(',') + 1;
    real = std::stod(num.substr(1));
    imag = std::stod(num.substr(offset));
}

double complex::re() const{
    return real;
}
double complex::im() const{
    return imag;
}
double complex::abs2() const{
    return real * real + imag * imag;
}
double complex::abs() const{
    return sqrt(real * real + imag * imag);
}

std::string complex::to_string() const {
    std::stringstream number;
    number << "(";
    number << std::setprecision(10) << real << "," << imag << ")";

    return number.str();
}

complex complex::operator~() const {
    return complex(real, -imag);
}
complex complex::operator-() const {
    return complex(-real, -imag);
}
complex& complex::operator+=(const complex &num) {
    real += num.real;
    imag += num.imag;
    return *this;
}
complex& complex::operator-=(const complex &num) {
    real -= num.real;
    imag -= num.imag;
    return *this;
}
complex& complex::operator*=(const complex &rhs) {
    auto real_new = (rhs.real * real - rhs.imag * imag);
    auto imag_new = (rhs.imag * real + imag * rhs.real);
    real = real_new;
    imag = imag_new;
    return (*this);
}
complex& complex::operator/=(const complex &rhs) {
    double factor = rhs.real * rhs.real + rhs.imag * rhs.imag;
    auto real_new = (rhs.real * real + rhs.imag * imag) / factor;
    auto imag_new = (imag * rhs.real - rhs.imag * real) / factor;
    real = real_new;
    imag = imag_new;
    return (*this);
}

complex operator*(const complex &lhs, const complex &rhs) {
    complex out = lhs;
    out *= rhs;
    return out;
}

complex operator/(const complex &lhs, const complex &rhs) {
    complex out = lhs;
    out /= rhs;
    return out;
}
complex operator+(const complex &lhs, const complex &rhs) {
    complex out = lhs;
    out += rhs;
    return out;
}
complex operator-(const complex &lhs, const complex &rhs) {
    complex out = lhs;
    out -= rhs;
    return out;
}