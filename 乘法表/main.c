#include <stdio.h>
#include <stdlib.h>

int main()
{
   int input_num;
   int i, j;
   printf("������һ��1-9�����֣�");
   scanf("%d", &input_num);
   printf("%d�ĳ˷���Ϊ��\n",input_num);
        for (i = 1; i <= input_num && i <= 9; i++)
        {


                for (j = 1; j <= i; j++)
                {
                printf("%d * %d = %d", j, i, i * j);
                    if (j == i)
                    {
                        printf("\n");
                    }
                    else
                    {
                        printf("\t");
                    }

                }
        }
        if (input_num > 9)
        {
            printf("���������������%d����9��֮�������ֻ��ʾ������йصĳ˷���ʽ��\n", input_num);
            //�����������5��
            /*for (i = 1; i <= input_num; i++)
            {
                printf("%d * %d = %d", input_num, i, i * input_num);
                if (i % 5 == 0)
                {
                    printf("\n");
                }
                else
                {
                    printf("\t\t");
                }
            }*/
            //�����������5��
            int row;//������
            if (input_num % 5 == 0)
            {
            row = input_num / 5;
            }
            else
            {
            row = input_num / 5 + 1;
            }
            for (i = 1 ; i <= row; i++)//ѭ������Ϊ�У���ָ���н�����
            {
                for (j = 0; j < 5 && (i + j * row) <= input_num; j++)//ѭ������Ϊ�У���5�н���ѭ����
                {
                    printf("%d * %d = %d\t\t", input_num, i + j * row, (i + j * row) * input_num);

                }
                printf("\n");
            }
        }

}
