#ifndef LNS_HPP
#define LNS_HPP

#include "fp16.hpp"

/**
 * @brief Divides the two half precision floats
 * 
 * @param a dividend
 * @param b divisor
 * @return float a / b
 */
float LDIV(FP16 a, FP16 b);
/**
 * @brief Multiplies the two half precision floats 
 * 
 * @param a first operand
 * @param b second operand
 * @return float a * b
 */
float LMUL(FP16 a, FP16 b);
/**
 * @brief Calculates the square root of half precision float
 * 
 * @param a 
 * @return float sqrt(a)
 */
float LSR(FP16 a);
/**
 * @brief Caclulates the inverse square root of half precision float
 * 
 * @param a 
 * @return float 1 / sqrt(a)
 */
float LISR(FP16 a);

#endif //LNS_HPP