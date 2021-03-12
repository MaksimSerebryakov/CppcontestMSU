#include "../inc/complex_stack.hpp"

using namespace numbers;

complex_stack::complex_stack() : number_{nullptr}, size_{0} {};

complex_stack::complex_stack(size_t size) : size_{size} {
    number_ = new complex [size_];
}

complex_stack::complex_stack(const complex_stack &rhs) {
    number_ = new complex [rhs.size()];

    size_ = rhs.size();

    for(size_t i = 0; i < size_; ++i) {
        number_[i] = rhs.number_[i];
    }
}

complex_stack& complex_stack::operator=(const complex_stack &rhs) {
    delete [] number_;

    number_ = new complex [rhs.size_];
    size_ = rhs.size_;

    for(size_t i = 0; i < size_; ++i) {
        number_[i] = rhs.number_[i];
    }

    return *this;
}

complex_stack::~complex_stack() {
    delete [] number_;
}

const size_t complex_stack::size() const {
    return size_;
}

const complex complex_stack::operator[](size_t i) const {
    return number_[i];
}

complex complex_stack::operator+() const {
    return number_[size_ - 1];
}

complex_stack complex_stack::operator~() const{
    complex_stack new_stack(size_ - 1);

    for(size_t i = 0; i < size_ - 1; ++i) {
        new_stack.number_[i] = this->number_[i];
    }

    return new_stack;
}