#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <ctype.h>

typedef char  Pre_;         //���������ֻ���ʱ��������

bool Judge_char(const char *p); //����һ�������ͱ����ĺ���ԭ��

int main(int argc, char *argv[])
{

    printf("Please enter the chars to judge:\n");

    bool re_value = 0;  //��ʼ���߼�����
    char *k;
    scanf("%s", k);   //����һ���ַ���ָ�룬����STDIN����

    re_value = Judge_char(k);

    if (re_value){
        printf("This charset is Palindrom");
    }
    else {
        printf("this charset is not Palindrom");     //�ж�������ٲ�������
    }
    return 0;
}

bool Judge_char(const char *p)
{
    register int i = 0;      //����������ʼ��
    int len = strlen(p); //ʹ��STRLEN����ȡ�ַ���������ַ�λ��

    //ע��˴�STRLEN��SIZEOF��ʹ�÷������𣬺��߷��ز�������ռ�ռ��С���������ַ�'\0'��С
    //��STRLENԭ���д���Ĳ�����constָ�������*p����

    for (i = 0; i <= len/2; i++)
    {
        if (p[i] == p[len - 1])
        {
            len--; //����β�����ַ���ֵ���ֱ����ַ��������ƶ�һλ�����ж�
        }
        else
        return false;
    }

    return true;
}
