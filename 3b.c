#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fs1, *fs2, *ft;
    char ch;
    fs1 = fopen(argv[1], "r");
    fs2 = fopen(argv[2], "r");
    ft = fopen(argv[3], "w");

    if (fs1 == NULL || fs2 == NULL || ft == NULL)
    {
        printf("Could not open files");
        exit(0);
    }

    while (1)
    {
        ch = fgetc(fs1);
        if (ch == EOF)
            break;
        else
            fputc(ch, ft);
    }

    while (1)
    {
        ch = fgetc(fs2);
        if (ch == EOF)
            break;
        else
            fputc(ch, ft);
    }
    printf("Merged fs1 and fs2 into ft.");
    fclose(fs1);
    fclose(fs2);
    fclose(ft);
}