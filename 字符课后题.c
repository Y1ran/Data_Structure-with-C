/*循环和字符课后习题
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    unsigned int i,k;
    unsigned int in_put;

    printf("Please enter a number: \n");
    scanf("%d", &in_put);

    //i = in_put;
    //k = 1;

    for( k = 1; k <= in_put / k; k++){
        //i = k * k;
        //printf("%d \n", i);
        //k++;

        switch( k % 2 ){
        case 0:
        i = k * k;
        printf("%d \n", i);
        case 1:
            continue;
            //i--;
        default: printf("Please enter a valid number\n");
            break;

        if(i >= in_put)
            break;
        }
    }
    /*int a;
    for( a = 1; a <= in_put;a++){

        i = a * a;
        printf("%d \n", i);

        if(i > in_put)
            break;
    }*/

    /*
    }*/

    return 0;
}
