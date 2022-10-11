// header protection
#ifndef BITMATH_H_
#define BITMATH_H_


#define read_bit(num, pos) ((num >> pos) & 1)
#define clear_bit(num, pos) (num &= ~(1 << pos))
#define set_bit(num, pos) (num |= (1 << pos))
#define toggle_bit(num, pos) (num ^= (1 << pos))



#endif