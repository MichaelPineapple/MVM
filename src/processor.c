#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#include "headers/processor.h"
#include "headers/interfaceFunctions.h"

#define MEMORY_SIZE 100
int MEMORY[MEMORY_SIZE];

int executeInstruction(int op, int x, int y)
{
    int out = 0;
    switch (op)
    {
        case 0:
            // NoOp
            break;
            
        case 1:
            // Set
            MEMORY[x] = y;
            break;
            
        case 2:
            // Get
            printf("%d", MEMORY[x]);
            break;
            
        case 3:
            // Cpy
            MEMORY[x] = MEMORY[y];
            break;
            
        case 4:
            // Add
            MEMORY[x] = MEMORY[x] + MEMORY[y];
            break;
            
        case 5:
            // Sub
            MEMORY[x] = MEMORY[x] - MEMORY[y];
            break;
            
        case 6:
            // Mul
            MEMORY[x] = MEMORY[x] * MEMORY[y];
            break;
            
        case 7:
            // Div
            MEMORY[x] = MEMORY[x] / MEMORY[y];
            break;
            
        case 8:
            // CLS
            clearScreen(x);
            break;
            
        default:
            printf("Error: Unknown OpCode!");
        case -1:
            out = -1;
    }
    return out;
}

void processorStart()
{
    for (int i = 0; i < MEMORY_SIZE; i++) MEMORY[i] = 0;
    
    bool loop = true;
    while (loop)
    {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        int result = executeInstruction(op, x, y);
        
        switch (result)
        {
            case 0:
                break;
                
            default:
                printf("Error: Unknown Result Code!");
            case -1:
                loop = false;
        }
        printf("\n");
    }
}
