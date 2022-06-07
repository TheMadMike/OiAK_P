#ifndef LOG_HPP
#define LOG_HPP

#include <inttypes.h>

/**
 * @brief Implements functionality of the fused converter
 * 
 * @param x e.g. 10-bit mantissa
 * @return uint16_t log2(1 + x) or antilog2(1 + x)
 */
uint16_t approximateLog2(uint16_t x);
uint16_t approximateAntilog2(uint16_t x);

struct Coefficients {
    uint16_t upperLimit;
    int a1, a2;
    uint16_t b;
};

const Coefficients lookup(uint16_t x, const Coefficients* lookupTable);

const Coefficients logCoefficients[] = {
    {95, 1, -3, 13},
    {191, 2, 6, 98},
    {303, 3, 5, 269},
    {415, 4, 0, 501},
    {559, -6, 0, 763},
    {703, -3, 6, 1178},
    {847, -2, 4, 1622},
    {1023, -2, 0, 2055} 
};

const Coefficients antiLogCoefficients[] = {
    {159, -2, -6, 8188},
    {287, -2, 4, 8085},
    {431, -3, 6, 7898},
    {575, -5, 0, 7625},
    {703, 4, 6, 7123},
    {815, 3, 5, 6680},
    {943, 2, 6, 5964},
    {1023, 1, -3, 5131}
};

#endif //LOG_HPP