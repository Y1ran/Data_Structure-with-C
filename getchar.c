
#include <stdio.h>
#include <ctype.h>


/*测试\n判断（即用户输入回车后的命令
int main(void){

char i;
char command;
printf("enter:\n");

scanf("%d", &i);

printf("enter:\n");

printf("the number you enter is : %c", command = getchar());

return 0;
}
*/

//计算输入字符长度
int main(void)
{
    char ch;
    int len = 0;

    printf("enter your message: \n");
    //ch = getchar();

    for (;ch != '\n'; len ++){
        ch = getchar();
    }

    printf("your message is %d long \n", len);

    return 0;
}
