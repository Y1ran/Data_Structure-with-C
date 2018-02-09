
/***代码复现与测试***/

/**最长公共子序列**/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#ifndef size_c
#define size_c 200
#endif // size_c

//这里定义两个数组用来表示规划表
//int char1[], char2[]

#define EQUAL 0
#define UP 1
#define LEFT 2 //定义路径标识

/**函数LCS_LEN传入两个代表源字符串的指针，以及两个待装数组
函数功能:
1. 实现算法主要功能，即状态转移与计算，并返回长度
2. 将计算值放入char1，路径值放入char2**/
int Lcs_len(char *str1, char *str2, int **char1, int **char2);

/**函数print传入其中一个源字符串，以及路径数组
/i和j为已装配数组的边界长度(m,n
功能：打印出按照路径索引的字符序列*/
void Print_Lcs(char *str1, int **char2, int i, int j);

/**函数FIND允许STDIN录入字符串（两个）并调用前两个函数*/
void Find_Lcs(char *str1, char *str2, int len1, int len2);

int main(int *argc, char *argv[])
{
    char X[size_c], Y[size_c];

    printf("Please enter your string for compara...\n");
    scanf("%s", X);

    printf("Please enter your string for compara...\n");
    scanf("%s", Y);

    while( strlen(X) > size_c)
    {
        printf("what you entered is too long, please retry:\n");
        scanf("%s", X);
    }
    while( strlen(Y) > size_c)
    {
        printf("what you entered is too long, please retry:\n");
        scanf("%s", Y);
    }

    int len1 = strlen(X),
        len2 = strlen(Y);

    Find_Lcs(X, Y, len1, len2);
    printf("\n");

    system("pause");

    return 0;
}

int Lcs_len(char *str1, char *str2, int **char1, int **char2)
{
    //初始化边界条件
    int m = strlen(str1);
    int n = strlen(str2);

    int i, j, lenth;

    for(i = 0; i <= m; i++)
    {

        char1[i][0] = 0;
    }

    for(j = 0; j <= n; j++) //初始化边界条件
    {
        char1[0][j] = 0;
    }

    //如果从0开始，则i-1的初始转移将为定义(<0)
    for( i = 1; i < m + 1; i++)
    {
        for( j = 1; j < n + 1; j++)
        {
            if(str1[i - 1] == str2[j - 1])
            {
                char1[i][j] = char1[i-1][j-1] + 1;
                char2[i][j] = EQUAL;

            }
            else if(char1[i - 1][j] >= char1[i][j - 1])
            {
                char1[i][j] = char1[i - 1][j];
                char2[i][j] = UP;
            }
            else
            {
                char1[i][j] = char1[i][j - 1];
                char2[i][j] = LEFT;
            }
        }
    }

    if(char1){

        lenth = char1[m][n];
    }

    return lenth;
}


void Print_Lcs(char *str1, int **char2, int m, int n)
{
    //根据路径打印出公共子序列

    if( m == 0 || n == 0){
        return;
    }
    if( char2[m][n] == EQUAL )
    {
        Print_Lcs(str1, char2, m - 1, n -1);
        printf("%c ", str1[m - 1]);
    }
    else if( char2[m][n] == UP)
    {
        Print_Lcs(str1, char2, m - 1, n);
    }
    else
        Print_Lcs(str1, char2, m , n - 1);

}


void Find_Lcs(char *str1, char *str2, int len1, int len2)
{
    //申请二维数组
    int i, j, lenth;


    //为数组的一维申请一块纵向内存空间

    int **char1 = (int **)malloc(sizeof(int*) * (len1 + 1));
    int **char2 = (int **)malloc(sizeof(int*) * (len2 + 1));

    //为数组的二维申请一块横向内存空间

    for( i = 0; i < len1 + 1; i++){
        char1[i] = (int *)malloc(sizeof(int) * (len2 + 1));
        char2[i] = (int *)malloc(sizeof(int) * (len2 + 1));
    }

    //初始化数组为0

    for( i = 0; i < len1 + 1; i++)
    {
        for( j = 0; j < len2 + 1; j++)
        {
            char1[i][j] = 0;
            char2[i][j] = 0;
        }
    }

    //计算LCS的长度

    int k;
    for( k = 0; k < 10; k++)
        printf("calculating...........\n", k);
    lenth = Lcs_len(str1, str2, char1, char2);
    printf("The longest common string length is:  %d\n", lenth);
    printf("\n");
    //输出LCS
    printf("The longest common string is: ");
    Print_Lcs(str1, char2, len1, len2);
    printf("\n");

    //释放内存
    for(i = 0; i < len1 + 1;i++)
    {
        free(char1[i]);
        free(char2[i]);
    }
    free(char1);
    free(char2);

}

