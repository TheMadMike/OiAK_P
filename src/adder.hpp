#ifndef ADDER_HPP
#define ADDER_HPP

#include <inttypes.h>

typedef bool bit_t;

struct Result {
    bit_t s : 1;
    bit_t c : 1;
};

struct X13 {
    bit_t bits[13];
};

Result fullAdder(bit_t x, bit_t y, bit_t cin);
Result halfAdder(bit_t x, bit_t y);

X13 adderTree(X13 a, X13 b, X13 c, X13 d);

struct CSA13Result {
    X13 sum;
    X13 carry;
};

CSA13Result csa13(X13 a, X13 b, X13 c);
X13 cpa13(X13 a, X13 b);

#define FA(x, y, cin) fullAdder(x, y, cin)
#define HA(x, y) halfAdder(x, y)

uint16_t x13ToInt(X13 x);
X13 intToX13(uint16_t x);


#endif //ADDER_HPP