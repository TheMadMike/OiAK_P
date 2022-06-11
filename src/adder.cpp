#include "adder.hpp"

Result fullAdder(bit_t x, bit_t y, bit_t cin) {
    return { x ^ y ^ cin, ((x ^ y) & cin) | (x & y) };
}

Result halfAdder(bit_t x, bit_t y) {
    return { x ^ y, x & y };
}

X13 adderTree(X13 a, X13 b, X13 c, X13 d) {
    CSA13Result csa1Result = csa13(b, c, d);
    CSA13Result csa2Result = csa13(csa1Result.carry, csa1Result.sum, a);
    return cpa13(csa2Result.carry, csa2Result.sum);
}

CSA13Result csa13(X13 a, X13 b, X13 c) {
    CSA13Result r;
    r.carry.bits[0] = 0;

    for(uint8_t i = 0; i < 13; ++i) {
        Result result = FA(a.bits[i], b.bits[i], c.bits[i]);
        if(i < 12) { 
            r.carry.bits[i+1] = result.c;
        }
        r.sum.bits[i] = result.s;
    }

    return r;
}

X13 cpa13(X13 a, X13 b) {
    bit_t carry = 0;
    X13 sum;

    for(uint8_t i = 0; i < 13; ++i) {
        Result result = FA(a.bits[i], b.bits[i], carry);
        sum.bits[i] = result.s;
        carry = result.c;
    }

    return sum;
}

uint16_t x13ToInt(X13 x) {
    uint16_t output = 0;
    
    for(uint8_t i = 0; i < 13; ++i) {
        output |= x.bits[i] << i;
    }

    return output;
}

X13 intToX13(uint16_t x) {
    X13 output;

    for(uint8_t i = 0; i < 13; ++i) {
        output.bits[i] = ((x >> i) & 1);
    }

    return output;
}