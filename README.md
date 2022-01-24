This program allows the user to simulate what happens within a single-datapath
processor in a MIPS ISA.

To start the program, the user may add whatever values they would
like to test to the MEM[] and PC_REGS[] arrays in the components.cpp file
(which simulate the memory and registers, respectively).

For the PC_REGS, array indexes of [0-9] represent registers $r1-$r10.
For memory, the user must access it by entering numbers divisible by 4.
0-36 represent memory slots $s1-$s10.
    For clarification:

      lw and sw instructions should be written in the following format:
            lw/sw $r(register#), (number in mem)

After the user has inputted the desired values in the memory and registers, the
user can run the program. They will be asked to input their values, and
registers in the same way they would in MIPS (exceptions detailed within this
README). User can enter "stop" when they would like to stop inputting commands.

If the inputs are valid, then the instructions get written to the "output.txt"
file, with each operation entered. When the user indicates they are done
inputting commands, the data will run through the code informing the user of
where it currently is within the processor, and what it is doing. At the end,
the result will be written to memory and/or the register file.

In the case of a beq operation, the user will enter the two registers
they would like to compare, as well as the line of the output file they would
like to jump and write to, if the registers are equal. If the registers are
equal, then "HERE: " will be written to the line in the output file specified
by the user after making the comparison, to prove a jump has occurred. Then, the
instruction jumps back to where it was, and the next instruction after the
jump gets processed.
    For clarification:

        jump instructions should be written in the following format:
            j (line to jump back to)
        beq instructions should be written in the following format:
            beq $(register #), $(register #), (line to jump back to)

After all instructions are performed, then the results of the memory and
registers are displayed. The user may also view the results of the instructions
and any jumps made in the output.txt file.

NOTE:

    Jumps may not exceed the current size of the output file. For this
    reason, only backward jumps may be performed. Otherwise, the user is
    notified with the error: "JUMP NOT FOUND..."

    For the "mul" operation (contrary to MIPS's ACTUAL multiplication
    operation "mult"), hi/lo need not be specified (the assignment instructions
    specify the support of a "mul" operation, and doesn't say that a
    hi/lo operation need be included) the user may enter it in the same way
    they would many other ALU instructions:

        mul $r(register # to hold result), $r(register # to multiply),
                                $r(register # to multiply)

    All other instructions, other than exceptions specified above,
    may be entered the exact way they would be in a MIPS environment.
