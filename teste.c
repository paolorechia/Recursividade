#include <stdio.h>

void print_matrix(int * pter, int size){
    if (size == -1)
    {
        putchar('\n');
        return;
    }
    printf("%d ", *(pter+size));
    print_matrix(pter, --size);
    return;
}

int main()
{
    int mat[2][2] = {{1,2},{3,4}};
    int *p = &mat[0][0];
    int i;
    for (i=0;i<4;i++)
        printf("%d\n",*(p+i));
    print_matrix(p, 3);
    return 0;
}
