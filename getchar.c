
#include <stdio.h>
#include <ctype.h>


/*����\n�жϣ����û�����س��������
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

//���������ַ�����
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
