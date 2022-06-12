#include "encoder.hpp"
#include "and.hpp"

uint8_t logIndexEncoder(bit_t a, bit_t b, bit_t c, 
                        bit_t d, bit_t e, bit_t f) {
    uint8_t lookupIndex = 0;
    lookupIndex |= 
        AND(!c, d, e) 
        | AND(!b, c, !d)
        | AND(c, !d, !e)
        | AND(a, b, c)
        | AND(!a, b, !c, d)
        | AND(b, !c, d, f)
        | AND(a, !b, !c, d)
        | AND(!a, b, !c, e, f)
        | AND(a, !b, !c, e, f);

    lookupIndex |= (
        AND(b, !c)
        | AND(a, b)
        | AND(!b, c, d)
        | AND(b, !d, !e)
    ) << 1;

    lookupIndex |= (
        a
        | AND(b, c, e)
        | AND(b, c, d)
    ) << 2;


    return lookupIndex;
} 

uint8_t antilogIndexEncoder(bit_t a, bit_t b, bit_t c, 
                            bit_t d, bit_t e, bit_t f) {
    uint8_t lookupIndex = 0;

    lookupIndex |=
        AND(c, d)
        | AND(!a, !b, c, e)
        | AND(b, !c, !d, !e)
        | AND(b, c, e, f)
        | AND(a, !b, !c, !d)
        | AND(a, !c, !d, !f);

    lookupIndex |= (
        AND(b, d)
        | AND(b, c)
        | AND(!a, b, e)
        | AND(b, e, f)
        | AND(a, !b, !c, !d)
    ) << 1;

    lookupIndex |= (
        AND(a, d)
        | AND(a, c)
        | AND(a, b)
    ) << 2;


    return lookupIndex;
}