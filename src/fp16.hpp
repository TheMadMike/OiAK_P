#ifndef FP_16_HPP
#define FP_16_HPP

#include <inttypes.h>

/**
 * @brief Stores a half-precision (16bit) floating point number
 */
class FP16 {

public:
    FP16(uint16_t value= 0);
    FP16(float x);

    explicit operator float();

    union {
        uint16_t value;
        struct {
            uint16_t mantissa: 10;
            uint16_t exponent: 5;
            bool sign: 1;
        };
    };

};

#endif //FP_16_HPP