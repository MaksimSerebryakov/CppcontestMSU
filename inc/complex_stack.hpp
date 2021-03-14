#ifndef COMPLEX_STACK_H
#define COMPLEX_STACK_H

#include "complex.hpp"

namespace numbers {
    class complex_stack {
        complex *number_;
        size_t size_;
    public:
        complex_stack();

        complex_stack(size_t size);

        complex_stack(const complex_stack &rhs);

        complex_stack &operator=(const complex_stack &rhs);
        ~complex_stack();

        const size_t size() const;

        const complex operator[](size_t i) const;

        complex operator+() const;

        complex_stack operator~() const; 

        friend complex_stack operator<<(const complex_stack &lhs, const complex &rhs);
    };

    complex_stack operator<<(const complex_stack &lhs, const complex &rhs);
};

#endif // COMPLEX_STACK_H
