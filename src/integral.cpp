#include "../inc/integral.hpp"

numbers::complex integral(const std::vector<std::string> &func, const numbers::complex &center, double r, long n) {
    numbers::complex zPrev = center + r * numbers::complex(1, 0);
    numbers::complex zCur, ksi, sum(0, 0);
    double argZ, argKsi;

    for(int i = 1; i <= n; ++i) {
        argZ = 2 * M_PI * i / n;
        argKsi = M_PI * (2 * i + 1) / n;

        zCur = center + r * numbers::complex(cos(argZ), sin(argZ));
        ksi = center + r * numbers::complex(cos(argKsi), sin(argKsi));
        sum += numbers::eval(func, ksi) * (zCur - zPrev);

        zPrev = zCur;
    }

    return sum;
}