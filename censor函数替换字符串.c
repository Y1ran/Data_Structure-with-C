/**Substitute foo with xxx**/

/*string*/

#include <stdio.h>
#include <string.h>

#ifndef N
#define N 10
#endif

void censor(char *word);

int main(int argc, int *argv[])
{

    char *inputs[N];

    printf("Please enter words: \n");

    gets(*inputs);

    int i = 0;
    while (inputs[i] != '\0')
    {
        printf("\n");           // Only for test WHILE input;
        i++;
    }
    censor(*inputs);

    printf("the words after sub is: %s", *inputs);

    return 0;
}


void censor(char *word)
{
    //char *word[N];

    int i = 0, j;
    for (i = 0; i < N; i++)
    {
        if(word[i] == 'f' && word[++i] == 'o' && word[++i] == 'o')
        {
            for( j = i;j - i < 3;j++)
            {
                word[j - 2] = 'x';
            }
        }
    }
}
