#include "lns.hpp"
#include "fp16.hpp"
#include <iostream>
#include <cmath>

int main(void) {
    std::cout << LDIV(FP16(1.0f), FP16(3.0f)) << '\n';
}