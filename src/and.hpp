#ifndef AND_HPP
#define AND_HPP


bit_t AND(bit_t a, bit_t b, bit_t c, bit_t d, bit_t e) {
    return a & b & c & d & e;
}

bit_t AND(bit_t a, bit_t b, bit_t c, bit_t d) {
    return AND(a, b, c, d, 1);
}

bit_t AND(bit_t a, bit_t b, bit_t c) {
    return AND(a, b, c, 1);
}

bit_t AND(bit_t a, bit_t b) {
    return AND(a, b, 1);
}


#endif //AND_HPP