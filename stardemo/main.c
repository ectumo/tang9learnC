#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j; //�����б���i,�б���j;
    //���ѭ����������,����
    for (i = 0; i < 4; i++)// ����num1 ��
    {
        //�ڲ�ѭ����������,���еķ���
        //��ӡ�����ϰ벿��
        for (j = 0; j <= 2 - i; j++)//����num2 ��
        {
            printf("%c", ' ');
        }

        for (j = 0; j <= i * 2; j++)
        {
             if (j == 0 || j == i * 2)
             {
                 printf("%c", '*');
             }
             else
             {
                 printf("%c", ' ');
             }

        }

        printf("\n");//����
    }

    for (i = 0; i < 3; i++)
    {
        //��ӡ�����°벿��
        for (j = 0; j <= i; j++)
        {
            printf("%c", ' ');
        }

        for (j = 0; j <= 4 - i * 2; j++)
        {
            if (j == 0 || j == 4 - i * 2)
            {
                printf("%c", '*');
            }
            else
            {
                printf("%c", ' ');
            }
        }

        printf("\n");
    }
}
