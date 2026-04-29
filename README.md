# ALU Modules

| What it is

This project is the collection of PCB that make up all of the Intel 8080 (Which is what my CPU is based on) ALU's functionality. \
It contains modules for an 8 bit adder, subtractor, AND, OR, XOR, rotate left, and rotate right. Also it has a NOT module for the CMA instruction, which inverts all the bits in the accumulator register. \
Also coincidentally there are 8 modules, which will make multiplexing to choose data lines really nice and easy! If I ever decide to create the module for DAA, which I don't have atm because im kinda lazy and I think it'll be seldom used, I can alway make the NOT module not on the multiplex because it is exclusively used to invert the accumulator register for CMA and nothing else.

| Why I made it

Most of my reasoning can be found in the [RAM Module readme](https://github.com/SABRINIAC/DelayLineRAM-ShiftRegister) but aside from that I made this so I can do what CPUs are really good for. Math! These modules alone, making up the ALU, accounts for 96 out of the 255 instructions my CPU needs. Over a third at 37.6%! \
I don't think another project will get even close to implementing that many instructions! They would need a combination of making registers, and routing on the motherboard; which tbf the ALU also needs that. \

Also, making a computer out of pure transistors sounds really cool! Getting to learn how to make logic gates with them was fun, but I don't think I've fully committed how they precisely work to my brain yet... maybe later on in this project.

| Pictures


| BOM + Quantity

You can see a greater breakdown in BOM.md, but here the table breakdown
| Part Name | Count |
|-----------|-------|
| 1x2 Male Pin Headers | 99 |
| 2N2222 NPN Transistors | 432 |
| 1kΩ Resistor 0603 SMD | 670 |
| Adder PCB | 1 |
| Subtractor PCB | 1 |
| AND PCB | 1 |
| XOR PCB | 1 |
| OR PCB | 1 |
| NOT PCB | 1 |
| Rotate Right PCB | 1 |
| Rotate Left PCB | 1 |
