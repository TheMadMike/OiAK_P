#include "lns.hpp"
#include "fp16.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

void runTests(size_t repetitions);

int main(void) { 
    runTests(100);
}

void runTests(size_t repetitions) {
    srand(time(NULL));

    const size_t SCALAR_COUNT = 3;
    const unsigned scalars[] = { 10, 100, 1000 };

    std::cout << "LDIV: \n";
    std::cout << "scalar, absError\n";
    for(size_t i = 0; i < SCALAR_COUNT; ++i) {
        float absError = 0.0f;
        for(size_t j = 0; j < repetitions; ++j) {
            float a = (float) (rand()%scalars[i]) + 1.0f;
            float b = (float) (rand()%scalars[i]) + 1.0f;
            absError += std::abs(LDIV(FP16(a), FP16(b)) - (a/b));
        }

        std::cout << scalars[i] << ", " << absError / (float)(repetitions) << '\n';
    }

    std::cout << "LSR: \n";
    std::cout << "scalar, absError\n";
    for(size_t i = 0; i < SCALAR_COUNT; ++i) {
        float absError = 0.0f;
        for(size_t j = 0; j < repetitions; ++j) {
            float a = (float) (rand()%scalars[i]) + 1.0f;
            absError += std::abs(LSR(FP16(a)) - sqrt(a));
        }

        std::cout << scalars[i] << ", " << absError / (float)(repetitions) << '\n';
    }

    std::cout << "LISR: \n";
    std::cout << "scalar, absError\n";
    for(size_t i = 0; i < SCALAR_COUNT; ++i) {
        float absError = 0.0f;
        for(size_t j = 0; j < repetitions; ++j) {
            float a = (float) (rand()%scalars[i]) + 1.0f;
            absError += std::abs(LISR(FP16(a)) - (1.0f/sqrt(a)));
        }

        std::cout << scalars[i] << ", " << absError / (float)(repetitions) << '\n';
    }

}