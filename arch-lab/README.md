# csapp arch-lab
Zhaoyang Li, 2014013432

## Part B
### `iaddl` instruction

    fetch
    	icode:ifun <- M_1[PC]
    	rA:rB <- M_1[PC+1]
    	valC <- M_4[PC+2]
    	valP <- PC+6
    decode
    	valB <- R[rB]
    execute
    	valE <- valB+valC
    memory
    	/
    write back
    	R[rB] <- valE
    PC update
    	PC <- valP


### `leave` instruction

    fetch
    	icode:ifun <- M_1[PC]
    	valP <- PC+1
    decode
    	valA <- R[%ebp]
    	valB <- R[%ebp]
    execute
    	valE <- valB+4
    memory
    	valM <- M_4[valA]
    write back
    	R[%esp] <- valE
    	R[%ebp] <- valM
    PC update
    	PC <- valP


## Remarks

Compared to the previous data- and buffer-lab, I feel that this one is the easiest.

In this lab, I got familiar with Y86 and HCL. I had a better understanding of how instructions are executed, especially the concepts of stages and pipelining.
