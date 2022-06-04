#include "lns.hpp"
#include <cmath>
#include "log.hpp"

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
    float result;
    uint16_t k1 = approximateLog2(a.mantissa);

    result = powf(2.0f, 0.5f*(a.exponent + k1/1024.0f) - 7.5f);

    return result;
}

float LISR(FP16 a) {
    float result;
    uint16_t k1 = approximateLog2(a.mantissa);

    result = powf(2.0f, -0.5f*(a.exponent + k1/1024.0f) + 7.5f);

    return result;
}