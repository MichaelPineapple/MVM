#include <stdio.h>
#include <stdbool.h>

#define MEM_SIZE 100
char mem[MEM_SIZE];
char ptr = 0;

bool execute_instruction(int op, int x, int y)
{
    int d;
    switch (op)
    {
        case 100:
            // NoOp
            break;
            
        case 101:
            // Set
            mem[x] = y;
            break;
            
        case 102:
            // Get
            scanf("%d", &d);
            mem[x] = (char) d;
            break;
            
        case 103:
            // Cpy
            mem[x] = mem[y];
            break;
            
        case 104:
            // Add
            mem[x] = mem[x] + mem[y];
            break;
            
        case 105:
            // Sub
            mem[x] = mem[x] - mem[y];
            break;
            
        case 106:
            // Mul
            mem[x] = mem[x] * mem[y];
            break;
            
        case 107:
            // Div
            mem[x] = mem[x] / mem[y];
            break;
            
        case 108:
            // Out
            printf("%d\n", mem[x]);
            break;
            
        case 109:
            // Jmp
            ptr = mem[x];
            break;
            
        default:
            printf("Unknown OpCode: %d\n", op);
        case 0:
            return false;
    }
    return true;
}

int main(int argc, char const* argv[])
{
    for (int i = 0; i < MEM_SIZE; i++) mem[i] = 0;
    FILE* file = fopen(argv[1], "r");
    fgets(mem, MEM_SIZE, file);
    bool loop = true;
    while (loop)
    {
        int op = (char) mem[ptr];
        int x = (char) mem[ptr + 1];
        int y = (char) mem[ptr + 2];
        ptr += 3;
        if (!execute_instruction(op, x, y)) loop = false;
    }
    return 0;
}
