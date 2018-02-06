
/***�����������***/
/*��̬�滮*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#ifndef size_c
#define size_c 200
#endif // Ԥ�����ַ����ĳ���

#define EQUAL   1   //EQUAL��ʾc[i][j]����c[i-1][j-1]+1����=��ʱ������������ͬ���ַ�
#define UP      2   //UP��ʾc[i][j]����c[i-1][j]����========��ʱ��������û����ͬ���ַ�
#define LEFT    3   //LEFT��ʾc[i][j]����[ci][j-1]����======��ʱ��������û����ͬ���ַ�

//int char1[size_c][size_c];  //����������ά�������ַ���
//int char2[size_c][size_c];  //1���λ�ã�2���·��

int max(int m, int n, int i, int j);
int print(int i, int j);

/***����һ���ж�LCS����***/
int Lcs_len(char *str1, char *str2, int **char1, int **char2)
{
    //int char1[size_c][size_c] = {0};
    //int char2[size_c][size_c] = {0};

    int m = strlen(str1);
    int n = strlen(str2);  //�����������ı߽糤��

    int i, j;
    for (i = 0; i <=  m; i++)
    {
        char1[i][0] = 0;
    }

    for (j = 0; j <=  n; j++)  //��ʼ���߽�����
    {
        char1[0][j] = 0;
    }

    for ( i = 1; i <= m; i++)
    {
        for ( j = 1; j <= n; j++)
        {
            if( str1[i-1] == str2[j-1] )
    // ����ʹ��i-1�Լ�j-1������������±��0��ʼ
    //��һ��ʵ�ַ�ʽ������ʵ�֣�����·����ȷ��������
            {
                char1[i][j] = char1[i-1][j-1] + 1;
                char2[i][j] = EQUAL;
            }
            else if (char1[i-1][j] >= char1[i][j-1])//��jѭ��ʱ���ַ�������
                {                                // ��ֻ���ж�char�е�Ԫ��
                char1[i][j] = char1[i-1][j];
                char2[i][j] = UP;
                }
            else
                {
                char1[i][j] = char1[i][j-1];
                char2[i][j] = LEFT;
                }
        }


    }
    return char1[m][n];  //�ݹ������λ�洢�����־���LCS����
}

/***�����������LCS***/

void Print_Lcs( char *str, int **b, int i, int j)
{
    if( i == 0 || j == 0)
        return;    //�ݹ����߽���ɨ�����
    if( b[i][j] == EQUAL)
    {                     //������ȵ�Ԫ�أ���·��Ϊ���Ϸ��Խ��ƶ�
        Print_Lcs(str, b, i - 1, j - 1);
        printf("%c ", str[i-1]);  //��ȵĻ���ԭ�ַ�������ǰ�ݹ�һλ����ӡ���ַ�
    }
    else if ( b[i][j] == UP )  //�����ʱ�жϷ�����������������λ��
        Print_Lcs(str, b, i - 1, j);
    else
        Print_Lcs(str, b, i , j - 1); //���������±�����λ��һλ

}

/***������������LCS����***/
void Find_Lcs( char *str1, char *str2)
{
    int i,j,length;
    int len1 = strlen(str1),
        len2 = strlen(str2);
    //�����ά����
    int **c = (int **)malloc(sizeof(int*) * (len1 + 1));
    int **b = (int **)malloc(sizeof(int*) * (len1 + 1));
    for( i = 0; i<= len1; i++ )  ////����Ⱥ�֮ǰû�ӣ������ڴ�й©
    {
        c[i] = (int *)malloc(sizeof(int) * (len2 + 1));
        b[i] = (int *)malloc(sizeof(int) * (len2 + 1));
    }

    //��c[len1][len2]��b[len1][len2]��ʼ��Ϊ0
    for ( i = 0; i<= len1; i++)
        for( j = 0; j <= len2; j++)
        {
            c[i][j] = 0;
            b[i][j] = 0;
        }

    //����LCS�ĳ���
    length = Lcs_len(str1, str2, c, b);
    printf("The number of the Longest-Common-Subsequence is %d\n", length);

    //��������b����������
    printf("The Longest-Common-Subsequence is: ");
    Print_Lcs(str1, b, len1, len2);
    printf("\n");

    //��̬�ڴ��ͷ�
    for ( i = 0; i <= len1; i++)
    {
        free(c[i]);
        free(b[i]);
    }
    free(c);
    free(b);
}

/***LCS�������***/

int main(int *argv, int *argc[])
{
   /* char x[10] = "abcdefghi";
    char y[10] = "bdegihbjk";
    Find_Lcs(x,y);
    */
    char X[size_c],Y[size_c];
    int len;
    printf("please enter your characters:");
    scanf("%s",X);
    while(strlen(X) > 200)
    {
        printf("what you input is too long, please try again");
        scanf("%s\n",X);
    }
    printf("please enter your characters:");
    scanf("%s",Y);
    while(strlen(Y) > 200)
    {
        printf("what you input is too long, please try again");
        scanf("%s",Y);
    }

    Find_Lcs(X,Y);
    system("pause");
}
