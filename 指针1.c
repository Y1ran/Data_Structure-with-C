#include <stdio.h>
#include <ctype.h>

/******


void decompose(float x, int *part, float *frac);

int main(void)
{

    float i, *c;
    int *b;

    float h;
    int g;

    c = &h;
    b = &g; //

    scanf("%f", &i);


    decompose(i, b, c); //
    //i = (float)i;
    //scanf("%f", b);


    //scanf("%f", &i);
    //i = 3;

    printf("%d\n%f",*b,*c);

    return 0;

}

void decompose(float x, int *part, float *frac)
{
    *part = (int) x;
    *frac = x - *part;
}**************************/

//��������

#define N 10
void change(int a[]);

int main(void)
{
    int a[N], i;

    for(i = 0; i < N; i++)
    {
        a[i] = i;
        printf("[%d]_", a[i]);

    }

    change(a);

        for(i = 0; i < N; i++)
    {
        printf("[%d]_", a[i]);

    }                                //
}

void change(int a[])
{
    int i;

    for(i = 0; i < N; i++)
    {
        a[i] = i + 1;
        //printf("%d \n", a[i]);

    }
    printf("\n");
    printf("After change (+1 order) :\n");
}
