# Data Lab: Buffer Overflow

Zhaoyang Li, 2014013432

Nov. 8, 2016

## Level 0

With debugger and disassembler, we know that within `getbuf`, the buffer can be refered to as `$ebp-0x28`, while the return address can be refered to as `$ebp+0x4`.

Thus, in order to modify return address at `$ebp+0x4`, our explot string consists of `0x28+0x4 = 44` bytes of arbitary characters, followed by the address of the targeted `smoke`, which is `0x08048b04`.

## Level 1

44 bytes of arbitary characters as in level 0. Then the address of `fizz`, which is `0x08048b2e`. 

The argument accessed by `fizz` can be refered to as `$ebp+0xC` within `getbuf`. So we need another 4 bytes of arbitary characters, then the cookie.

## Level 2

`global_variable` is located at `0x804e10c`, revealed by instructions within `bang`. We need a `mov` instruction to change its value, then `push` the address of `bang`, followed by a `ret`. This should be able to take us to `bang`.

I chose to put these instructions at the beginning of the buffer, which within `getbuf` is refered to as `$ebp-0x28`, which is `0x55683a58`, which is the new return address to be put at `$ebp+0x4`.

In conclusion, our exploit code starts with machine code of instructions

	0:  c7 05 0c e1 04 08 da    mov    DWORD PTR ds:0x804e10c,0x2b1487da
	7:  87 14 2b
	a:  68 82 8b 04 08          push   0x8048b82
	f:  c3                      ret

followed by some bytes of arbitary characters, making the following `0x55683a58` the 45th byte in the string.

## Level 3

* `mov` the cookie into `eax`,
* restore stack frame by `mov`ing the desired address into `ebp`,
* `push` and `ret` instructions to take us back to the caller, with the address of the next instruction of the `call` in `test`.

The exploit code starts with machine code of instructions

	0:  b8 da 87 14 2b          mov    eax,0x2b1487da
	5:  bd b0 3a 68 55          mov    ebp,0x55683ab0
	a:  68 f3 8b 04 08          push   0x8048bf3
	f:  c3                      ret

followed by some bytes of arbitary characters, making the following `0x55683a58` the 45th byte in the string.

## Level 4

* `mov` the cookie into `eax`,
* restore stack frame with an `lea` instruction to load the desired address,,
* `push` and `ret` instructions to take us back to the caller.

Code snippet:

	0:  b8 da 87 14 2b          mov    eax,0x2b1487da
	5:  8d 6c 24 28             lea    ebp,[esp+0x28]
	9:  68 67 8c 04 08          push   0x8048c67
	e:  c3                      ret
	f:  90                      nop

where I inserted an adittional `nop` to make the snippet 16 bytes, since I'm not good at math.

The buffer is refered to within `getbufn` as `$ebp-0x208`.  We need `nop` from this point. Since I decided to put the snippet right below the return address at `$ebp+0x4`, total number of `nop`'s needed is `0x208+0x4-0x10 = 508`. 

In conclution, the exploit string consists of 508 `nop`'s, followed by the code snnipet, then the address of the snippet `$ebp-0x8 = 0x556838c8`.
