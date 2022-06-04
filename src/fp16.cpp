#include "fp16.hpp"

union fp32 {
    float v;

    struct {
        uint32_t m : 23;
        uint32_t e : 5;
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
    exponent = fp.e & 0b11111;
}

FP16::operator float() {
    fp32 fp;
    fp.s = sign;
    fp.e = exponent;
    fp.m = ((uint32_t)mantissa) << 13;

    return fp.v;
}