/***test***/

#include <stdio.h>
#define N 10
#ifdef N
#define C 11
#endif // N

int main(int argc, int *argv[])
{
    printf("count is %d, and parameter is:%d\n", argc, argv[1]);

    printf("%d", C);

    return 0;
}
