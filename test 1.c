
//Code test 2

#include <stdio.h>

int main(void)
{
    int day, month, year;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%4d", &month, &day, &year);
/*输入与格式化字符串的格式应一致*/

    printf("You entered the date %4d%2.2d%2.2d\n", year, month, day);

    return 0;
}
