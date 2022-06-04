#include "fp16.hpp"
#include <cmath>

union fp32 {
    float v;

    struct {
        uint32_t m : 23;
        uint32_t e : 8;
        bool s : 1;
    };

};

FP16::FP16(uint16_t value) 
:value(value){
}

FP16::FP16(float x) {
    fp32 fp;
    fp.v = x;
    sign = fp.s;
    mantissa = (uint16_t)((fp.m & 0b11111111110000000000000) >> 13);
    exponent = (uint16_t) (fp.e >> 3);
}

FP16::operator float() {
    float f = powf(2.0f, (float)(exponent - 15)) * (1.0f + ((float)mantissa / 1024.0f));
    f *= sign ? -1 : 1;
    return f;
}