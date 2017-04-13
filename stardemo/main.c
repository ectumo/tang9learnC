#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j; //定义行变量i,列变量j;
    //外层循环控制行数,换行
    for (i = 0; i < 4; i++)// 行数num1 行
    {
        //内层循环控制列数,和列的符号
        //打印菱形上半部分
        for (j = 0; j <= 2 - i; j++)//列数num2 列
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

        printf("\n");//换行
    }

    for (i = 0; i < 3; i++)
    {
        //打印菱形下半部分
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
