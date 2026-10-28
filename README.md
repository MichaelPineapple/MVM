### MVM (Mcl Virtual Machine)
Highly simplified virtual machine for executing toy machine code.

Instruction Set:
```
100 _ _ -> NOP "Do nothing"
101 X Y -> SET "MEM[X] = Y"
102 X _ -> GET "MEM[X] = User Input"
103 X Y -> CPY "MEM[X] = MEM[Y]"
104 X Y -> ADD "MEM[X] = MEM[X] + MEM[Y]"
105 X Y -> SUB "MEM[X] = MEM[X] - MEM[Y]"
106 X Y -> MUL "MEM[X] = MEM[X] * MEM[Y]"
107 X Y -> DIV "MEM[X] = MEM[X] / MEM[Y]"
108 X _ -> OUT "Print MEM[X]"
109 X _ -> JMP "Goto instruction at address MEM[X]"
000 _ _ -> END "Terminate Program"
```
