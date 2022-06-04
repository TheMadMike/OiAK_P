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

FP16::FP16(float f) {
    uint32_t x = *((uint32_t*)&f);
    value = ((x>>16)&0x8000)|((((x&0x7f800000)-0x38000000)>>13)&0x7c00)|((x>>13)&0x03ff);
}

float FP16::toFloat() {
    float x = powf(2.0f, (float)(exponent - 15))*(1.0f + (((float)mantissa) / ((float)(1 << 9))));
    x *= sign ? -1.0f : 1.0f;
    return x;
}