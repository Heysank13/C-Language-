#include <stdio.h>
#include <sys/types.h>
void main()
{
    int a = 100;
    if (fork() == 0)
    { // child code
        a = a + 5;
        printf("\n%d %p", a, &a);
    }
    else
    { // parent code
        a = a - 5;
        printf("\n%d %p\n", a, &a);
    }
}