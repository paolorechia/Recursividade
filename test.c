#include <stdio.h>
#include <stdlib.h>

int durp(int * x, int * y)
{
    return ((*x) + (*y));
}

int main(int argc, char * argv[])

{
    int x = 5;
    int y = 3;
    printf("%d\n", durp(&x, &y));
    return 0;
}
