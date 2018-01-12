/***判断回文数***/

//情况2.判断数字回文
//利用数字的数值方法进行回文判断


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//此方法可以直接嵌入main函数中，不需要声明额外函数
int main(int argc, char *argv[])
{

    printf("Please enter the number to judge:\n");

    int Inp;   //将INP作为一个保存初始变量的整型，用于循环后的判断
    scanf("%d", &Inp);      //将STDIN格式化输入INP中，举个例子a=1234

    int sum  = 0;
    int Calcul;
    Calcul = Inp;   //声明另一个CALCUL变量并将初始值赋给它，其在循环中将会用以判断并发生改变

    while(Calcul != false)
    {
        sum = sum * 10 + Calcul % 10;//第一次等式为sum=0*10+1234%10(其实值就是4)=4，
                    //第二次等式为sum=4*10+123%10(其实值为3)=43，第三次等式为sum=43*10+12%10
                   //(其实值为2)=432,第四次sum=432*10+1%10(其实为1)=4321
        Calcul /= 10;
//第一次等式为Calcul=1234/10=123第二次Calcul=123/10=12第三次Calcul=12/10=1,第四次Calcul=1/10=0;
    }

    if (sum == Inp)
    {
        printf("this is a palindrome");
    }

    else{printf("this is not a palindrome");
    }

    return 0;
}
