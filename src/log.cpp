#include "log.hpp"
#include "adder.hpp"
#include <stdexcept>
#include <cmath>
#include "encoder.hpp"

uint16_t shift(uint16_t x, int a) {
    if(a == 0)
        return 0;

    x = x >> abs(a);

    if(a < 0) {
        x = ~x;
    }

    return x;
}


const Coefficients lookup(uint16_t x, const Coefficients* lookupTable, IndexEncoder_t indexEncoder) {
    bit_t a, b, c, d, e, f;
    f = x & 1; e = (x >> 1) & 1; d = (x >> 2) & 1;
    c = (x >> 3) & 1; b = (x >> 4) & 1; a = (x >> 5) & 1;
 

    uint8_t lookupIndex = indexEncoder(a, b, c, d, e, f);
    return lookupTable[lookupIndex];
}


uint16_t approximateLog2(uint16_t x) {
    uint16_t shiftedX = x << 3;
    Coefficients coefficients = lookup((x & 0x3F0) >> 4, logCoefficients, logIndexEncoder);
    shiftedX = x13ToInt(adderTree(
        intToX13(shiftedX), 
        intToX13(coefficients.b),
        intToX13(shift(shiftedX, coefficients.a1)),
        intToX13(shift(shiftedX, coefficients.a2))
    ));

    return (shiftedX >> 3);
}

uint16_t approximateAntilog2(uint16_t  x) {
    uint16_t shiftedX = x << 3;
    Coefficients coefficients = lookup((x & 0x3F0) >> 4, antiLogCoefficients, antilogIndexEncoder);
    shiftedX = x13ToInt(adderTree(
        intToX13(shiftedX), 
        intToX13(coefficients.b),
        intToX13(shift(shiftedX, coefficients.a1)),
        intToX13(shift(shiftedX, coefficients.a2))
    ));

    return (shiftedX >> 3);
}