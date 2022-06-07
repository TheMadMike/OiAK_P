#include "log.hpp"
#include <stdexcept>
#include <cmath>

uint16_t shift(uint16_t x, int a) {
    if(a == 0)
        return 0;

    x = x >> abs(a);

    if(a < 0) {
        x = ~x;
    }

    return x;
}

const Coefficients lookup(uint16_t x, const Coefficients* lookupTable) {
    for(uint8_t i = 0; i < 8; ++i) {
        if(x < logCoefficients[i].upperLimit) {
            return lookupTable[i];
        }
    }

    throw std::out_of_range("x is out of lookupTable range");
}


uint16_t approximateLog2(uint16_t x) {
    uint16_t shiftedX = x << 3;
    Coefficients coefficients = lookup(x & 0x3F0, logCoefficients);
    shiftedX += coefficients.b;
    shiftedX += shift(shiftedX, coefficients.a1);
    shiftedX += shift(shiftedX, coefficients.a2);

    return (shiftedX >> 3);
}

uint16_t approximateAntilog2(uint16_t  x) {
    uint16_t shiftedX = x << 3;
    Coefficients coefficients = lookup(x & 0x3F0, antiLogCoefficients);
    shiftedX += coefficients.b;
    shiftedX += shift(shiftedX, coefficients.a1);
    shiftedX += shift(shiftedX, coefficients.a2);

    return (shiftedX >> 3);
}