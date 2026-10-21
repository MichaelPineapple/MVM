#include <stdio.h>

int main(int argc, char const* argv[])
{
    FILE* file = fopen(argv[1], "w");
    while (1)
    {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        fputc((char)op, file);
        fputc((char)x, file);
        fputc((char)y, file);
        fflush(file);
    }
    return 0;
}
