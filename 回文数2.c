/***�жϻ�����***/

//���2.�ж����ֻ���
//�������ֵ���ֵ�������л����ж�


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//�˷�������ֱ��Ƕ��main�����У�����Ҫ�������⺯��
int main(int argc, char *argv[])
{

    printf("Please enter the number to judge:\n");

    int Inp;   //��INP��Ϊһ�������ʼ���������ͣ�����ѭ������ж�
    scanf("%d", &Inp);      //��STDIN��ʽ������INP�У��ٸ�����a=1234

    int sum  = 0;
    int Calcul;
    Calcul = Inp;   //������һ��CALCUL����������ʼֵ������������ѭ���н��������жϲ������ı�

    while(Calcul != false)
    {
        sum = sum * 10 + Calcul % 10;//��һ�ε�ʽΪsum=0*10+1234%10(��ʵֵ����4)=4��
                    //�ڶ��ε�ʽΪsum=4*10+123%10(��ʵֵΪ3)=43�������ε�ʽΪsum=43*10+12%10
                   //(��ʵֵΪ2)=432,���Ĵ�sum=432*10+1%10(��ʵΪ1)=4321
        Calcul /= 10;
//��һ�ε�ʽΪCalcul=1234/10=123�ڶ���Calcul=123/10=12������Calcul=12/10=1,���Ĵ�Calcul=1/10=0;
    }

    if (sum == Inp)
    {
        printf("this is a palindrome");
    }

    else{printf("this is not a palindrome");
    }

    return 0;
}
