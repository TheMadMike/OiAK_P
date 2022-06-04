#include "log.hpp"
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

Coefficients lookup(uint16_t x, const Coefficients* lookupTable) {
    Coefficients coefficients;
    for(uint8_t i = 0; i < 8; ++i) {
        if(x < logCoefficients[i].upperLimit) {
            coefficients = lookupTable[i];
            break;
        }
    }

    return coefficients;
}


uint16_t approximateLog2(uint16_t x) {
    uint16_t shiftedX = x << 3;
    Coefficients coefficients = lookup(x, logCoefficients);
    shiftedX += coefficients.b;
    shiftedX += shift(x, coefficients.a1);
    shiftedX += shift(x, coefficients.a2);

    return shiftedX >> 3;
}

uint16_t approximateAntilog2(uint16_t  x) {
    uint16_t shiftedX = x << 3;
    Coefficients coefficients = lookup(x, antiLogCoefficients);
    shiftedX += coefficients.b;
    shiftedX += shift(x, coefficients.a1);
    shiftedX += shift(x, coefficients.a2);

    return shiftedX >> 3;
}