#include "fp16.hpp"
#include "log.hpp"
#include <cstdio>
#include <cmath>

int main(void) {
    FP16 f(1.5f);
    float l = log2f((float) f);
    printf("%f \n", l);
    uint16_t x = approximateLog2(f.mantissa);

    FP16 result(1.0f);  
    result.mantissa = x;
    printf("%f \n", (float)result - 1.0f);

    x = approximateAntilog2(result.mantissa);
    result.mantissa = x;
    printf("%f \n",(float)result - 1.0f);
}