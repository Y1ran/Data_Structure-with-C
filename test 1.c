
//Code test 2

#include <stdio.h>

int main(void)
{
    int day, month, year;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%4d", &month, &day, &year);
/*�������ʽ���ַ����ĸ�ʽӦһ��*/

    printf("You entered the date %4d%2.2d%2.2d\n", year, month, day);

    return 0;
}
