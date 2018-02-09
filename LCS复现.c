
/***���븴�������***/

/**�����������**/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#ifndef size_c
#define size_c 200
#endif // size_c

//���ﶨ����������������ʾ�滮��
//int char1[], char2[]

#define EQUAL 0
#define UP 1
#define LEFT 2 //����·����ʶ

/**����LCS_LEN������������Դ�ַ�����ָ�룬�Լ�������װ����
��������:
1. ʵ���㷨��Ҫ���ܣ���״̬ת������㣬�����س���
2. ������ֵ����char1��·��ֵ����char2**/
int Lcs_len(char *str1, char *str2, int **char1, int **char2);

/**����print��������һ��Դ�ַ������Լ�·������
/i��jΪ��װ������ı߽糤��(m,n
���ܣ���ӡ������·���������ַ�����*/
void Print_Lcs(char *str1, int **char2, int i, int j);

/**����FIND����STDIN¼���ַ�����������������ǰ��������*/
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
    //��ʼ���߽�����
    int m = strlen(str1);
    int n = strlen(str2);

    int i, j, lenth;

    for(i = 0; i <= m; i++)
    {

        char1[i][0] = 0;
    }

    for(j = 0; j <= n; j++) //��ʼ���߽�����
    {
        char1[0][j] = 0;
    }

    //�����0��ʼ����i-1�ĳ�ʼת�ƽ�Ϊ����(<0)
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
    //����·����ӡ������������

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
    //�����ά����
    int i, j, lenth;


    //Ϊ�����һά����һ�������ڴ�ռ�

    int **char1 = (int **)malloc(sizeof(int*) * (len1 + 1));
    int **char2 = (int **)malloc(sizeof(int*) * (len2 + 1));

    //Ϊ����Ķ�ά����һ������ڴ�ռ�

    for( i = 0; i < len1 + 1; i++){
        char1[i] = (int *)malloc(sizeof(int) * (len2 + 1));
        char2[i] = (int *)malloc(sizeof(int) * (len2 + 1));
    }

    //��ʼ������Ϊ0

    for( i = 0; i < len1 + 1; i++)
    {
        for( j = 0; j < len2 + 1; j++)
        {
            char1[i][j] = 0;
            char2[i][j] = 0;
        }
    }

    //����LCS�ĳ���

    int k;
    for( k = 0; k < 10; k++)
        printf("calculating...........\n", k);
    lenth = Lcs_len(str1, str2, char1, char2);
    printf("The longest common string length is:  %d\n", lenth);
    printf("\n");
    //���LCS
    printf("The longest common string is: ");
    Print_Lcs(str1, char2, len1, len2);
    printf("\n");

    //�ͷ��ڴ�
    for(i = 0; i < len1 + 1;i++)
    {
        free(char1[i]);
        free(char2[i]);
    }
    free(char1);
    free(char2);

}

