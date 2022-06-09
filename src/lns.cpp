#include "lns.hpp"
#include <cmath>
#include "log.hpp"

float LDIV(FP16 a, FP16 b) {
    float result;
    uint16_t k1 = approximateLog2(a.mantissa);
    uint16_t k2 = approximateLog2(b.mantissa);
    
    float m;

    if(k2 > k1) {
        m = (1.0f / (approximateAntilog2(k2 - k1) / 1024.0f)); 
    } else {
        m = approximateAntilog2(k1 - k2) / 1024.0f;
    }

    result = powf(2.0f, (float)(a.exponent - b.exponent))*m;
    result *= (a.sign ^ b.sign) ? -1.0f : 1.0f;

    return result;
}

float LMUL(FP16 a, FP16 b) {
    float result;
    uint16_t k1 = approximateLog2(a.mantissa);
    uint16_t k2 = approximateLog2(b.mantissa);

    float m;
    m = approximateAntilog2((k1 + k2) & 1023) / 1024.0f;

    result = powf(2.0f, (float)(a.exponent + b.exponent - 30))*m - 0.5f;
    result *= (a.sign ^ b.sign) ? -1.0f : 1.0f;

    return result;
}

float LSR(FP16 a) {
    float result;
    uint16_t k1 = approximateLog2(a.mantissa);

    float m = approximateAntilog2(k1) / 1024.0f;
    m = powf(m, 0.5f);

    result = powf(2.0f, 0.5f*(a.exponent) - 7.5f)*m;

    return result;
}

float LISR(FP16 a) {
    float result;
    uint16_t k1 = approximateLog2(a.mantissa);

    result = powf(2.0f, -0.5f*(a.exponent + k1/1024.0f) + 7.5f);

    return result;
}