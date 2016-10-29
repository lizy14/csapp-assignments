# CSAPP
Zhaoyang Li, 201401342

## bitAnd
De Morgan's law.

## getByte
* perform a right-shift
* get the least significant byte with a mask
we cannot change the order, unless we know the right-shift is logical.

## logicalShift
* perform a right-shift, without considering whether or not it's logical
* clear the higher bits with a mask

## bitCount

## bang
the most significant bit of `x` and `-x` are both `0` if and only if `x==0`.
* get the msb of `x`
* get the msb of `-x`
for 1-bit operand(s), we have
* `x||y == x|y`
* `!x   == (x+1) & 1`

## tmin
msb = 1, other bits = 0.

## fitsBits

## divpwr2

## negate
by definition, `-x == ~x + 1` for all `x` as integer

## isPositive
* check the sign bit
* exclude zero

## isLessOrEqual

## ilog2

## float_neg

## float_i2f

## float_twice
