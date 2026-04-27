| What operations there are and their function
[Instruction Descriptions On Wikipedia](https://en.wikipedia.org/wiki/Intel_8080#Instruction_set) \

INR: Increment Register \
DCR: Decrement Register \
RLC: Accumulator << 1 ; Both the LSB and the Carry flag become old MSB \
RAL: Accumulator << 1 ; Carry flag becomes the old MSB ; LSB becomes the old Carry flag \
DAA: \
STC: Sets the carry flag to `1` | Don't include in the ALU? We can just modify the flag register? \
RRC: Accumulator >> 1 ; Both the MSB and Carry flag become the old LSB \
RAR: Accumulator >> 1 ; Carry flag becomes the old LSB ; MSB becomes the old carry flag \
CMA: Bitwise NOT on the current Accumulator ; Accumulator = !Accumulator \
CMC: Invert the carry flag | Don't include in the ALU? We can just modify the flag register? \
ADD + ADI: Add argument to the accumulator \
ADC + ACI: Add argument plus the carry flag to the accumulator \
SUB + SUI: Subtract the argument from the accumulator \
SBB + SBI: Subtract the argument and the carry flag from the accumulator \
ANA + ANI: Bitwise AND the argument with the accumulator \
XRA + XRI: Bitwise XOR the argument with the accumulator \
ORA + ORI: Bitwise OR the argument with the accumulator \
CMP + CPI: Accumulator minus the argument, but only changes flags \


| Circuits Needed

RLC: Accumulator << 1 ; Both the LSB and the Carry flag become old MSB \
RAL: Accumulator << 1 ; Carry flag becomes the old MSB ; LSB becomes the old Carry flag \
DAA: \
STC: Sets the carry flag to `1` | Don't include in the ALU? We can just modify the flag register? \
RRC: Accumulator >> 1 ; Both the MSB and Carry flag become the old LSB \
RAR: Accumulator >> 1 ; Carry flag becomes the old LSB ; MSB becomes the old carry flag \
CMA: Bitwise NOT on the current Accumulator ; Accumulator = !Accumulator \
CMC: Invert the carry flag | Don't include in the ALU? We can just modify the flag register? \


~Adder; For INR, ADD, ADI, ADC, and ACI~ \
~Subtractor; For DCR, SUB, SUI, SBB, SBI, CMP, and CPI~ \
Bitwise AND; For ANA, and ANI \
Bitwise XOR; For XRA, and XRI \
Bitwise OR; For ORA, and ORI \
