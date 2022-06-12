#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <inttypes.h>

typedef bool bit_t;

/**
 * @brief Implements functionality of the logarithm segment index encoder
 */
uint8_t logIndexEncoder(bit_t a, bit_t b, bit_t c, 
                        bit_t d, bit_t e, bit_t f);

/**
 * @brief Implements functionality of the antilogarithm segment index encoder
 */
uint8_t antilogIndexEncoder(bit_t a, bit_t b, bit_t c, 
                            bit_t d, bit_t e, bit_t f);

typedef uint8_t (*IndexEncoder_t)(bit_t, bit_t, bit_t, bit_t, bit_t, bit_t);

#endif //ENCODER_HPP