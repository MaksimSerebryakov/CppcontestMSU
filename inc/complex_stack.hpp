#ifndef COMPLEX_STACK_H
#define COMPLEX_STACK_H

#include "complex.hpp"
huinya

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

    complex_stack operator<<(const complex_stack &lhs, const complex &rhs) {
        complex_stack new_stack(lhs.size() + 1);

        for(size_t i = 0; i < lhs.size(); ++i) {
        new_stack.number_[i] = lhs.number_[i];
        }
        new_stack.number_[new_stack.size_ - 1] = rhs;

        return new_stack;
    }
};

#endif // COMPLEX_STACK_H