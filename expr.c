#include <stdio.h>

int main(void)
{
    int in_put, out_put, i, j, k;

    printf("Enter a two digit number: \n");
    scanf("%d", &in_put);

    printf("Reversing... \n");


    if (in_put/100 >= 1 || in_put/100 <= -1) {
        i = (in_put - in_put % 100) / 100;
        j = (in_put - in_put % 10) / 10 - i * 10;
        k = in_put % 10;
        printf ("the reversal is: %d%d%d", k, j, i);
    }

    else {
        i = (in_put - in_put % 10) / 10;
        j = in_put % 10;
        printf("the reversal is: %d%d", j, i);
    }

    return 0;
}
