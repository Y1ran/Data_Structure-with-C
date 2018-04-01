#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <ctype.h>

typedef char  Pre_;         //方便做数字回文时更改类型

bool Judge_char(const char *p); //声明一个布尔型变量的函数原型

int main(int argc, char *argv[])
{

    printf("Please enter the chars to judge:\n");

    bool re_value = 0;  //初始化逻辑变量
    char *k;
    scanf("%s", k);   //声明一个字符串指针，并将STDIN传入

    re_value = Judge_char(k);

    if (re_value){
        printf("This charset is Palindrom");
    }
    else {
        printf("this charset is not Palindrom");     //判断命题真假并输出结果
    }
    return 0;
}

bool Judge_char(const char *p)
{
    register int i = 0;      //计数变量初始化
    int len = strlen(p); //使用STRLEN函数取字符串数组的字符位数

    //注意此处STRLEN与SIZEOF的使用方法区别，后者返回参数的所占空间大小并包含空字符'\0'大小
    //在STRLEN原型中传入的参数是const指针而不是*p对象

    for (i = 0; i <= len/2; i++)
    {
        if (p[i] == p[len - 1])
        {
            len--; //若首尾两个字符等值，分别向字符串中心移动一位，并判断
        }
        else
        return false;
    }

    return true;
}
