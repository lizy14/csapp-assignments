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
Adds neighboring bits together in groups of 1, then 2, then 4, up to 32, in 5 steps.
reference: http://stackoverflow.com/a/3815253

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
* "fold" the upper bits into the lower bits to construct a bit vector with the same most significant 1 as x, but all 1's below it
* then count number of 1's
reference: http://stackoverflow.com/a/21442682

## float_neg
* get a mask for the sign bit
* toggle the sign bit
* check if the input is NaN. is so, revert changes

## float_i2f

## float_twice
