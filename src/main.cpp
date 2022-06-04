#include "fp16.hpp"
#include "log.hpp"
#include <iostream>
#include <cmath>

float LDIV(FP16 a, FP16 b);
float LSR(FP16 a);

int main(void) {
    std::cout << LDIV(FP16(1.0f), FP16(3.0f)) << '\n';
}

float LDIV(FP16 a, FP16 b) {
    float result;
    uint16_t k1 = approximateLog2(a.mantissa);
    uint16_t k2 = approximateLog2(b.mantissa);

    result = pow(2.0f, (a.exponent + k1/1024.0f) - (b.exponent + k2/1024.0f));

    //TODO: figure out why the antilog method does not work

    //result = ((approximateAntilog2((k1 - k2) + 1)/1024.0f)+1.0f)*pow(2.0f, a.exponent-b.exponent);

    return result;
}

float LSR(FP16 a) {
    std::cout << a.toFloat() << '\n';
    float result;
    uint16_t k1 = approximateLog2(a.mantissa);
    std::cout << k1 << '\n';

    result = powf(2.0f, 0.5f*(a.exponent + k1/1024.0f)-7.5f);

    std::cout << result << '\n';
    return result;
}