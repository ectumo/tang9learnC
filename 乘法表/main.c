#include <stdio.h>
#include <stdlib.h>

int main()
{
   int input_num;
   int i, j;
   printf("请输入一个1-9的数字：");
   scanf("%d", &input_num);
   printf("%d的乘法表为：\n",input_num);
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
            printf("由于你输入的数字%d超过9，之后的数字只显示与该数有关的乘法公式：\n", input_num);
            //横向递增，排5列
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
            //纵向递增，排5列
            int row;//定义行
            if (input_num % 5 == 0)
            {
            row = input_num / 5;
            }
            else
            {
            row = input_num / 5 + 1;
            }
            for (i = 1 ; i <= row; i++)//循环条件为行，到指定行结束。
            {
                for (j = 0; j < 5 && (i + j * row) <= input_num; j++)//循环条件为列，到5列结束循环。
                {
                    printf("%d * %d = %d\t\t", input_num, i + j * row, (i + j * row) * input_num);

                }
                printf("\n");
            }
        }

}
