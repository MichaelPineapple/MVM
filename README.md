### MVM (Mcl Virtual Machine)
Highly simplified virtual machine for executing toy machine code.

Instruction Set:
```
100 _ _ -> NOP (Do nothing)
101 X Y -> SET (Value at address X set to value Y)
102 X _ -> GET (Value at address X set to user provided input)
103 X Y -> CPY (Value at address X set to value at address Y)
104 X Y -> ADD (Value at address X set to value at address X plus value at address Y)
105 X Y -> SUB (Value at address X set to value at address X minus value at address Y)
106 X Y -> MUL (Value at address X set to value at address X multiplied by value at address Y)
107 X Y -> DIV (Value at address X set to value at address X divided by value at address Y)
108 X _ -> OUT (Print value at address X)
109 X _ -> JMP (Set instruction pointer to value at address X)
000 _ _ -> END (Terminate program)
```
