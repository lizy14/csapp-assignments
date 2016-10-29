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
the sign bit of `x` and `-x` are both `0` if and only if `x==0`.
* get the sign bit of `x`
* get the sign bit of `-x`
for 1-bit operand(s), we have
* `x||y == x|y`
* `!x   == (x+1) & 1`

## tmin
sign bit = 1, other bits = 0.

## fitsBits
* drop the right-most `n-1` bits
* check if the remaining part is all zero's or all one's

## divpwr2
`x >> n` works perfectly fine for positive dividends.
For negative dividends we have to take care of rounding manually:
* the remainder is the last `n` bits of the dividend; all we need is a mask
* if there is a non-zero remainder, we add `1` to the result

## negate
by definition, `-x == ~x + 1` for all `x` as integer

## isPositive
* check the sign bit
* exclude zero

## isLessOrEqual
Ignoring overflow, we have `x <= y` if and only if `y-x >= 0`, in which case we just look at the sign bit of the difference
For overflow scenario, we look at bit signs of both operands.

## ilog2

## float_neg

## float_i2f

## float_twice
